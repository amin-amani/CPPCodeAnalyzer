import QtQuick 2.5
import QtQuick.Window 2.2
import "code.js" as MyScript


Rectangle {
    function setText(text)
    {

appWindow.children[0].name=text;
        console.log(appWindow.children[0].id);

    }
    function setx(x)
    {

appWindow.children[0].x=x;
        console.log(x);

    }

id:appWindow
anchors.fill: parent
    visible: true
    Component.onCompleted:
    {

        MyScript.createSpriteObjects();
    //setText("hj");
    }
}
