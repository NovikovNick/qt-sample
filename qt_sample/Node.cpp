#include "Node.h"

Node::Node(QObject *parent) : QObject(parent), x(0), y(0), width(0), height(0){}

void Node::increment(){
    emit onChange(++x);
}

