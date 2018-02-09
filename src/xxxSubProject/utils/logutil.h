#ifndef LOGUTIL_H
#define LOGUTIL_H

#include <QObject>
#include <QFile>
const int logmaxsize=1024*1024*10;

class LogUtil : public QObject
{
    Q_OBJECT
public:
    static LogUtil* getInstance(){
        static LogUtil ins;
        return &ins;
    }
    void openLog();
signals:
public slots:
private:

    LogUtil(QObject *parent = nullptr);
    static void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    static void enableLog();

private:
    //static QFile* file;
};

#endif // LOGUTIL_H
