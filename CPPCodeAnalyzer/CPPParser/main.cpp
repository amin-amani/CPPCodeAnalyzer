#include <QCoreApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QtQuick/qquickview.h>
#include <QGuiApplication>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>


#include <QTranslator>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlApplicationEngine>
#include <QtNetwork/QUdpSocket>
#include "UI.h"
UI ui;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv); // to show charts use this one

    QQuickView view;
    view.engine()->rootContext()->setContextProperty("ui", &ui);
    view.setSource(QUrl(QLatin1String("qrc:/main.qml")));
    ui.RootObject=view.rootObject();
    ui.View=&view;
    ui.Init();
    return a.exec();
}
