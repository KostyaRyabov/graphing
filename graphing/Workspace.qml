import QtQuick 2.0
import QtQuick.Controls 2.14

Rectangle{
    id : space

    width: 512
    height: 512
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
        onPressAndHold: {
            if (mouse.source === Qt.MouseEventNotSynthesized)
                contextMenu.popup()
        }

        Menu {
            id: contextMenu
            MenuItem { text: "add new Node" }
            MenuItem { text: "paste" }
        }
    }
}
