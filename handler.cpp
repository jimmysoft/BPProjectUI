#include "handler.h"
#include "camerathread.h"
#include <QImage>
#include "iostream"

using namespace std;
Handler *handler = NULL;
Handler::Handler(MainWindow* qmainWindow)
{
    cameraThread = new CameraThread();
    connect(cameraThread, SIGNAL(sendImage(QImage)), qmainWindow, SLOT(changeLabel(QImage)));
    cameraThread->start();

}


void Handler::Start()
{
    cameraThread->start_signal=true;
}

void Handler::Once()
{
    cameraThread->once_signal= true;
}

void Handler::Stop()
{
    cameraThread->stop_signal=true;
}

