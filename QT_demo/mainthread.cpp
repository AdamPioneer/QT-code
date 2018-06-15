#include "mainthread.h"
#include <QMutex>
#include <qlogging.h>
#include <QDebug>
#include <qthread.h>

#include<sys/shm.h>  // shared memory
#include<sys/sem.h>  // semaphore
#include<sys/msg.h>  // message queue
#include <iostream>

#include "msg.h"



mainThread::mainThread()
{
    m_stopFlag = false;
}

void mainThread::stop()
{
    //QMutexLocker locker(&mutex);
    m_stopFlag = true;
}

void mainThread::run()
{
  //  system("cmd");
    int msqid;
    QObject QO;
    //msqid = create_msg();

    while(1){

        //write_msg(msqid);
        if(!defaultConfFile.isEmpty())
            qDebug()<<"defaultConfFile:"<<defaultConfFile;
        if(!sequenceScript.isEmpty()) {
            qDebug()<<"sequenceScript:"<<sequenceScript;
            parseDefaultConfFile();
        }
        sleep(1);
    }
    m_stopFlag = false;
}
void mainThread::setDefaultConfFile(QString File)
{
    if (!File.isEmpty())
        defaultConfFile=File;
}

void mainThread::setSequenceScript(QString Script)
{
    if (!Script.isEmpty())
        sequenceScript = Script;
}

void mainThread::parseDefaultConfFile()
{
    QString line;
    QByteArray data;
    if (sequenceScript.isEmpty())
        return;
    QFile sequenceScriptFile(sequenceScript);
    sequenceScriptFile.open(QIODevice::ReadOnly);
    qDebug()<<"==file size :"<<sequenceScriptFile.size();
    //std::count<<
    while(!sequenceScriptFile.atEnd()) {
        line = "";
        data=sequenceScriptFile.readLine();
        //std::cout << "std:" << data.toStdString() << "\n";
        line.append(data);
        qDebug() << line;
    }

    sequenceScriptFile.close();
}

