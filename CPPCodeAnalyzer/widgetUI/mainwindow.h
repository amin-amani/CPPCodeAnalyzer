#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtQuick/QQuickView>
#include <QMetaObject>
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>
#include <qqmlcomponent.h>
#include <QObject>
#include <QDir>
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include "MyImageViewer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QObject *qmlRoot=nullptr;
    MYImageViewer *imgv;
         QQuickView *view ;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Q_INVOKABLE void printText(QVariant var);
    ~MainWindow();


         void  SetText(QString name);
         void CreateObject();
private:
    Ui::MainWindow *ui;

public  slots:

private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
