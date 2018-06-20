#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <QMutex>
#include <qlogging.h>
#include <QDebug>
#include <qthread.h>

#include "globalparameter.h"
#include "parsesequencescript.h"


STM32ControlThread STM32Thread;
captureImageThread ImageThread;
mainThread ecoliThread;
//parseSequenceScript reader;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QObject::connect(&ecoliThread, SIGNAL(finished()), &a, SLOT(quit()));
    QObject::connect(&STM32Thread, SIGNAL(finished()), &a, SLOT(quit()));
    QObject::connect(&ImageThread, SIGNAL(finished()), &a, SLOT(quit()));

    ecoliThread.setPriority(QThread::HighPriority);
    STM32Thread.setPriority(QThread::HighestPriority);
    ImageThread.setPriority(QThread::HighestPriority);

    ecoliThread.start();//启动线程
    STM32Thread.start();//启动线程
    ImageThread.start();//启动线程

    w.init_setup();
    QObject::connect(&a, SIGNAL(finished()), &a, SLOT(quit()));
    w.show();

    return a.exec();
}
