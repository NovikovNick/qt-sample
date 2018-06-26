#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT

private:
int value;

public:
    explicit Counter(QObject *parent = nullptr);

signals:
    void onChange(int);
    void full();

public slots:
     void increment();
};

#endif // COUNTER_H

