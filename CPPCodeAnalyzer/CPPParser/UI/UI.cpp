#include "UI.h"


// =========================================================================
UI::UI(QObject *parent) : QObject(parent)
{

}
// =========================================================================
void UI::Init()
{
//    if(!QFile(QCoreApplication::applicationDirPath() + "/systemHistory.ini").exists())
//    {
//        qDebug() << "History file doesn't exist....Creating file...";
//     //   saveSystemHistory(0, 0, 0); // up-time, object, valve
//    }
//    else {
//        qDebug() << "History file exists......";
//        //readSystemHistory();
//    }
//    qDebug()<<"INIT START";
    View->showFullScreen();
    connect(View->engine(), SIGNAL(quit()), this, SLOT(closeApp()));
}
// =========================================================================
void UI::WaitMs(int ms)
{
    QEventLoop q;
    QTimer tT;
    tT.setSingleShot(true);
    connect(&tT, SIGNAL(timeout()), &q, SLOT(quit()));
    tT.start(ms);
    q.exec();
    if(tT.isActive()){
        tT.stop();
    } else {

    }
}
// =========================================================================
void UI::closeApp()
{

}

// =========================================================================
void UI::AddChute(int id)
{
    QMetaObject::invokeMethod((QObject*)RootObject, "newDeviceJoined",
                              Q_ARG(QVariant,QString::number(id))
                              );
}
// =========================================================================
