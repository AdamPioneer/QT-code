#include "mythread.h"
#include <QMutex>
#include <qlogging.h>
#include <QDebug>
#include <qthread.h>
#include "msg.h"


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
    int msqid;
    QObject QO;
    msqid = create_msg();

    while(1){
        {
            QMutexLocker locker(&mutex);
            if(m_stopFlag)
                break;
        }
        write_msg(msqid);
        qDebug()<<"This is in thread["<<currentThreadId()<<"]."<<currentThread();
        sleep(2);
    }
    m_stopFlag = false;
}
