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

    MouseArea {
        anchors.fill: parent

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

    Workspace{
        id:workspace;
        objectName: "workspace"


        transform: Scale { id: scaleRect }
    }

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
            Action { text: "Quit"; onTriggered: close() }
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