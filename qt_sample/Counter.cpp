#include "Counter.h"
#include <QtCore/qdebug.h>

Counter::Counter(QObject *parent) : QObject(parent), value(0)
{

}

void Counter::increment(){


    qDebug() << " increment ";

    if(++value > 5){
        emit full();
    }else{
        emit onChange(value);
    }
}
