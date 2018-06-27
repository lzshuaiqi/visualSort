#ifndef FUNCBUTTON_H
#define FUNCBUTTON_H
#include <QWidget>
#include<QPushButton>
#include<QTime>
#include<QApplication>
#include <QPropertyAnimation>


class FuncButton : public QPushButton
{
public:
    FuncButton();
    FuncButton(QWidget *parent);
    void sleep(unsigned int msec);
    void higher();
protected:
    virtual void enterEvent(QEvent* e);
    virtual void leaveEvent(QEvent* e);
};

#endif // FUNCBUTTON_H
