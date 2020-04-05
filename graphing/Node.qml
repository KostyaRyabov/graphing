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
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton

            cursorShape: Qt.OpenHandCursor
            onPressed: {   cursorShape = Qt.CloseHandCursor}
            onReleased: { cursorShape = Qt.OpenHandCursor}
            onPositionChanged: {
                node.x += mouseX-nodeRadius
                node.y += mouseY-nodeRadius
            }

            MyMenu {
                id: contextMenu
                Action { text: "copy"; onTriggered: arrow_model.display() }
                Action { text: "remove"; onTriggered: destroyObj.start() }
            }
        }

        Rectangle{
            id: control

            property int counter: 0

            width: view.width
            height: view.height
            radius: width*0.5

            scale: 3

            opacity: 0
            color: "#7777FF"
            border.color: "#2222FF"
            border.width: 1

            x: rx;
            y: ry;

            onXChanged: node_model.update(node.index,control.x,259)
            onYChanged: node_model.update(node.index,control.y,260)

            MouseArea{
                anchors.fill: parent
                acceptedButtons: Qt.RightButton

                cursorShape: Qt.OpenHandCursor

                MouseArea{
                    anchors.fill: parent
                    acceptedButtons: "NoButton"

                    hoverEnabled: true
                    onEntered: selected.start();

                    onExited: { unselected.start();}
                }

                onPressed: {
                    timer.start();
                    cursorShape = Qt.ArrowCursor;
                    arrow_model.bindA(node.index)
                }

                onPositionChanged: {
                    control.x += mouse.x-nodeRadius
                    control.y += mouse.y-nodeRadius
                }

                onReleased: {
                    cursorShape = Qt.OpenHandCursor;
                    if (Math.abs(Math.sqrt(Math.pow(node.rx,2)+Math.pow(node.rx,2)))>2*nodeRadius){
                        node_model.addNode(node.xc+node.rx,node.yc+node.ry);
                        arrow_model.bindB(node.index+1)
                    }
                }

                onClicked: {
                    if (mouse.button === Qt.RightButton)
                        if (control < 1){
                            timer.stop();
                            contextMenu.popup()
                        }
                }
            }
        }

        Timer {
            id: timer
            onTriggered: control.counter++;
            interval: 200
            repeat: true
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

        PropertyAnimation {
            id: selected
            target: control
            properties: "opacity"
            easing.type: Easing.OutBack
            to: 0.2
            duration: 300
        }
        PropertyAnimation {
            id: unselected
            target: control
            properties: "opacity"
            easing.type: Easing.InBack
            to: 0
            duration: 300

            onStopped: {
                control.x = 0;
                control.y = 0;
            }
        }
    }
}
