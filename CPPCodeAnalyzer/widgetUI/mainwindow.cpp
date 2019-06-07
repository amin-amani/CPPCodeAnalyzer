#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(this->width()+200,this->height()+100);
    //container->setMaximumSize(200, 200);
    //container->setMaximumSize(this->width(),this->height());
    container->setFocusPolicy(Qt::TabFocus);
    view->setSource(QUrl(QLatin1String("qrc:/main.qml")));

    view->engine()->rootContext()->setContextProperty("cppgui", this);
    ui->verticalLayout->setSpacing(0);
    ui->verticalLayout->setContentsMargins(0, 0, 0, 0);
    ui->verticalLayout->addWidget(container);

//ui->widget=container;
   QVariant returnedValue ;

    QMetaObject::invokeMethod((QObject*)view->rootObject(),"setText",Qt::AutoConnection
                              , Q_RETURN_ARG(QVariant, returnedValue)
                              ,Q_ARG(QVariant,  "amin")
                                  );

    QMetaObject::invokeMethod((QObject*)view->rootObject(),"setx",Qt::AutoConnection
                              , Q_RETURN_ARG(QVariant, returnedValue)
                              ,Q_ARG(QVariant,  700)
                                  );

}
void MainWindow::printText(QVariant var)
{
    qDebug()<<"cpp"<<var;

    //SetText("amin!");
}
MainWindow::~MainWindow()
{
    delete ui;
}
