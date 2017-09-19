#include "camerathread.h"
#include <QMessageBox>
#include <iostream>
#include <QImage>
#include <QVector>

using namespace cv;
using namespace std;

CameraThread::CameraThread()
{
    start_signal = false;
    stop_signal = false;
    once_signal = false;
}

int CameraThread::Grab()
{
    imgMat = cvQueryFrame(capture);

    if(imgMat.type()==CV_8UC1){
        //cout<< "CV_8UC1" <<endl;
        QVector<QRgb> sColorTable;
        if(sColorTable.isEmpty())
        {    sColorTable.resize(256);
            for(int i=0; i<256; ++i)
            {
                sColorTable[i] = qRgb(i, i, i);
            }
        }
         QImage qimg((uchar*)imgMat.data, imgMat.cols, imgMat.rows, imgMat.step, QImage::Format_Indexed8);
         emit sendImage(qimg);
    }else if(imgMat.type()==CV_8UC3){
        //cout<< "CV_8UC3"<<endl;
        QImage qimg((uchar*)imgMat.data, imgMat.cols, imgMat.rows, imgMat.step, QImage::Format_RGB888);
        emit sendImage(qimg.rgbSwapped());
    }
    return 0;
}

int CameraThread::ProcessImage()
{
    Canny(imgMat, imgMat, 100, 200, 5);
    std::vector<std::vector<cv::Point> > contours;
    findContours(imgMat, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    vector<Moments> mu(contours.size());

    for (int i = 0; i < contours.size(); i++)
    {
        mu[i] = moments(contours[i], false);
    }
    //  Get the mass centers:
    vector<Point2f> mc(contours.size());
    for (int i = 0; i < contours.size(); i++)
    {
        mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
    }
    //contours to point iterator
    std::vector<std::vector<cv::Point> >::iterator it = contours.begin();
    int i = 0;
    //change color gray -> CV_8UC3
    Mat drawing = Mat::zeros(imgMat.size(), CV_8UC3);
    //draw line and center

    float pointX = 0;
    float pointY = 0;
    while (it != contours.end())
    {
        //poly vector
        std::vector<cv::Point> poly;
        //get poly vector from points (poly line length)
        cv::approxPolyDP(*it, poly, 10, true);
        //is it square?
        //if (poly.size() == 4)
        if (poly.size() >= 4 && fabs(contourArea(Mat(poly))) > 1000 && isContourConvex(Mat(poly)))
        //if (poly.size() >= 4)
        {
            //draw lines
            cv:polylines(drawing, poly, true, Scalar(255, 255, 0), 5);
            //cv::rectangle(drawing, poly[0], poly[2], CV_RGB(0, 255, 0), 2);
            //draw centers
            circle(drawing, mc[i], 4, Scalar(100, 200, 0), -1, 8, 0);
            //ostringstream stream;
            //stream << mc[i].x;
            //ui->plainTextEdit->appendPlainText(QString::fromStdString(stream.str()));
            //ui->plainTextEdit->verticalScrollBar()->maximum();

            //cout<<stream.str();
            if(pointX==0&&pointY==0)
            {
                pointX=mc[i].x;
                pointY=mc[i].y;
            }
        }
        ++it;
        i++;
    }
    ostringstream osX;
    osX<<pointX;
    ostringstream osY;
    osY<<pointY;
    if(pointX!=0&&pointY!=0){
        cout<<"X: "+osX.str()+", Y: "+osY.str()<<endl;
    }
    return 0;
}

int CameraThread::Pickup()
{
    // Move to pickup position

    // check motors

    // move motor
   /// MoveXYPosition(POS_PICKUP);

   /// MoveZToPickupLevel();

   /// GripForPickupPosition();

   /// MoveZToOffsetLevel();


    return 0;
}
int CameraThread::Place()
{
    int retv;
    /// retv = CheckSafety(); if(retv) return retv;
    /// retv = MoveXYPosition(POS_PLACE); if(retv) return retv;
    /// retv = MoveZ(POS_PLACE); if(retv) return retv;
    ///
    if(1)
    {
        // Okay
        /// handler->YIELD_OKAY++;
    }
    else
    {
        /// handler->YIELD_NG++;
    }
    return 0;
}

void CameraThread::run()
{
    capture = cvCaptureFromCAM(0);

    stop_signal=false;

    while(1)
    {
        // Handle for click of start button
        if(start_signal || once_signal)
        {
            if(Grab())
            {
                // sth wrong wrt Grabbing
            }
            if(ProcessImage())
            {
            }
            if(Pickup())
            {

            }
            if(Place())
            {

            }
            once_signal = false;
        }


        // Handle for click of stop button
        if(stop_signal)
        {
            start_signal = 0;
            stop_signal = 0;
        }
        sleep(0.1);
    }
}

