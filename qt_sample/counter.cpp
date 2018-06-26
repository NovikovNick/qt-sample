#include "counter.h"

#include <QObject>


class Counter : public QObject
{
    Q_OBJECT

private:
    int counter;

signals:
    void onChange(int value);

public slots:
    void increment(){
        emit onChange(++counter);
    }

public:
    Counter(){ counter = 0;}
    int getCounter() const { return counter; }
};
