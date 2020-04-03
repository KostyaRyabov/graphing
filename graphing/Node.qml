import QtQuick 2.0

Rectangle {
    id: node
    property string text: ""

    width: 32
    height: width
    color: "lightgray"
    border.color: "black"
    border.width: 1
    radius: width*0.5
    Text {
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        text: node.text
    }
}
