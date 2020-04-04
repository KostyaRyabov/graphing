import QtQuick 2.0
import QtQuick.Controls 2.14

Rectangle {
    id: node

    property int index: 0
    property int xc: 0
    property int yc: 0



    x: xc-nodeRadius
    y: yc-nodeRadius

    width: nodeRadius*2
    height: width
    color: "lightgray"
    border.color: "black"
    border.width: 1
    radius: width*0.5

    NumberAnimation on scale {
        from: 0
        to: 1
        easing.type: Easing.OutBack
        duration: 400
    }

    Text {
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        text: node.identifier
    }

    Drag.active: dragArea.drag.active
    Drag.hotSpot.x : nodeRadius
    Drag.hotSpot.y : nodeRadius

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
            Action { text: "copy"; }
            Action { text: "remove"; onTriggered: { manager.removeNode(node.identifier); } }
        }
    }


}
