import QtQuick 2.0
import QtQuick.Controls 2.14

Item {
    id: node
    property int nIndex: -1
    property int stored_index: -1

    property bool isSelected: false

    onIsSelectedChanged: {
        if (isSelected) selected.start();
        else unselected.start();
    }

    property int xc: 0
    property int yc: 0

    property int rx: 0
    property int ry: 0

    Binding on x { when: onXcChanged; value: xc }
    Binding on y { when: onYcChanged; value: yc }

    onNIndexChanged: textHide.start();

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

        Component.onCompleted: creation.start();

        NumberAnimation {
            id:creation;
            target:view;
            properties: "scale,opacity"
            from: 0
            to: 1
            easing.type: Easing.OutBack
            duration: delayCD
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
            onReleased: {
                cursorShape = Qt.OpenHandCursor
                node_model.checkNodeCollision(node.nIndex);
            }
            onPositionChanged: {
                node.x += mouseX-nodeRadius
                node.y += mouseY-nodeRadius

                node_model.update(node.nIndex,node.x,257)
                node_model.update(node.nIndex,node.y,258)
            }

            MyMenu {
                id: contextMenu
                Action { text: "copy"; }
                Action { text: "remove"; onTriggered: detonator.start() }
                MenuSeparator { }
                Action { text: "create loop"; onTriggered: arrow_model.createLoop(node.nIndex); }
            }
        }

        Rectangle{
            id: control

            property int counter: 0

            width: view.width
            height: view.height
            radius: width*0.5

            scale: SelectorRadius/view.width

            opacity: 0
            color: "#7777FF"
            border.color: "#2222FF"
            border.width: 1

            x: rx;
            y: ry;

            MouseArea{
                anchors.fill: parent
                acceptedButtons: Qt.RightButton

                cursorShape: Qt.OpenHandCursor

                MouseArea{
                    anchors.fill: parent
                    acceptedButtons: Qt.NoButton

                    hoverEnabled: true;
                    onEntered: if (!isSelected) node_model.selectNode(nIndex,false);
                    onExited: unselected.start();
                }

                onPressed: {
                    control.counter = 0;
                    timer.start();
                    cursorShape = Qt.ArrowCursor;
                    arrow_model.bindA(node.nIndex);
                }

                onPositionChanged: {
                    control.x += mouse.x-nodeRadius
                    control.y += mouse.y-nodeRadius

                    node_model.update(node.nIndex,control.x,259)
                    node_model.update(node.nIndex,control.y,260)
                }

                onReleased: {
                    cursorShape = Qt.OpenHandCursor;
                    if (Math.abs(Math.sqrt(Math.pow(node.rx,2)+Math.pow(node.ry,2)))>SelectorRadius){
                        arrow_model.bindB(node.nIndex)
                    } else {
                        arrow_model.removeCurrent();
                    }

                    if (mouse.button === Qt.RightButton){
                        if (control.counter < 1){
                            contextMenu.popup()
                        }
                    }

                    control.opacity = 0;
                    control.x = 0;
                    control.y = 0;
                    timer.stop();
                }
            }
        }

        Timer {
            id: timer
            onTriggered: control.counter++
            interval: 200
            repeat: true
        }

        PropertyAnimation {
            id: detonator
            target: node
            properties: "scale,opacity"
            from: 1
            to: 0
            easing.type: Easing.InCirc
            duration: delayCD

            onStopped: node_model.removeNode(node.nIndex,true);
        }

        PropertyAnimation {
            id: textHide
            target: textBox
            properties: "opacity"
            to: 0
            easing.type: Easing.InOutQuad
            duration: changeTime

            onStopped: {
                node.stored_index = node.nIndex;
                textShow.start();
            }
        }
        PropertyAnimation {
            id: textShow
            target: textBox
            properties: "opacity"
            to: 1
            easing.type: Easing.OutInQuad
            duration: changeTime
        }

        PropertyAnimation {
            id: selected
            target: control
            properties: "opacity"
            easing.type: Easing.OutBack
            to: 0.2
            duration: changeTime
        }
        PropertyAnimation {
            id: unselected
            target: control
            properties: "opacity"
            easing.type: Easing.InBack
            to: 0
            duration: changeTime

            onStopped: {
                control.x = 0;
                control.y = 0;
            }
        }
    }
}
