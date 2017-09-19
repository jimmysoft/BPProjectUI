#ifndef HANDLER_H
#define HANDLER_H

#include "mainwindow.h"
#include <camerathread.h>

class Handler : public QObject
{
public:

    Handler(MainWindow*);
    CameraThread *cameraThread;
    void Start();
    void Stop();
    void Once();


public:
    int YIELD_OKAY;
    int YIELD_NG;
};
extern Handler *handler;



#endif // HANDLER_H
