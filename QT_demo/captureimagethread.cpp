#include "captureimagethread.h"
#include <QMutex>
#include <qlogging.h>
#include <QDebug>
#include <qthread.h>

captureImageThread::captureImageThread()
{

}

void captureImageThread::run()
{
    while(1)
    {
        //need to do

        //qDebug()<<"This is in thread [captureImageThread]";
        sleep(2);
    }
}
