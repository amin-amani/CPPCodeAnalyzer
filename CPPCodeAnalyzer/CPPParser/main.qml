import QtQuick 2.12
import QtQuick.Window 2.12


Rectangle {

    visible: true
    width: 640
    height: 480
    color: "gray"
        id:mainPage


    Rectangle
    {
        id:r1
        width: 100
        height: 100
        x:10
        y:10
        color: "red"
        //        border.color: "white"
        MouseArea
        {
            anchors.fill: parent
            onClicked: parent.border.color="black"
            drag.target: parent
            drag.axis: Drag.XAndYAxis
            drag.minimumX: 0
            drag.maximumX:  mainPage.width
        }
    }

    Rectangle
    {
        id:r2
        width: 100
        height: 100
        x:200
        y:200
        color: "green"
        border.color: "white"
        MouseArea
        {
            anchors.fill: parent
            onClicked: parent.border.color="black"
            drag.target: parent
            drag.axis: Drag.XAndYAxis
            drag.minimumX: 0
            drag.maximumX:  mainPage.width
            onPositionChanged:
            {
                //         console.log(Math.atan2(r2.y, r1.y) * 180 / Math.PI)
            }
        }
    }

    Rectangle
    {
        id:r3
        width: 100
        height: 100
        x:200
        y:200
        color: "green"
        border.color: "white"
        MouseArea
        {
            anchors.fill: parent
            onClicked: parent.border.color="black"
            drag.target: parent
            drag.axis: Drag.XAndYAxis
            drag.minimumX: 0
            drag.maximumX:  mainPage.width
            onPositionChanged:
            {
                //         console.log(Math.atan2(r2.y, r1.y) * 180 / Math.PI)
            }
        }
    }


    Line{
        id:line1
        xStart:r1.x
        yStart:r1.y
        xEnd: p1.x
        yEnd: p1.y
        color: "white"
    }

    Point{
        id:p1
        x:40
        y:40
    }

    Line{
        id:line2
        xStart:p1.x
        yStart:p1.y
        xEnd: r3.x
        yEnd: r3.y
        color: "white"

    }

}
