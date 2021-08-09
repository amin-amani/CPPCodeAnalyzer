#ifndef ICLASSIFIER_H
#define ICLASSIFIER_H
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QTime>
//#include "QsLog.h"
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <QThread>
#include <QRunnable>
#include <Vision.h>



using namespace std;
using namespace chrono;
class ClassifyResult
{
public:
    ClassifyResult(){}
    ClassifyResult(QString lable,float probablity,float inferenceTime)
    {
        Lable=lable;
        Probablity= probablity;
        InferenceTime=inferenceTime;
    }
    cv::Mat image;
    QString Lable;
    float Probablity;
    float InferenceTime;
};
class Classifier :  public QObject
{
    Q_OBJECT
public:
     virtual int Init(QString modelPath,int imageHeight,
                   int imageWidth,int channel,int minBatch,
                   int optBatch,int maxBatch,QString engineName)=0;


signals:
    void ClassifyCompleted(QString classname);
    void ClassifyCompleted(ClassifyResult result);
    void ClassifyCompleted();
    //=====================================================================================================
    void ClassifyCompleted(VisionResult result);
public slots:
    virtual VisionResult DoClassify(VisionResult Input)=0;
};
#endif // ICLASSIFIER_H


