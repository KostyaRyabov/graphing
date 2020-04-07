import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    id: window

    visible: true
    width: 640
    height: 640
    title: "graph editor"
    color: "lightgray"

    Workspace{
        id:workspace;
        objectName: "workspace"

        x: (parent.width-workspace.width)/2
        y: (parent.height-workspace.height)/2

        property int lastX: 0
        property int lastY: 0

        transform: Scale { id: scaleRect }
    }


    MouseArea {
        id: area
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

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

            zoomBox.show();
        }
    }
    RectSelector {id:selector }


    PopupMessage { id:zoomBox; value: (scaleRect.xScale).toFixed(2) + "%" }

    menuBar: MenuBar {
        implicitHeight: 20

        MyMenu {
            title: "File"
            Action { text: "New..."; onTriggered: manager.newFile() }
            Action { text: "Open..."; onTriggered: manager.openFile() }
            Action { text: "Save"; onTriggered: manager.saveFile() }
            Action { text: "Save As..."; onTriggered: manager.saveAsFile(); enabled: manager.filePathExists() }
            MenuSeparator { }
            //Action { text: "Quit"; onTriggered: close() }
            Action { text: "showAll"; onTriggered: {
                    node_model.showNodeList()
                    arrow_model.showArrowList()
                    arrow_model.showMap()
                    manager.showMatrix()
                }
            }
        }
        MyMenu {
            implicitHeight: 20

            title: "Help"
            Action { text: "About" }
        }

        delegate: MenuBarItem {
            id: menuBarItem
            implicitHeight: 20

            contentItem: Text {
                text: menuBarItem.text
                font: menuBarItem.font
                color: "#2c374a"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            background: Rectangle {
                color: menuBarItem.highlighted ? "#b9bfc9" : "transparent"
            }
        }
    }
}
