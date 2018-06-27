#include "databutton.h"

DataButton::DataButton()
{

}

DataButton::DataButton(QWidget *parent,int interval,int i,int width)
    :QPushButton(parent)
{
    int h=rand()%630+20;
    this->setGeometry(250+interval*i,800-h,width,h);
    this->setStyleSheet("background-color:rgb(128,0,128);");
}

void DataButton::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void DataButton::higher()
{
    int h=(this->height()+10)%630+20;
    this->setStyleSheet("background-color:rgb(255,255,255);");
    this->setGeometry(this->x(),800-h,this->width(),h);
    sleep(100);
    this->setStyleSheet("background-color:rgb(128,0,128);");
}


void DataButton::setRed()
{
    this->setStyleSheet("background-color:rgb(255,0,0);");
}

void DataButton::setOrange()
{
    this->setStyleSheet("background-color:rgb(255,165,0);");   
}

void DataButton::setYellow()
{
    this->setStyleSheet("background-color:rgb(255,255,0);");      
}

void DataButton::setGreen()
{
    this->setStyleSheet("background-color:rgb(0,255,0);");         
}

void DataButton::setCyan()
{
    this->setStyleSheet("background-color:rgb(0,127,255);");            
}

void DataButton::setBlue()
{
    this->setStyleSheet("background-color:rgb(139,0,255);");   
}

void DataButton::setWhite()
{
    this->setStyleSheet("background-color:rgb(255,255,255);");         
}

void DataButton::setPurple()
{
    this->setStyleSheet("background-color:rgb(128,0,128);");
}
