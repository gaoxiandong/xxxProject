#include "logutil.h"
#include <QTextStream>
#include <QCoreApplication>
#include <QTime>
#include <QDebug>
#include <QSettings>
static QFile logfile;
LogUtil::LogUtil(QObject *parent) : QObject(parent)
{

}

void LogUtil::myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type);
    Q_UNUSED(context);
    if (logfile.isOpen())
    {
        QTextStream out(&logfile);
        out <<"["<<QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")<<"]";
        switch(type)
        {
        case QtDebugMsg:
            out<<"[Debug]";
            break;
        case QtWarningMsg:
            out<<"[Warning]";
            break;
        case QtCriticalMsg:
            out<<"[Critical]";
            break;
        case QtFatalMsg:
            out<<"[Fatal]";
            break;
        case QtInfoMsg:
            out<<"[Info]";
            break;
        default:
            out<<"[Unknow]";
            break;
        }
        out<< msg<<"\n";
        out.flush();//add by gxd
    }
}

void LogUtil::enableLog()
{
    QString strAppPath = QCoreApplication::applicationDirPath();
    QString strLogFile = strAppPath + "/applog.txt";
    QFile orilogfile(strLogFile);
    if (orilogfile.open(QIODevice::ReadOnly))
    {
        if(orilogfile.size()>logmaxsize)
        {
            orilogfile.rename("applog"+QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss")+".txt");
        }
        orilogfile.close();
    }
    logfile.setFileName(strLogFile);
    if (logfile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
    {
        qInstallMessageHandler(myMessageOutput);
    }
    else
    {
        qDebug()<<"open log file fail";
    }
}

void LogUtil::openLog()
{
    QString appDir = QCoreApplication::applicationDirPath();
    QString configPath = appDir.append("/Options.ini");
    QSettings config(configPath, QSettings::IniFormat);
    int logflag=config.value("InitOption/EnLog").toInt();
    if(1==logflag)
        enableLog();
}
