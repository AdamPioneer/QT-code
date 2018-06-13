#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <QMutex>
#include <qlogging.h>
#include <QDebug>

#include "mythread.h"
#include <qthread.h>
#if 0
namespace Ui {
class myThread;
}

class myThread : public QThread
{
    Q_OBJECT
public:
    Thread();
    void stop();
private:
    bool m_stopFlag;
    QMutex mutex;
protected:
    void run();
};


#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    myThread backGroudThread;

    QObject::connect(&backGroudThread, SIGNAL(finished()), &a, SLOT(quit()));
    backGroudThread.setPriority(backGroudThread.HighPriority);
    backGroudThread.start();//启动线程

    w.init_setup();
    QObject::connect(&a, SIGNAL(finished()), &a, SLOT(quit()));
    w.show();

    return a.exec();
}
