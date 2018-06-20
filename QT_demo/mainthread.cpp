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
#include <QDomDocument>


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
            //parseDefaultConfFile();
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
    if (defaultConfFile.isEmpty())
        return;

    QFile configFile(defaultConfFile);
    configFile.open(QIODevice::ReadOnly);
    qDebug()<<"==file size :"<<configFile.size();
    //std::count<<
    while(!configFile.atEnd()) {
        line = "";
        data=configFile.readLine();
        //std::cout << "std:" << data.toStdString() << "\n";
        line.append(data);
        qDebug() << line;
    }

    configFile.close();
}

void mainThread::parseSequenceScript(void)
{
    int i = 0;
    if (sequenceScript.isEmpty())
        return;

    QFile *sequenceScriptFile = new QFile(sequenceScript);
    sequenceScriptFile->open(QFile::ReadOnly);

    QDomDocument doc;
    QString errorStr;
    int errorLine;
    int errorCol;


    if(!doc.setContent(sequenceScriptFile,true,&errorStr,
                           &errorLine,&errorCol))
        {
            //file.close();
            qDebug()<<"errorStr:"<<errorStr<<"\n";
            qDebug()<<"errorLine:"<<errorLine<<
                    "  errorCol:"<<errorCol;
        }

    QDomElement root = doc.documentElement();
    qDebug() << "root :" << root.tagName();
    qDebug() << "attribute:" << root.attribute("ScriptName") << "："<< root.attribute("RepeatTimes");
    QDomNode n = root.firstChild(); //返回根节点的第一个子节点
    while(!n.isNull())
    { //如果节点不为空
        if (n.isElement()) //如果节点是元素
        {
            QDomElement e = n.toElement(); //将其转换为元素
            qDebug() << qPrintable(e.tagName()) //返回元素标记
            << qPrintable(e.attribute("id")); //返回元素id属性的值
            QDomNodeList list = e.childNodes(); //获得元素e的所有子节点的列表
            for(int i=0; i<list.count(); i++) //遍历该列表
            {
                QDomNode node = list.at(i);
                if(node.isElement())
                qDebug() << "::::"<< qPrintable(node.toElement().tagName())
                <<qPrintable(node.toElement().text());
            }
        }

        n = n.nextSibling(); //下一个兄弟节点

    }
    QDomNodeList rootList = root.childNodes();
    qDebug() << "rootList.count() :" << rootList.count();

    QDomElement ele = root.firstChildElement();
    qDebug() <<"ele.text():" << ele.text();
    qDebug() << "root.firstChildElement :" << ele.tagName();
    QDomNodeList list = ele.childNodes(); //获得元素e的所有子节点的列表
    ele.nextSiblingElement();
    qDebug() << "list.count() :" << list.count();

      for(;!ele.isNull();ele = ele.nextSiblingElement()){
          qDebug() << "ele.nextSiblingElement().tagname :" << ele.tagName();
          ele.firstChildElement();
          if(ele.hasAttribute("id"))
          {
              qDebug()<<i<<": "<<ele.attributeNode("id").value();
              i++;
          }
      }


#if 0
    QXmlStreamReader *reader = new QXmlStreamReader(sequenceScriptFile);
         while(!reader->atEnd() && !reader->hasError()) {

             reader->readNext();
             if (reader->isStartElement()) {
                if ((reader->name() =="MiniScript"))
                {
                    qDebug() << "12345:"; //<< reader->attributes().value();
                }
                if ((reader->name() =="MiniScript") ||
                        (reader->name() == "Temperature") ||
                       (reader->name() == "Valve") ||
                        (reader->name() == "Pump") ||
                        (reader->name() == "CMOSSensor") ||
                        (reader->name() == "Delay")  ) {
                    qDebug() << "4 reader->name():" << reader->name();
                    continue;
                } else {
                    qDebug() << "5reader->name():" << reader->name();
                    QString elementText = reader->readElementText();
                    qDebug() << "readElementText:" << elementText;
                }
              }
             if (reader->isEndElement()) {
                        qDebug() << "6reader->name():" << reader->name();
             }

         }
        if (reader->hasError()) {
            qDebug() <<"reader->hasErro" << reader->errorString();
            //QMessageBox::information(NULL, QString("parseXML"), reader->errorString());
        }
        reader->clear();
        delete reader;
        reader = NULL;
#endif

        sequenceScriptFile->close();
        delete sequenceScriptFile;
        sequenceScriptFile = NULL;
}

int mainThread::getSequenceRepeatTimes()
{
    int repeatTimes = -1;
    if (sequenceScript.isEmpty())
        return -1;

    QFile *sequenceScriptFile = new QFile(sequenceScript);
    sequenceScriptFile->open(QFile::ReadOnly);



    sequenceScriptFile->close();
    delete sequenceScriptFile;
    sequenceScriptFile = NULL;

    return repeatTimes;
}

QString mainThread::getSequenceScriptName()
{
    QString scriptName;
    if (sequenceScript.isEmpty())
        return "";

    QFile *sequenceScriptFile = new QFile(sequenceScript);
    sequenceScriptFile->open(QFile::ReadOnly);



    sequenceScriptFile->close();
    delete sequenceScriptFile;
    sequenceScriptFile = NULL;

    return scriptName;
}
