import QtQuick 2.0

Rectangle
{
    property int xStart : 0
    property int xEnd : 0
    property int yStart : 0
    property int yEnd : 0
    id:line
    x: xStart
    y: yStart

    transform: Rotation { origin.x: 0; origin.y: 0; angle: 180-Math.atan2((yEnd-yStart), (xStart-xEnd)) * 180 / Math.PI}
    width: Math.pow( Math.pow(xStart-xEnd,2)+Math.pow(yStart-yEnd,2),0.5)
    height: 2
    color: "black"
    MouseArea
    {
        anchors.fill: parent
        drag.target: parent
        drag.axis: Drag.XAndYAxis
        drag.minimumX: 0
        drag.maximumX:  mainPage.width
    }
}
