#ifndef mainThread_H
#define mainThread_H

#include <QThread>
#include <QMutex>
#include <strings.h>
#include <QString>
#include <string>
#include <QFile>

class mainThread : public QThread
{
 //   Q_OBJECT
public:
    mainThread();
    void stop();

    void setDefaultConfFile(QString File);
    void setSequenceScript(QString Script);
private:
    QString defaultConfFile;
    QString sequenceScript;
    bool m_stopFlag;
    QMutex mutex;
    void parseSequenceScript(void);
    void parseDefaultConfFile(void);
protected:
    void run();
};

#endif // mainThread_H
