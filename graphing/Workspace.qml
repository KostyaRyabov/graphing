import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{
    id : space

    width: wsWidth
    height: wsHeight

    property bool activated: false

    MouseArea {
        id: dragArea
        anchors.fill: parent
        acceptedButtons: Qt.RightButton

        propagateComposedEvents: true

        cursorShape: Qt.PointingHandCursor

        onPressed: {
            space.activated = false;
            timer.start();
            cursorShape = Qt.CloseHandCursor
            mouse.accepted = false
        }

        onReleased: {
            cursorShape = Qt.PointingHandCursor
            mouse.accepted = false
        }

        onClicked: {
            if (mouse.button === Qt.RightButton)
                if (!space.activated)
                    contextMenu.popup()

            mouse.accepted = false
        }

        Menu {
            id: contextMenu
            MenuItem { text: "new Node"; onTriggered: node_model.addNode(dragArea.mouseX, dragArea.mouseY)}
            MenuItem { text: "paste"; onTriggered: manager.paste(dragArea.mouseX, dragArea.mouseY)}
        }
    }

    Timer {
        id: timer
        interval: 200
        repeat: true
        onTriggered: {space.activated = true;timer.stop()}
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
            aDetonate: Delete;
            aIndex: arrow_id;
            isMoving: selected;
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
            nIndex: node_id;
            isSelected: selected;
            nDetonate: Delete;
        }
    }
}
