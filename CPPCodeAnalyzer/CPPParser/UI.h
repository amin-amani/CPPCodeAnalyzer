#ifndef UI_H
#define UI_H

#include <QObject>
#include <QDebug>
#include <QMetaObject>
#include <QtQuick/QQuickView>
#include <QDateTime>
#include <QtQml/qqmlcontext.h>
#include <QTranslator>
#include <stdlib.h>
#include <stdio.h>
#include <QEventLoop>
#include <QtQml/QQmlApplicationEngine>
#include <QTimer>
#include <QElapsedTimer>
#include <QtNetwork/QNetworkInterface>

class UI : public QObject
{
    Q_OBJECT
    QString frontStatus="Not connected";
    QString rearStatus="Not connected";
    QStringList chuteNameList;
    QStringList chuteProcTempList;
    QList<QStringList> delegatess;
    QList<QString> chuteLabels;
    QQmlContext *ctx;
    QString sorterStatus;
    int ModBusStatus;
    QString UiIP = "192.168.1.100";

    //============================================================================================================================


    QString m_name; // sample
    QString _hourTimer;
    QString _minuteTimer;
    //============================================================================================================================
    void UpdateTimerButtonText(int chuteID, int hour, int minute);
    // ============================================ //

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString hourTimer READ hourTimer WRITE sethourTimer)
    Q_PROPERTY(QString minuteTimer READ minuteTimer WRITE setminuteTimer)
    // Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)


public:

    QQuickItem *RootObject=nullptr;
    QQuickView  *View=nullptr;
    QTranslator m_translator;


    explicit UI(QObject *parent = nullptr);
    Q_INVOKABLE void closeApp();
    Q_INVOKABLE void sendSortingType(int chuteID, QList<QString> labels);
    Q_INVOKABLE void setFeederSpeed(int chuteID, int speed);
    Q_INVOKABLE void setChuteTimer(int chuteID, int hour, int minute);
    Q_INVOKABLE void shutDownChute(int chuteID);
    Q_INVOKABLE void rebootChute(int chuteID);



    QString name() const { return m_name; } // sample
    void setName(const QString &name) { m_name = name; } // sample

    QString hourTimer() const { return _hourTimer; }
    void sethourTimer(const QString &hourTimer) { _hourTimer = hourTimer; }

    QString minuteTimer() const { return _minuteTimer; }
    void setminuteTimer(const QString &minuteTimer) { _minuteTimer = minuteTimer; }

    void WaitMs(int ms);
    void Init();
signals:

    void ChuteStartButtonClicked(int id);
    // =========================================================================
    void SystemShutDownRequest();
    // =========================================================================
    void SystemRebootRequest();
    // =========================================================================
    void sendSortingTypeRequest(int chuteID, QList<QString> labels);
    // =========================================================================
    void SetFeederSpeed(int chuteID, int feederSpeed);
    // =========================================================================
    void SetElapsedTime(int chuteID, int hour, int minute);
    // =========================================================================
    void ChuteShutdown(int chuteID);
    // =========================================================================
    void ChuteReboot(int chuteID);


public slots:
    void AddChute(int id);
    // =========================================================================
    void DeleteChute(int id);
    // =========================================================================
    void UpdateChart(int64_t totalAccept, int64_t totalEject);
    // =========================================================================
    void ADDSortingType(QStringList labels, int chuteID);
    // =========================================================================
    void ClearAllSortingTypes();
    // =========================================================================
    void UpdateElapsedTime(int chuteID, QString elapsedTime);
    // =========================================================================
    void UpdateTotalValues(QString totalUpTime, QString totalObject, QString totalValve);
    // =========================================================================
    void SetTemperatureTable(int chuteID, int frontCamTemp, int rearCamTemp, int processorTemp);
    // =========================================================================
    void SetAirPressureTable(int pressure);
// =========================================================================
    void UpdateCameraStatus(int chuteID, int error);
    // =========================================================================
    void UpdateSerialPortStatus(int chuteID, int error);
    // =========================================================================
    void UpdateAirPressureStatus(int chuteID, int error);
    // =========================================================================
    void UpdateModBusStatus(int error);
    // =========================================================================
    void DisplayMessage(QString message);
    // =========================================================================
    void SetStartButtonState(int chuteID, int stat);
    // =========================================================================
    void DisplayProgressBar(bool status, bool visibility);
    // =========================================================================
    int startBtnClicked(int chuteID);
    // =========================================================================
    void shutdownUI();
    // =========================================================================
    void rebootUI();
    // =========================================================================

};


#endif // UI_H
