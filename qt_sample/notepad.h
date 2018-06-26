#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(bool customProp READ getCustomProp WRITE setCustomProp DESIGNABLE true) //doesn't work... why?

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();

    void setCustomProp(bool customProp);
    bool getCustomProp();

private slots:
    void on_actionaction1_triggered();

private:
    Ui::Notepad *ui;
    bool customProp;
};

#endif // NOTEPAD_H
