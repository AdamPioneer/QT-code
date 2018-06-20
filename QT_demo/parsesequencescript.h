#ifndef PARSESEQUENCESCRIPT_H
#define PARSESEQUENCESCRIPT_H
#include <QtXml>
#include <QDomDocument>
#include <QXmlStreamReader>
//#include <QXmlStreamWriter>

class parseSequenceScript //: public QXmlStreamReader
{
public:
    parseSequenceScript();

private:
    QXmlStreamReader *reader;
protected:
};

#endif // PARSESEQUENCESCRIPT_H
