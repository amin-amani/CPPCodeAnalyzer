#include "UI.h"

QStringList UI::GetDtatSetFilesList(QString path)
{
    QStringList result;
    QStringList filters={".h",".hpp"};
    QDirIterator directoryIterator(path, QDirIterator::Subdirectories);
    while (directoryIterator.hasNext())
    {
        QString fname= directoryIterator.next();
        if(fname.contains("/."))
            continue;

        for(int i=0;i<filters.count();i++)
        {

            if(fname.endsWith(filters[i]))
            {
                result.append(fname);


                break;
            }

        }
    }
    return result;
}
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


    QStringList files= GetDtatSetFilesList("E:\\Sorter Files\\SorterNew_trt8_new git\\SorterNew\\src");
    for(int i=0;i<files.count();i++)
    {
        qDebug()<<"in file:"<<files[i];
        parser.SetFileName(files[i]);
        QList<CPPClass> classes= parser.GetAllClasses();

            foreach(CPPClass c,classes)
            {
              qDebug()<<c.Name;
            }


    }

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
