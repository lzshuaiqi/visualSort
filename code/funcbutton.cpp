#include"funcbutton.h"
#include"widget.h"

FuncButton::FuncButton(QWidget *parent)
	:QPushButton(parent)
{
    //字体
    QFont font;
    font.setPointSize(30);
	this->setStyleSheet("border:2px groove white;border-radius:10px;color:rgb(255,255,255);");
    this->setFont(font);
    this->setCursor(Qt::PointingHandCursor);
}

void FuncButton::enterEvent(QEvent* e)
{
    setStyleSheet("QPushButton{background: white;}");
}
void FuncButton::leaveEvent(QEvent* e)
{
    setStyleSheet("border:2px groove white;border-radius:10px;color:rgb(255,255,255);");
}

void FuncButton::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

