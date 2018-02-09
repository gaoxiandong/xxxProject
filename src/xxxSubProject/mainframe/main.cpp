#include <QCoreApplication>
#include <QDebug>
#include "logutil.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LogUtil::getInstance()->openLog();
    qDebug()<<"hello world";
    return a.exec();
}
