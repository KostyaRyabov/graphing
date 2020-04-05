import QtQuick 2.4

Item {
    id:arrow

    property int xxx: 0;
    property int yyy: 0;

    property int len: 0;

    property double alpha: 0
    property bool bDir: false

    x: xxx
    y: yyy

    transform: Rotation { angle: alpha }

    onBDirChanged: {
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

            context.beginPath();
            context.fillStyle = "black"
            context.moveTo(width/2, nodeRadius);
            context.lineTo(0, 2*nodeRadius);
            context.lineTo(width, 2*nodeRadius);
            context.lineTo(width/2, nodeRadius);
            context.fill();

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
            context.restart();
        }
    }
}
