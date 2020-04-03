import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4

import MyTools.NodeManager 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 640
    title: "graph editor"
    color: "lightgray"

    MouseArea {
        anchors.fill: parent

        property double factor: 1.05
        onWheel: {
            var zoomFactor

            if(wheel.angleDelta.y > 0 && tform.xScale < 4) zoomFactor = factor
            else if (tform.xScale > 0.5) zoomFactor = 1/factor
            else { zoomBox.show(); return; }

            var realX = wheel.x * tform.xScale
            var realY = wheel.y * tform.yScale
            workspace.x += (1-zoomFactor)*realX
            workspace.y += (1-zoomFactor)*realY
            tform.xScale *= zoomFactor
            tform.yScale *= zoomFactor

            zoomBox.show();
        }

        PopupMessage { id:zoomBox; value: (tform.xScale).toFixed(2) + "%" }
    }

    Workspace{
        id:workspace;
        transform: Scale {id: tform}

        MouseArea{
            anchors.fill: parent
            acceptedButtons: "LeftButton" | "RightButton"

            onClicked: {

            }
        }

        NodeManager{ id:manager }
    }


    menuBar: MenuBar {
        implicitHeight: 20

        Menu {
            title: "File"
            Action { text: "New..."; onTriggered: manager.createFile() }
            Action { text: "Open..."; onTriggered: manager.openFile() }
            Action { text: "Save"; onTriggered: manager.saveFile() }
            Action { text: "Save As..."; onTriggered: manager.saveAsFile()() }
            MenuSeparator { }
            Action { text: "Quit"; onTriggered: close() }

            delegate: MenuItem{
                implicitHeight: 20
            }
        }
        Menu {
            implicitHeight: 20

            title: "Help"
            Action { text: "About" }

            delegate: MenuItem{
                implicitHeight: 20
            }
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
