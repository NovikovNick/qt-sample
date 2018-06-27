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


    QWidget wgt;

    QLabel label(&wgt);
    label.setText("<p>Label <b style='color:red'>1</b> </p>");


    QPushButton btn1(&wgt);
    btn1.move(100, 0);
    btn1.setText("&BUTTON");

    QWidget* pwgt1 = new QWidget(&wgt);
    QPalette pal1;
    pal1.setColor(pwgt1->backgroundRole(), Qt::blue);
    pwgt1->setPalette(pal1);
    pwgt1->resize(100, 100);
    pwgt1->move(25, 25);
    pwgt1->setAutoFillBackground(true);

    QWidget* pwgt2 = new QWidget(&wgt);
    QPalette pal2;
    pal2.setBrush(pwgt1->backgroundRole(), QBrush(QPixmap(":/stone.jpg")));
    pwgt2->setPalette(pal2);
    pwgt2->setCursor(QCursor(QPixmap(":/cursor")));
    pwgt2->resize(100, 100);
    pwgt2->move(75, 75);
    pwgt2->setAutoFillBackground(true);

    wgt.resize(200, 200);
    wgt.show();



    /*
    QLabel label("0");
    QPushButton cmd("ADD");
    cmd.setGeometry(10, 10, 300, 200);
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

    */
    return app.exec();
}
