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
//   QVariant returnedValue ;

//    QMetaObject::invokeMethod((QObject*)view->rootObject(),"setText",Qt::AutoConnection
//                              , Q_RETURN_ARG(QVariant, returnedValue)
//                              ,Q_ARG(QVariant,  "amin")
//                                  );



}
void MainWindow::printText(QVariant var)
{
    qDebug()<<"cpp"<<var;

    SetText("amin!");
}
void MainWindow::SetText(QString name)
{

    QVariant returnedValue ;

     QMetaObject::invokeMethod((QObject*)view->rootObject(),"setText",Qt::AutoConnection
                               , Q_RETURN_ARG(QVariant, returnedValue)
                               ,Q_ARG(QVariant,  name)
                                   );

}
void MainWindow::CreateObject()
{

    imgv=new MYImageViewer();
//
  //  QQmlEngine* engine = QtQml::qmlEngine( this );
      //  view->setSource(QUrl(QLatin1String("qrc:/main.qml")));
    //QQmlComponent splitComp( engine, QUrl( "qrc:/classObject.qml" ) );

    //dynamically loaded component/
    //QQmlComponent component(view->engine(), QUrl::fromLocalFile("qrc:/classObject.qml"));
    //QObject *object = component.create();
    //QQuickItem item = qobject_cast<QQuickItem>(object);

    //view->setSource(QUrl::fromLocalFile("MyItem.qml"));
    //view->show();
    //QObject *object = view->rootObject();

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    CreateObject();
}
