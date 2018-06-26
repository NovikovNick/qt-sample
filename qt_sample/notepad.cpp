#include "notepad.h"
#include "ui_notepad.h"
#include <iostream>


Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_actionaction1_triggered()
{
    using namespace std;
    cout << sender()->objectName().toStdString() << " action" << endl;

}


void Notepad::setCustomProp(bool customProp){
    this->customProp = customProp;
}
bool Notepad::getCustomProp(){
    return this->customProp;
}
