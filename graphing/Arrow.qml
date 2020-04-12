import QtQuick 2.4
import QtQuick.Controls 2.14

Item {
    id:arrow

    property int aIndex: -1;

    property int xxx: 0;
    property int yyy: 0;

    property int len: 0;

    property double alpha: 0
    property bool bDir: false

    property bool detonate: false;

    onLenChanged: {
        if (len >= 0){
            canvas.height = len*2
            canvas.width = nodeRadius*2
        }else{
            canvas.height = 4*nodeRadius
            canvas.width = canvas.height
        }
    }

    onDetonateChanged: if (detonate) detonator.start();

    x: xxx
    y: yyy

    NumberAnimation on opacity {
        from: 0
        to: 1
        easing.type: Easing.InOutQuad
        duration: delayCD
    }

    transform: Rotation { angle: alpha }

    onBDirChanged: {
        canvas.redraw();
    }

    Canvas {
        id: canvas

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        scale: 0.5

        antialiasing: true

        onPaint: {
            var context = canvas.getContext('2d')

            if (len >= 0){
                context.beginPath();
                context.strokeStyle = "black"
                context.lineWidth = nodeRadius/4;
                context.moveTo(nodeRadius, width);
                context.lineTo(nodeRadius, height-width);
                context.stroke();

                if (bDir){
                    context.beginPath();
                    context.fillStyle = "black"
                    context.moveTo(nodeRadius, width);
                    context.lineTo(0, 2*width);
                    context.lineTo(width, 2*width);
                    context.lineTo(nodeRadius, width);
                    context.fill();
                }

                context.beginPath();
                context.fillStyle = "black"
                context.moveTo(nodeRadius, height-width);
                context.lineTo(0, height-2*width);
                context.lineTo(width, height-2*width);
                context.lineTo(nodeRadius, height-width);
                context.fill();
            }else{
                context.beginPath();
                context.fillStyle = "black"
                context.moveTo(width/2, 0);
                context.lineTo(width*0.8, width*0.05);
                context.lineTo(width*0.55, width*0.3);
                context.fill();

                context.beginPath();
                context.strokeStyle = "black"
                context.lineWidth = width/20;
                context.arc(width*0.42, width*0.42, width*0.35, 1.7*Math.PI, 1.1*Math.PI, false);
                context.stroke();
            }
        }

        function redraw(){
            var context = canvas.getContext('2d')
            context.reset();
            canvas.requestPaint();
        }

        Rectangle{
            id: control;
            anchors.fill: parent
            anchors.margins: -nodeRadius

            opacity: 0
            color: "#7777FF"
            border.color: "#2222FF"
            border.width: 1

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true;
                acceptedButtons: Qt.LeftButton | Qt.RightButton

                onEntered: selected.start();
                onExited: unselected.start();

                onClicked: {
                    if (mouse.button === Qt.RightButton){
                        contextMenu.popup()
                    }
                }
            }
        }
    }

    Text {
        anchors.fill: parent
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 4
        text: arrow.aIndex
    }

    PropertyAnimation {
        id: detonator
        target: arrow
        properties: "opacity"
        from: 1
        to: 0
        easing.type: Easing.OutQuad
        duration: delayCD

        onStopped: arrow_model.kill()
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

    MyMenu {
        id: contextMenu
        Action { text: "copy"; }
        Action { text: "remove"; onTriggered: { manager.removeArrow(aIndex); arrow_model.remove(aIndex,true) }}
    }
}
