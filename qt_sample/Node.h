#ifndef NODE_H
#define NODE_H

#include <QObject>

class Node : public QObject{

    Q_OBJECT

private:
    int x, y, width, height;


public:
    explicit Node(QObject *parent = nullptr);

signals:
    void onChange(int);

public slots:
    void increment();
};

#endif // NODE_H
