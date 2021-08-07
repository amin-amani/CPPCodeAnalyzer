import QtQuick 2.0

Rectangle
{
    property int xStart : 0
    property int xEnd : 0
    property int yStart : 0
    property int yEnd : 0
    id:point
    x: xStart
    y: yStart
    width: 5
    height: 5
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
