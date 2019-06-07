import QtQuick 2.0


Rectangle {
    property string name: "empty"
    id: "nsew"
width: 80;
height: 120;
color: "red"
Drag.active: dragArea.drag.active
Text {


    anchors.horizontalCenter:  parent.horizontalCenter
    text: name
}
       //Drag.hotSpot.x: 10
       ///Drag.hotSpot.y: 10
MouseArea
{
    id:dragArea
anchors.fill: parent;
drag.target: parent
onClicked: cppgui.printText( name);
}


}
