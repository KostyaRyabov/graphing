import QtQuick 2.0
import QtQuick.Controls 2.14

Rectangle{
    id : space

    width: wsWidth
    height: wsHeight

    MouseArea {
        id: dragArea
        anchors.fill: parent
        acceptedButtons: Qt.RightButton

        propagateComposedEvents: true

        cursorShape: Qt.PointingHandCursor

        onPressed: {
            cursorShape = Qt.CloseHandCursor
            mouse.accepted = false
        }

        onReleased: {
            cursorShape = Qt.PointingHandCursor
            mouse.accepted = false
        }

        onClicked: {
            if (mouse.button === Qt.RightButton)
                contextMenu.popup()

            mouse.accepted = false
        }

        MyMenu {
            id: contextMenu
            Action { text: "new Node"; onTriggered: {
                    console.log(dragArea.mouseX, dragArea.mouseY,"  ",space.x,space.y)
                    node_model.addNode(dragArea.mouseX, dragArea.mouseY)
                }
            }
            Action { text: "paste"; }
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
}
