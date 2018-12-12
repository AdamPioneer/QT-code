#include "sld.h"
#include <QDebug>

SLD::SLD()
{
    qDebug()<<"";
}


QString SLD::GetStr()
{
    return "aa";
}

//外部函数
int add(int i, int j)
{
    return i+j;
}
