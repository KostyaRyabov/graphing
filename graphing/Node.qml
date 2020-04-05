import QtQuick 2.0
import QtQuick.Controls 2.14

Item {
    id: node
    property int index: -1
    property int stored_index: -1

    property int xc: 0
    property int yc: 0

    property int rx: 0
    property int ry: 0

    x: xc
    y: yc

    onXChanged: node_model.update(node.index,node.x,257)
    onYChanged: node_model.update(node.index,node.y,258)

    onIndexChanged: textHide.start();

    Rectangle {
        id: view

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

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
            opacity: 0
            id:textBox
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            text: node.stored_index
        }

        MouseArea {
            id: dragArea
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton

            cursorShape: Qt.OpenHandCursor
            onPressed: { dragArea.cursorShape = Qt.CloseHandCursor}
            onReleased: {dragArea.cursorShape = Qt.OpenHandCursor}
            onPositionChanged: {
                node.x += mouseX
                node.y += mouseY
            }

            MyMenu {
                id: contextMenu
                Action { text: "copy"; onTriggered: arrow_model.display() }
                Action { text: "remove"; onTriggered: destroyObj.start() }
            }
        }

        Rectangle{
            id: control

            width: view.width
            height: view.height
            radius: width*0.5

            opacity: 0.3
            color: "blue"

            x: rx;
            y: ry;

            onXChanged: node_model.update(node.index,control.x,259)
            onYChanged: node_model.update(node.index,control.y,260)

            MouseArea{
                id: appendArea

                anchors.fill: parent
                acceptedButtons: Qt.RightButton

                cursorShape: Qt.OpenHandCursor

                onPressed: {
                    appendArea.cursorShape = Qt.ArrowCursor;
                    arrow_model.bind(node.index)
                }
                onPositionChanged: {
                    control.x += mouseX
                    control.y += mouseY
                }

                onReleased: {appendArea.cursorShape = Qt.OpenHandCursor}

                onClicked: {
                    if (mouse.button === Qt.RightButton)
                        contextMenu.popup()
                }
            }
        }

        PropertyAnimation {
            id: destroyObj
            target: node
            properties: "scale"
            from: 1
            to: 0
            easing.type: Easing.InBack
            duration: 500

            onStopped: manager.removeNode(node.index);
        }

        PropertyAnimation {
            id: textHide
            target: textBox
            properties: "opacity"
            to: 0
            easing.type: Easing.InOutQuart
            duration: 300

            onStopped: {
                node.stored_index = node.index;
                textShow.start();
            }

        }
        PropertyAnimation {
            id: textShow
            target: textBox
            properties: "opacity"
            to: 1
            easing.type: Easing.OutInQuart
            duration: 300
        }
    }
}
