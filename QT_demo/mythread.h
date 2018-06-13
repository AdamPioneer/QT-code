#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutex>

class myThread : public QThread
{
 //   Q_OBJECT
public:
    myThread();
    void stop();
private:
    bool m_stopFlag;
    QMutex mutex;
protected:
    void run();
};

#endif // MYTHREAD_H
