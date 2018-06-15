#ifndef STM32CONTROLTHREAD_H
#define STM32CONTROLTHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>

class STM32ControlThread : public QThread
{
public:
    STM32ControlThread();
    void stop();
private:
     QMutex mutex;
     bool stopFlag;
protected:
    void run();
};

#endif // STM32CONTROLTHREAD_H
