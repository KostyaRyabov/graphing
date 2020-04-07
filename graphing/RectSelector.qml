import QtQuick 2.0

Item {
    id: selector

    property int dX: 0
    property int dY: 0

    Rectangle{
        id: view

        opacity: 0.15
        color: "blue"

        height: Math.abs(selector.dY)
        width: Math.abs(selector.dX)

        x: (selector.dX < 0)?dX:0
        y: (selector.dY < 0)?dY:0
    }
}
