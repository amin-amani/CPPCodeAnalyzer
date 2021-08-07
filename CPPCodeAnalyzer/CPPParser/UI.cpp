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
// =========================================================================tested
void UI::DisplayProgressBar(bool status, bool visibility)
{
    QMetaObject::invokeMethod((QObject*)RootObject, "displayProgressBar",
                              Q_ARG(QVariant, status),
                              Q_ARG(QVariant, visibility)
                              );
}
// =========================================================================
void UI::closeApp()
{

}
// =========================================================================
void UI::sendSortingType(int chuteID, QList<QString> labels)
{
    emit sendSortingTypeRequest(chuteID, labels);
}
// =========================================================================
void UI::AddChute(int id)
{
    QMetaObject::invokeMethod((QObject*)RootObject, "newDeviceJoined",
                              Q_ARG(QVariant,QString::number(id))
                              );
}
// =========================================================================
void UI::DeleteChute(int id)
{
    QMetaObject::invokeMethod((QObject*)RootObject, "deviceLeft",
                              Q_ARG(QVariant,QString::number(id))
                              );
}
// =========================================================================
void UI::UpdateChart(int64_t totalAccept,int64_t totalEject)
{
    QMetaObject::invokeMethod((QObject*)RootObject, "updateChart",
                              Q_ARG(QVariant, QString::number(totalAccept)),
                              Q_ARG(QVariant, QString::number(totalEject))
                              );
}
// =========================================================================
int UI::startBtnClicked(int chuteID)
{
    emit ChuteStartButtonClicked(chuteID);
    return 0;

}
// =========================================================================
void UI::ADDSortingType(QStringList labels, int chuteID)
{

    for(int i=0 ; i<labels.count() ; i++) {

        if(chuteLabels.indexOf(labels[i])>-1)
            continue;


        chuteLabels.append(labels[i]);
        if(i<labels.count()/2)
        {
            QMetaObject::invokeMethod((QObject*)RootObject, "addSortingType",
                                      Q_ARG(QVariant,labels[i]),
                                      Q_ARG(QVariant,chuteID)
                                      );
        }
        else
        {
            QMetaObject::invokeMethod((QObject*)RootObject, "addSortingTypePersian",
                                      Q_ARG(QVariant,labels[i]),
                                      Q_ARG(QVariant,chuteID)
                                      );
        }
    }
}
// =========================================================================
void UI::ClearAllSortingTypes()
{
       QMetaObject::invokeMethod((QObject*)RootObject, "clearSortingType");
}
// =========================================================================
void UI::UpdateElapsedTime(int chuteID, QString elapsedTime)
{
    QMetaObject::invokeMethod((QObject*)RootObject, "updateElapsedTime",
                              Q_ARG(QVariant, chuteID),
                              Q_ARG(QVariant, elapsedTime)
                              );
}
// =========================================================================
void UI::UpdateTotalValues(QString totalUpTime, QString totalObject, QString totalValve)
{

    QMetaObject::invokeMethod((QObject*)RootObject, "updateTotalValues",
                              Q_ARG(QVariant, totalUpTime),
                              Q_ARG(QVariant, totalObject),
                              Q_ARG(QVariant, totalValve)
                              );
}
// =========================================================================
void UI::SetTemperatureTable(int chuteID, int frontCamTemp, int rearCamTemp, int processorTemp) {

    QMetaObject::invokeMethod((QObject*)RootObject, "setTemperatureTable",
                              Q_ARG(QVariant, QString::number(chuteID)),
                              Q_ARG(QVariant, QString::number(frontCamTemp)),
                              Q_ARG(QVariant, QString::number(rearCamTemp)),
                              Q_ARG(QVariant, QString::number(processorTemp))
                              );
}
// =========================================================================
void UI::SetAirPressureTable(int pressure) {

    QMetaObject::invokeMethod((QObject*)RootObject, "setAirPressureTable",
                              Q_ARG(QVariant, QString::number(pressure))
                              );
}
// =========================================================================
void UI::UpdateCameraStatus(int chuteID, int error)
{
    QMetaObject::invokeMethod((QObject*)RootObject, "updateCameraStatus",
                              Q_ARG(QVariant, chuteID),
                              Q_ARG(QVariant, error)
                              );
}
// =========================================================================
void UI::UpdateSerialPortStatus(int chuteID, int error)
{
    QMetaObject::invokeMethod((QObject*)RootObject, "updateSerialPortStatus",
                              Q_ARG(QVariant, chuteID),
                              Q_ARG(QVariant, error)
                              );
}
// =========================================================================
void UI::UpdateAirPressureStatus(int chuteID, int error)
{
    qDebug() << "modbus status is: " << error;
    QMetaObject::invokeMethod((QObject*)RootObject, "updateAirPressureStatus",
                              Q_ARG(QVariant, chuteID),
                              Q_ARG(QVariant, error)
                              );
}
// =========================================================================
void UI::UpdateModBusStatus(int error)
{

    QMetaObject::invokeMethod((QObject*)RootObject, "updateModBusStatus",
                              Q_ARG(QVariant, error)
                              );
}
// =========================================================================
void UI::DisplayMessage(QString message) {
    QMetaObject::invokeMethod((QObject*)RootObject, "errorStartSorting",
                               Q_ARG(QVariant, message));
}
// =========================================================================
void UI::SetStartButtonState(int chuteID,int stat)
{

    // 0 => Running
    // 1 => Idle
    QMetaObject::invokeMethod((QObject*)RootObject, "setStartButtonState",
                              Q_ARG(QVariant,chuteID),
                              Q_ARG(QVariant,stat)
                              );

}
// =========================================================================
void UI::setFeederSpeed(int chuteID, int speed)
{
    emit SetFeederSpeed(chuteID, speed);
}
// ============================================ //
void UI::shutdownUI()
{
    emit SystemShutDownRequest();

}
// =========================================================================
void UI::rebootUI()
{
emit SystemRebootRequest();

}
// =========================================================================
void UI::setChuteTimer(int chuteID, int hour, int minute)
{
    emit SetElapsedTime(chuteID, hour, minute);
}
// =========================================================================
void UI::shutDownChute(int chuteID)
{
    emit ChuteShutdown(chuteID);
}
void UI::rebootChute(int chuteID)
{
    emit ChuteReboot(chuteID);
}
