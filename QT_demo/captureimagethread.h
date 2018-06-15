#ifndef CAPTUREIMAGETHREAD_H
#define CAPTUREIMAGETHREAD_H
#include <QObject>
#include <QThread>
#include <QMutex>

class captureImageThread : public QThread
{
public:
    captureImageThread();
private:

protected:
    void run();
};

#endif // CAPTUREIMAGETHREAD_H
