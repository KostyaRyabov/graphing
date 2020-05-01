import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.4

ApplicationWindow {
    id: window

    visible: true
    width: 640
    height: 640
    title: "graph editor"
    color: "lightgray"

    MouseArea {
        id: area
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        propagateComposedEvents: true

        onPressed: {
            if (mouse.button & Qt.RightButton){
                workspace.lastX = mouseX - workspace.x
                workspace.lastY = mouseY - workspace.y
            } else if (mouse.button & Qt.LeftButton){
                selector.x = mouseX
                selector.y = mouseY
            }
        }
        onPositionChanged: {
            if (area.pressedButtons & Qt.RightButton){
                workspace.x = mouseX - workspace.lastX
                workspace.y = mouseY - workspace.lastY
            } else if (area.pressedButtons & Qt.LeftButton){
                selector.dX = mouseX - selector.x
                selector.dY = mouseY - selector.y
            }
        }

        onReleased: {
            node_model.selectNodesOnRect(selector.x,selector.y,selector.x+selector.dX,selector.y+selector.dY,workspace.x,workspace.y,scaleRect.xScale)
            arrow_model.changeFocus(-1);
            selector.dX = 0;
            selector.dY = 0;
        }

        property double ratio: 0.95;
        onWheel: {
            var origin = mapToItem(workspace, wheel.x, wheel.y)

            if(wheel.angleDelta.y > 0 && scaleRect.xScale < 4) scale = 1/ratio
            else if (scaleRect.xScale > 0.5) scale = ratio
            else scale = 1;


            var realX = origin.x * scaleRect.xScale
            var realY = origin.y * scaleRect.yScale
            workspace.x += (1-scale)*realX
            workspace.y += (1-scale)*realY
            scaleRect.xScale *= scale
            scaleRect.yScale *= scale

            msgBox.message = scaleRect.xScale.toFixed(2) + "%";
            msgBox.show();
        }
    }

    Workspace{
        id:workspace;
        objectName: "workspace"

        x: (parent.width-workspace.width)/2
        y: (parent.height-workspace.height)/2

        property int lastX: 0
        property int lastY: 0

        transform: Scale { id: scaleRect }
    }

    RectSelector {id:selector }

    Connections {
        target: manager
        onDebug: {
            msgBox.message = text;
            msgBox.show();
        }
    }

    PopupMessage { id:msgBox; }

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem { text: "Clear..."; onTriggered: manager.clear() }
            MenuItem { text: "Open..."; onTriggered: manager.openFile() }
            MenuItem { id:save; text: "Save"; onTriggered: manager.saveFile(); enabled: false; }
            MenuItem { text: "Save As..."; onTriggered: save.enabled = manager.saveAsFile(); }
            MenuSeparator { }
            MenuItem { text: "Quit"; onTriggered: close() }
            MenuItem { text: "last"; onTriggered: if (node_model.rowCount() > 0) node_model.update(0,50,257) }
        }
        Menu {
            title: "Help"
            MenuItem { text: "About" }
        }
    }
}
