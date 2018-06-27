#ifndef DATABUTTON_H
#define DATABUTTON_H
#include <QWidget>
#include<QPushButton>
#include<QTime>
#include<QApplication>
#include <QPropertyAnimation>


class DataButton : public QPushButton
{
public:
    DataButton();
    DataButton(QWidget *parent, int flag, int i, int width);
    void sleep(unsigned int msec);
    void higher();
    void setRed();
    void setOrange();
    void setYellow();
    void setGreen();
    void setCyan();
    void setBlue();
    void setWhite();
    void setPurple();

};

#endif // DATABUTTON_H
