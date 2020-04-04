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
            Action { text: "paste"; }
        }
    }

    Repeater {
        anchors.fill: parent
        model: manager
        delegate: Node {
            xc: node_x;
            yc: node_y;
            index: node_id
        }
    }
}
