#ifndef UI_H
#define UI_H

#include <QObject>
#include <QDir>
#include <QDirIterator>
#include <QDebug>
#include <QMetaObject>
#include <QtQuick/QQuickView>
#include <QDateTime>
#include <QtQml/qqmlcontext.h>
#include <stdlib.h>
#include <stdio.h>
#include <QEventLoop>
#include <QtQml/QQmlApplicationEngine>
#include <QTimer>
#include <QElapsedTimer>
#include <QtNetwork/QNetworkInterface>
#include "parser.h"
#include "Types.h"
class UI : public QObject
{
    Q_OBJECT
    QQmlContext *ctx;
    QString sorterStatus;
    Parser parser;


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

    explicit UI(QObject *parent = nullptr);
    Q_INVOKABLE void closeApp();

    QString name() const { return m_name; } // sample
    void setName(const QString &name) { m_name = name; } // sample

    QString hourTimer() const { return _hourTimer; }
    void sethourTimer(const QString &hourTimer) { _hourTimer = hourTimer; }

    QString minuteTimer() const { return _minuteTimer; }
    void setminuteTimer(const QString &minuteTimer) { _minuteTimer = minuteTimer; }

    void WaitMs(int ms);
    void Init();
    QStringList GetDtatSetFilesList(QString path);
signals:

    void ChuteStartButtonClicked(int id);
    // =========================================================================



public slots:
    void AddChute(int id);
    // =========================================================================


};


#endif // UI_H
