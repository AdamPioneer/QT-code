#include "mythread.h"
#include <QMutex>
#include <qlogging.h>
#include <QDebug>
#include <qthread.h>

myThread::myThread()
{
    m_stopFlag = false;
}

void myThread::stop()
{
    QMutexLocker locker(&mutex);
    m_stopFlag = true;
}

void myThread::run()
{
  //  system("cmd");
    QObject QO;

    while(1){
        {
            QMutexLocker locker(&mutex);
            if(m_stopFlag)
                break;
        }
        qDebug()<<"This is in thread["<<currentThreadId()<<"]."<<(int)currentThread();
        sleep(2);
    }
    m_stopFlag = false;
}
