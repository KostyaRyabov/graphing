import QtQuick 2.0
import QtQuick.Controls 2.14

Rectangle{
    id : space

    width: wsWidth
    height: wsHeight

    MouseArea {
        id: dragArea
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        cursorShape: Qt.PointingHandCursor
        onPressed: cursorShape = Qt.CloseHandCursor
        onReleased: {cursorShape = Qt.PointingHandCursor}

        onClicked: {
            if (mouse.button === Qt.RightButton)
                contextMenu.popup()
        }

        MyMenu {
            id: contextMenu
            Action { text: "new Node"; onTriggered: node_model.addNode(dragArea.mouseX, dragArea.mouseY) }
            Action { text: "paste"; }
        }
    }



    Repeater {
        id: node_conveier
        anchors.fill: parent
        model: node_model
        delegate: Node {
            xc: PosX;
            yc: PosY;
            rx: RelativePosX;
            ry: RelativePosY;
            index: node_id;
        }
    }



    Repeater {
        anchors.fill: parent
        model: arrow_model
        delegate: Arrow {
            xxx: PosX;
            yyy: PosY;
            len: Length;
            alpha: Angle;
            bDir: bDirection;
            detonate: Delete;
        }
    }
}
