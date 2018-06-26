#include "notepad.h"
#include <QtWidgets>
#include "qlogging.h"
#include "Counter.h"
#include "Node.h"
#include <iostream>

#include <QtGlobal>
#include <QTextStream>

// Умный указатель на файл логирования
QScopedPointer<QFile>   m_logFile;

void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg){

    QTextStream ts(m_logFile.data());
    QString txt;
    QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");

    switch (type) {
    case QtDebugMsg:
        txt = QString("%1:[DEBUG]: %2").arg(date, msg);
        break;
    case QtWarningMsg:
        txt = QString("%1:[WARN]: %2").arg(date, msg);
        break;
    case QtCriticalMsg:
        txt = QString("%1:[CRITICAL]: %2").arg(date, msg);
        break;
    case QtFatalMsg:
        txt = QString("%1:[FATAL]: %2").arg(date, msg);
    }

    std::cout << txt.toStdString() << std::endl;
    ts << txt << endl;
    ts.flush();
}

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    m_logFile.reset(new QFile("/home/nicknovikov/WORKSPACE/cpp/qt_sample/log.txt"));
    m_logFile.data()->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(messageHandler);

    //Notepad w;
    //w.show();

    QLabel label("0");
    QPushButton cmd("ADD");
    Counter* counter = new Counter();

    Node* node = new Node();

    QList<QWidget*> list;
    list << &label << &cmd;

    for(QWidget* w : list){
        w->show();
    }



    QObject::connect(&cmd, SIGNAL(clicked()), node, SLOT(increment()));

    QObject::connect(&cmd, SIGNAL(clicked()), counter, SLOT(increment()));
    QObject::connect(counter, SIGNAL(onChange(int)), &label, SLOT(setNum(int)));
    QObject::connect(counter, SIGNAL(full()), &app, SLOT(quit()));

    return app.exec();
}
