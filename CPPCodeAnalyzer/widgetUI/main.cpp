#include "mainwindow.h"
#include <QApplication>
#include "MyImageViewer.h"
#include "squircle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qmlRegisterType<MYImageViewer>("MyLibrary", 1, 0, "MyImageViewer");
     qmlRegisterType<Squircle>("OpenGLUnderQML", 1, 0, "Squircle");
    //MainWindow w;
    //w.showMaximized();

     QQuickView view;
     view.setResizeMode(QQuickView::SizeRootObjectToView);
     view.setSource(QUrl("qrc:/main.qml"));
     view.show();

    return a.exec();
}
