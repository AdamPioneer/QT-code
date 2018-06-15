#include "stm32controlthread.h"
#include <QMutex>
#include <qlogging.h>
#include <QDebug>
#include <qthread.h>

STM32ControlThread::STM32ControlThread()
{

}

void STM32ControlThread::stop()
{
    stopFlag = true;
}

void STM32ControlThread::run()
{
    while(1)
    {
        //need to do
        sleep(3);
    }
}

