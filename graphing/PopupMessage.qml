import QtQuick 2.0

Rectangle {
    property string value: ""
    function show(){
        if (animateZoomBoxOpacity.running) animateZoomBoxOpacity.stop()
        animateZoomBoxOpacity.start()
    }

    anchors.left: parent.left
    anchors.bottom: parent.bottom

    anchors.leftMargin: 16
    anchors.bottomMargin: 16

    radius: 5

    height: 50
    width: value.length * 18

    color: "#95a7ad"
    opacity: 0

    Text {
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#2c3238"
        font.pixelSize: 24
        text: value
    }

    PropertyAnimation {
        id: animateZoomBoxOpacity;
        target: zoomBox;
        properties: "opacity";
        from: 0.8
        to: 0;
        easing.type: Easing.InOutQuint;
        duration: 1500
    }
}
