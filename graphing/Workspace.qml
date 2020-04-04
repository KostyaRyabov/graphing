import QtQuick 2.0
import QtQuick.Controls 2.14

Rectangle{
    id : space

    width: wsWidth
    height: wsHeight
    x: (parent.width-space.width)/2
    y: (parent.height-space.height)/2

    Drag.active: dragArea.drag.active

    MouseArea {
        id: dragArea
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        drag.target: parent

        cursorShape: Qt.OpenHandCursor
        onPressed: {dragArea.cursorShape = Qt.CloseHandCursor}
        onReleased: {dragArea.cursorShape = Qt.OpenHandCursor}

        onClicked: {
            if (mouse.button === Qt.RightButton)
                contextMenu.popup()
        }

        MyMenu {
            id: contextMenu
            Action { text: "new Node"; onTriggered: manager.addNode(dragArea.mouseX, dragArea.mouseY) }
            Action { text: "paste"; onTriggered: nameModel.remove(0)}
        }
    }


    property ListModel listsss: ListModel {
        id: nameModel
        ListElement { xx: 50; yy: 20 }
        ListElement { xx: 20; yy: 50 }
        ListElement { xx: 70; yy: 110 }
        ListElement { xx: 100; yy: 0 }
        ListElement { xx: 150; yy: 0 }
        ListElement { xx: 250; yy: 0 }
    }

    Component {
        id: nameDelegate
        Node {
            xc: xx;
            yc: yy;
        }
    }

    Repeater {
        anchors.fill: parent
        model: nameModel
        delegate: nameDelegate
    }
}
