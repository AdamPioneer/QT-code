#ifndef mainThread_H
#define mainThread_H

#include <QThread>
#include <QMutex>
#include <strings.h>
#include <QString>
#include <string>
#include <QFile>

#include <QtXml>
#include <QDomDocument>
#include <QXmlStreamReader>

class ParseSequenceScript : public QXmlStreamReader
{
public:

private:
    QXmlStreamReader *reader;
protected:
};

class mainThread : public QThread
{
 //   Q_OBJECT
public:
    mainThread();
    void stop();
    ParseSequenceScript *mytest;

    /* sequence script */
    QString getSequenceScriptName();
    int getSequenceRepeatTimes();
    void setSequenceScript(QString Script);
    void parseSequenceScript(void);

    /*defaule configuration */
    void setDefaultConfFile(QString File);
    void parseDefaultConfFile(void);
private:
    QString defaultConfFile;
    QString sequenceScript;
    bool m_stopFlag;
    ParseSequenceScript *parseSequence;
    QMutex mutex;

protected:
    void run();

};

#endif // mainThread_H
