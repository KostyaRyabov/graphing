import QtQuick 2.4

Item {
    id:arrow
    height: 100
    width: nodeRadius

    property bool bidirectional: false

    onBidirectionalChanged: {
        canvas.clear();
        canvas.draw();
    }

    Canvas {
        id: canvas

        anchors.centerIn: parent

        height: parent.height / 2
        width: parent.width

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
