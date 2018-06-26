#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>


class Counter : public QObject
{
    Q_OBJECT

private:
    int counter;

signals:
    void onChange(int);

private slots:
    void increment(){
        emit onChange(++counter);
    }

public:
    Counter() : QObject{}, counter(0){}
    int getCounter(){ return counter; }
};

#endif // COUNTER_H
