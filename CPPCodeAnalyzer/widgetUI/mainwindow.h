#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtQuick/QQuickView>
#include <QMetaObject>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>
#include <QObject>
#include <QDir>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QObject *qmlRoot=nullptr;
         QQuickView *view ;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Q_INVOKABLE void printText(QVariant var);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

public  slots:

};

#endif // MAINWINDOW_H
