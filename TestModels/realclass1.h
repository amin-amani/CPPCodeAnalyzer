#ifndef OBJECTDETECTION_H
#define OBJECTDETECTION_H

#include <QObject>
#include <QRunnable>
#include "QsLog.h"
#include <opencv4/opencv2/opencv_modules.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/opencv_modules.hpp>
#include <opencv4/opencv2/core/cuda.hpp>
#include <opencv4/opencv2/core/core.hpp>
#include <QMutexLocker>
#include <QRunnable>
#include <QTime>
#include "Vision.h"

#define  Privates private
#ifdef QT_QTTEST_MODULE_H
#define Privates public
#endif

//#define DETECTOR_DEBUG
//#define USE_GPU_CANNY
//===========================================================================================

class ObjectDetection : public QObject,  public QRunnable
{

    cv::Mat _background;
    int morph_size=3;
    int morph_elem = 0;
    const int _cannyMaxThreshold=120;
    const int _cannyMinThreshold=30;
    float scale=0.5;//0.5

    int max=400*scale,min=100*scale;
    cv::Mat element = cv::getStructuringElement( morph_elem, cv::Size( 2*morph_size + 1, 2*morph_size+1 ), cv::Point( morph_size, morph_size ) );
    const int _offsetY =0;//50;


    Q_OBJECT
#ifdef USE_GPU_CANNY
    cv::Ptr<cv::cuda::CannyEdgeDetector> canny_edg = cv::cuda::createCannyEdgeDetector(30, 200.0, 3, false);
#endif
    cv::cuda::GpuMat _imageDev,_imageDev2;
    QMutex _mutex;
    VisionResult _processResult;
    //-------------------------------------------------------------------------------------------
public:
    //Privates:
    void FindBlobs(cv::Mat grayImage, VisionResult cameraInput);
    void FilterBlobs(std::vector<cv::Point> contour, VisionResult *cameraInput);
    void AddRect(cv::Rect rect, VisionResult *cameraInput);
    void ScaleRect(cv::Rect *rect);
    void AddMarginToRect(cv::Rect *rect, VisionResult *cameraInput, int offset);

public:

    //===========================================================================================
    explicit ObjectDetection(QObject *parent = nullptr);
    //===========================================================================================
    ObjectDetection(VisionResult cameraInput, cv::Mat backGround);
    //===========================================================================================
    ~ObjectDetection();
    //===========================================================================================
    QVector<cv::Mat> DetectObjectsToTest(cv::Mat image);
    //===========================================================================================

    void Init(VisionResult cameraInput, cv::Mat backGround);
    void SetBackgroundImage(cv::Mat backGround);
    void DetectObjects();
    void DetectObjectsColors(VisionResult cameraInput);
protected:
    //===========================================================================================
    void run();
    //===========================================================================================
public slots:
    //===========================================================================================
    void DetectObjects(VisionResult cameraInput);
    //===========================================================================================
signals:
    //===========================================================================================
    void NewObjectDetected(VisionResult detectionOut);
    //===========================================================================================
    void NoObjectDetected();
    //===========================================================================================

};

#endif // OBJECTDETECTION_H
