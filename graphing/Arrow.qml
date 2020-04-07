import QtQuick 2.4

Item {
    id:arrow

    property int xxx: 0;
    property int yyy: 0;

    property int len: 0;

    property double alpha: 0
    property bool bDir: false

    property bool detonate: false;

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
        console.log("redraw");
        canvas.clear();
        canvas.draw();
    }

    Canvas {
        id: canvas

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        height: len
        width: nodeRadius

        antialiasing: true

        onPaint: draw()

        function draw(){
            var context = canvas.getContext('2d')

            context.beginPath();
            context.strokeStyle = "black"
            context.moveTo(width/2, nodeRadius);
            context.lineTo(width/2, height-nodeRadius);
            context.stroke();

            if (bDir){
                context.beginPath();
                context.fillStyle = "black"
                context.moveTo(width/2, nodeRadius);
                context.lineTo(0, 2*nodeRadius);
                context.lineTo(width, 2*nodeRadius);
                context.lineTo(width/2, nodeRadius);
                context.fill();
            }

            context.beginPath();
            context.fillStyle = "black"
            context.moveTo(width/2, height-nodeRadius);
            context.lineTo(0, height-2*nodeRadius);
            context.lineTo(width, height-2*nodeRadius);
            context.lineTo(width/2, height-nodeRadius);
            context.fill();
        }

        function clear(){
            var context = canvas.getContext('2d')
            context.reset();
            canvas.requestPaint();
        }
    }

    PropertyAnimation {
        id: detonator
        target: arrow
        properties: "opacity"
        from: 1
        to: 0
        easing.type: Easing.InBack
        duration: delayCD

        onStopped: console.log("remove arrow");
    }
}
