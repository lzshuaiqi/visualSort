#include<QTime>
#include<QPushButton>
#include<QApplication>
#include <QPropertyAnimation>
#include "widget.h"
#include<QString>

bool Widget::lock=0;
bool Widget::stop=0;
bool Widget::quit=0;
int Widget::flag=0;
int Widget::num=20;
int Widget::width=40;
int Widget::interval=60;
void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

Widget::Widget(QWidget *parent)
   :QWidget(parent)
{
    setWindowTitle("排序可视化");
    resize(QSize(1920,1080));

    for(int i=0;i<60;i++)
    {
        data[i]=NULL;
    }
    for(int i=0;i<700;i++)
    {
        tong[i]=NULL;
    }


    showFullScreen();

    //生成数据
    random=new FuncButton(this);
    random->setGeometry(1600,250,200,100);
    random->setText("随机生成");

    connect(random,&QPushButton::clicked,this,&Widget::randomF);
    random->show();

    //结束程序
    done=new FuncButton(this);
    done->setGeometry(1600,50,200,100);
    done->setText(" 关 闭 ");


    connect(done,&QPushButton::clicked,this,&Widget::doneF);
    done->show();

    //暂停按钮
    zanting=new FuncButton(this);
    zanting->setGeometry(1600,450,200,100);
    zanting->setText(" 暂 停 ");

    connect(zanting,&QPushButton::clicked,this,&Widget::zantingF);
    zanting->hide();

    //开始按钮
    kaishi=new FuncButton(this);
    kaishi->setGeometry(1600,450,100,100);
    kaishi->setText("继续");

    connect(kaishi,&QPushButton::clicked,this,&Widget::kaishiF);
    kaishi->hide();

    //退出按钮
    exit=new FuncButton(this);
    exit->setGeometry(1700,450,100,100);
    exit->setText("退出");


    connect(exit,&QPushButton::clicked,this,&Widget::exitF);
    exit->hide();

    //改变数据量
    change=new FuncButton(this);
    change->setGeometry(1600,650,200,100);
    change->setText(" 改变数量 ");

    connect(change,&QPushButton::clicked,this,&Widget::changeF);
    change->hide();

    //冒泡按钮
    mao=new FuncButton(this);
    mao->setGeometry(120,840,200,80);
    mao->setText("冒泡排序");


    connect(mao,&QPushButton::clicked,this,&Widget::bubbleSort);
    mao->hide();

    //选择按钮
    xua=new FuncButton(this);
    xua->setGeometry(435,840,200,80);
    xua->setText("选择排序");


    connect(xua,&QPushButton::clicked,this,&Widget::selectionSort);
    xua->hide();

    //快排按钮
    qui=new FuncButton(this);
    qui->setGeometry(750,840,200,80);
    qui->setText("快速排序");


    connect(qui,&QPushButton::clicked,this,&Widget::startqui);
    qui->hide();

    //桶排按钮
    ton=new FuncButton(this);
    ton->setGeometry(1065,840,200,80);
    ton->setText("桶排序");


    connect(ton,&QPushButton::clicked,this,&Widget::countingSort);
    ton->hide();

    //希尔按钮
    xier=new FuncButton(this);
    xier->setGeometry(1380,840,200,80);
    xier->setText("希尔排序");


    connect(xier,&QPushButton::clicked,this,&Widget::shellSort);
    xier->hide();

    //归并按钮
    gui=new FuncButton(this);
    gui->setGeometry(120,960,200,80);
    gui->setText("归并排序");


    connect(gui,&QPushButton::clicked,this,&Widget::mergeSort);
    gui->hide();

    //插入按钮
    cha=new FuncButton(this);
    cha->setGeometry(435,960,200,80);
    cha->setText("插入排序");


    connect(cha,&QPushButton::clicked,this,&Widget::insectionSort);
    cha->hide();

    //猴子anniu
    bogo = new FuncButton(this);
    bogo->setGeometry(750,960,200,80);
    bogo->setText("猴子排序");

    connect(bogo,&QPushButton::clicked,this,&Widget::bogoSort);
    bogo->hide();
}

void Widget::randomF()
{
    if(lock==1)
    {

    }
    else
    {
        lock=1;
    zanting->show();
    mao->show();
    xua->show();
    qui->show();
    ton->show();
    xier->show();
    change->show();
    gui->show();
    cha->show();
    bogo->show();
        for(int i=0;i<num;i++)
        {
            delete data[i];
            data[i]=new DataButton(this,interval,i,width);
            connect(data[i],&DataButton::clicked,this,&Widget::Lengthen);
            data[i]->show();
        }
        lock=0;
    }
}

void Widget::doneF()
{
    close();
}

void Widget::Lengthen()
{
    if(lock==1)
    {

    }
    else
    {
        lock=1;
        DataButton *it=(DataButton*)sender();
        it->higher();
        lock=0;
    }
}

void Widget::zantingF()
{
    stop=1;
    zanting->hide();
    kaishi->show();
    exit->show();
}

void Widget::kaishiF()
{
    stop=0;
    kaishi->hide();
    exit->hide();
    zanting->show();
}

void Widget::exitF()
{
    quit=1;
    kaishi->hide();
    exit->hide();
    zanting->show();
}

void Widget::changeF()
{
    if(lock!=1)
    {
        if(flag==0)
        {
            num=60;
            width=20;
            interval=20;
            flag=1;
        }
        else
        {
            num=20;
            for(int i=20;i<60;i++)
            {
                delete data[i];
                data[i]=NULL;
            }
            width=40;
            interval=60;
            flag=0;
        }

        for(int i=0;i<num;i++)
        {
            delete data[i];
            data[i]=new DataButton(this,interval,i,width);
            connect(data[i],&DataButton::clicked,this,&Widget::Lengthen);
            data[i]->show();
        }
    }
}



//猴子排序
void Widget::bogoSort()
{
    if(lock==1)
    {

    }
    else
    {
        lock=1;

        int i,j;
        while(1)
        {
            i = rand()%num;
            j = rand()%num;
            bool isordered=1;
            for(int yy = 0;yy < num - 1;yy++)
            {
                if(data[yy]->height()>data[yy+1]->height())
                {
                    isordered = 0;
                    break;
                }
            }
            if(isordered)
                break;
            int tmp = max(i,j);
            j = min(i,j);
            i = tmp;

                data[i]->setStyleSheet("background-color:rgb(255,255,255);");
                data[j]->setStyleSheet("background-color:rgb(255,255,255);");
                //sleep(500);
                if(data[j]->height() > data[i]->height())
                {
                    if(num==20)
                    {
                        int x0,x1;
                        DataButton *t=NULL;
                        x0=data[j]->x();
                        x1=data[i]->x();
                        QPropertyAnimation *animation1=new QPropertyAnimation(data[j],"geometry");
                        animation1->setDuration(200);
                        animation1->setStartValue(QRect(data[j]->x(),data[j]->y(),data[j]->width(),data[j]->height()));
                        animation1->setEndValue(QRect(x1,data[j]->y(),data[j]->width(),data[j]->height()));
                        animation1->start();
                        QPropertyAnimation *animation2=new QPropertyAnimation(data[i],"geometry");
                        animation2->setDuration(200);
                        animation2->setStartValue(QRect(data[i]->x(),data[i]->y(),data[i]->width(),data[i]->height()));
                        animation2->setEndValue(QRect(x0,data[i]->y(),data[i]->width(),data[i]->height()));
                        animation2->start();
                        t=data[j];
                        data[j]=data[i];
                        data[i]=t;
                        sleep(250);//300 100
                    }
                    else
                    {
                        int t,s;
                        data[j]->setStyleSheet("background-color:rgb(255,255,255);");
                        data[i]->setStyleSheet("background-color:rgb(255,255,255);");
                        t=data[j]->height();
                        s=data[i]->height();
                        data[j]->setGeometry(data[j]->x(),800-s,data[j]->width(),s);
                        data[i]->setGeometry(data[i]->x(),800-t,data[i]->width(),t);
                        sleep(20);
                    }
                }
                else
                {
                    if(num==20)
                    {
                        sleep(100);
                    }
                    else
                    {
                        sleep(20);
                    }
                }
                while(stop==1)
                {
                    if(quit==1)
                    {
                        quit=0;
                        lock=0;
                        stop=0;
                        data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                        data[i]->setStyleSheet("background-color:rgb(128,0,128);");
                        return;
                    }
                    else
                    {
                        sleep(100);
                    }
                }
                data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                data[i]->setStyleSheet("background-color:rgb(128,0,128);");
            }
        lock=0;
    }
}


void Widget::merge(int left, int mid, int right)
{
    while(stop==1)
            {
                if(quit==1)
                {

                    return;
                }
                else
                {
                    sleep(100);
                }
            }
    if(lock==1)
    {

    }
    else
    {
        lock=1;
    DataButton* tmp[right - left + 1];
    int i = left, j = mid, k = 0;
    int x0 = data[left]->x();


    while(i < mid && j<= right)
    {
        while(stop==1)
                {
                    if(quit==1)
                    {

                        return;
                    }
                    else
                    {
                        sleep(100);
                    }
                }

        if(data[i]->height() < data[j]->height())
        {
            data[i]->setWhite();
            QPropertyAnimation *animation1=new QPropertyAnimation(data[i],"geometry");
            animation1->setDuration(180);
            animation1->setStartValue(QRect(data[i]->x(),data[i]->y(),data[i]->width(),data[i]->height()));
            animation1->setEndValue(QRect(x0 + k*interval,data[i]->y()-100,data[i]->width(),data[i]->height()));
            animation1->start();
            tmp[k] = data[i];
            k++;
            i++;
            sleep(200);
        }
        else
        {
            data[j]->setWhite();
            QPropertyAnimation *animation2=new QPropertyAnimation(data[j],"geometry");
            animation2->setDuration(180);
            animation2->setStartValue(QRect(data[j]->x(),data[j]->y(),data[j]->width(),data[j]->height()));
            animation2->setEndValue(QRect(x0 + k*interval,data[j]->y()-100,data[j]->width(),data[j]->height()));
            animation2->start();
            tmp[k] =data[j];
            k++;
            j++;
            sleep(200);
        }
    }
    while(i<mid)
    {
        while(stop==1)
                {
                    if(quit==1)
                    {

                        return;
                    }
                    else
                    {
                        sleep(100);
                    }
                }
        data[i]->setWhite();
        QPropertyAnimation *animation1=new QPropertyAnimation(data[i],"geometry");
        animation1->setDuration(180);
        animation1->setStartValue(QRect(data[i]->x(),data[i]->y(),data[i]->width(),data[i]->height()));
        animation1->setEndValue(QRect(x0 + k*interval,data[i]->y()-100,data[i]->width(),data[i]->height()));
        animation1->start();
        tmp[k] = data[i];
        k++;
        i++;
        sleep(200);
    }
    while(j <= right)
    {
        while(stop==1)
                {
                    if(quit==1)
                    {

                        return;
                    }
                    else
                    {
                        sleep(100);
                    }
                }
        data[j]->setWhite();
        QPropertyAnimation *animation2=new QPropertyAnimation(data[j],"geometry");
        animation2->setDuration(180);
        animation2->setStartValue(QRect(data[j]->x(),data[j]->y(),data[j]->width(),data[j]->height()));
        animation2->setEndValue(QRect(x0 + k*interval,data[j]->y()-100,data[j]->width(),data[j]->height()));
        animation2->start();
        tmp[k] = data[j];
        k++;
        j++;
        sleep(200);
    }

    for(int k = 0;k < right - left + 1;k++)
    {
        while(stop==1)
                {
                    if(quit==1)
                    {

                        return;
                    }
                    else
                    {
                        sleep(100);
                    }
                }
        data[left + k] = tmp[k];
    }

    for(int k = left;k <= right;k++)
    {
        while(stop==1)
                {
                    if(quit==1)
                    {

                        return;
                    }
                    else
                    {
                        sleep(100);
                    }
                }

        QPropertyAnimation *animation3=new QPropertyAnimation(data[k],"geometry");
        animation3->setDuration(170);
        animation3->setStartValue(QRect(data[k]->x(),data[k]->y(),data[k]->width(),data[k]->height()));
        animation3->setEndValue(QRect(data[k]->x(),data[k]->y() + 100,data[k]->width(),data[k]->height()));
        animation3->start();
        data[k]->setPurple();
        sleep(100);
    }
    sleep(200);
    lock=0;
    }
   // delete[] tmp;
}

void Widget::mergeSort1(int left, int right)
{
    if(quit == 1)
    {
        quit=0;
        lock=0;
        stop=0;
        randomF();
        return;

    }
    if(lock==1)
    {

    }
    else
    {
    int mid = (left + right) / 2;
    if(left == right)
        return ;

    mergeSort1(left , mid);
    if(quit == 1)
    {
        quit=0;
        lock=0;
        stop=0;
        randomF();
        return;

    }
    mergeSort1(mid + 1, right);
    if(quit == 1)
    {
        quit=0;
        lock=0;
        stop=0;
        randomF();
        return;

    }
    merge(left, mid + 1, right);

    }
}

// void Widget::mergeSort2(int left, int right)
// {
//     int i=0;
// }



void Widget::mergeSort()
{
    //if(num > 0)
    //{
        //填上五颜六色
        //for(int i = 0;i < 20;i++)
       // {
        //    data[i]->setStyleSheet("background-color:rgb(64*i mod 255,131*i mod 255,212*i mod 255);");
        //}
        mergeSort1(0, num - 1);
    //}
    // else 
    // {
    //     //填色
    //     mergeSort2(0, 60);
    // }

}


//冒泡排序
void Widget::bubbleSort()
{
    if(lock==1)
    {

    }
    else
    {
        lock=1;
        int x0,x1;
        for(int i=num;i>1;i--){
            for(int j=0;j<i-1;j++){
                data[j]->setStyleSheet("background-color:rgb(255,255,255);");
                if(data[j]->height() > data[j+1]->height())
                {
                    if(num==20)
                    {
                        data[j+1]->setStyleSheet("background-color:rgb(255,255,255);");
                        DataButton *t=NULL;
                        x0=data[j]->x();
                        x1=data[j+1]->x();
                        QPropertyAnimation *animation1=new QPropertyAnimation(data[j],"geometry");
                        animation1->setDuration(200);
                        animation1->setStartValue(QRect(data[j]->x(),data[j]->y(),data[j]->width(),data[j]->height()));
                        animation1->setEndValue(QRect(x1,data[j]->y(),data[j]->width(),data[j]->height()));
                        animation1->start();
                        QPropertyAnimation *animation2=new QPropertyAnimation(data[j+1],"geometry");
                        animation2->setDuration(200);
                        animation2->setStartValue(QRect(data[j+1]->x(),data[j+1]->y(),data[j+1]->width(),data[j+1]->height()));
                        animation2->setEndValue(QRect(x0,data[j+1]->y(),data[j+1]->width(),data[j+1]->height()));
                        animation2->start();
                        t=data[j];
                        data[j]=data[j+1];
                        data[j+1]=t;
                        sleep(250);//300 100
                    }
                    else
                    {
                        int t,s;
                        data[j]->setStyleSheet("background-color:rgb(255,255,255);");
                        data[j+1]->setStyleSheet("background-color:rgb(255,255,255);");
                        t=data[j]->height();
                        s=data[j+1]->height();
                        data[j]->setGeometry(data[j]->x(),800-s,data[j]->width(),s);
                        data[j+1]->setGeometry(data[j+1]->x(),800-t,data[j+1]->width(),t);
                        sleep(20);
                    }
                }
                else
                {
                    if(num==20)
                    {
                        sleep(100);
                    }
                    else
                    {
                        sleep(20);
                    }
                }
                while(stop==1)
                {
                    if(quit==1)
                    {
                        quit=0;
                        lock=0;
                        stop=0;
                        data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                        data[j+1]->setStyleSheet("background-color:rgb(128,0,128);");
                        return;
                    }
                    else
                    {
                        sleep(100);
                    }
                }
                data[j]->setStyleSheet("background-color:rgb(128,0,128);");
            }
            data[i-1]->setStyleSheet("background-color:rgb(128,0,128);");
        }
        lock=0;
    }
}

void Widget::selectionSort()
{
    if(lock==1)
    {

    }
    else
    {
        lock=1;
        int k;
        for(int i=num-1;i>=1;i--){
            k=i;
            for(int j=i-1;j>=0;j--){ 
                data[j]->setStyleSheet("background-color:rgb(255,255,255);");
                while(stop==1)
                {
                    if(quit==1)
                    {
                        quit=0;
                        lock=0;
                        stop=0;
                        data[i]->setStyleSheet("background-color:rgb(128,0,128);");
                        data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                        data[j+1]->setStyleSheet("background-color:rgb(128,0,128);");
                        return;
                    }
                    else
                    {
                        sleep(100);
                    }
                }
                if(data[k]->height() < data[j]->height())
                {
                    k=j;
                }
                if(num==20)
                {
                    sleep(100);
                }
                else
                {
                    sleep(20);
                } 
                data[j]->setStyleSheet("background-color:rgb(128,0,128);");
            }
            if(k!=i)
            {
                if(num==20)
                {
                    data[k]->setStyleSheet("background-color:rgb(255,255,255);");
                    data[i]->setStyleSheet("background-color:rgb(255,255,255);");
                    DataButton *t=NULL;
                    int x0=data[k]->x();
                    int x1=data[i]->x();
                    QPropertyAnimation *animation1=new QPropertyAnimation(data[k],"geometry");
                    animation1->setDuration(200);
                    animation1->setStartValue(QRect(data[k]->x(),data[k]->y(),data[k]->width(),data[k]->height()));
                    animation1->setEndValue(QRect(x1,data[k]->y(),data[k]->width(),data[k]->height()));
                    animation1->start();
                    QPropertyAnimation *animation2=new QPropertyAnimation(data[i],"geometry");
                    animation2->setDuration(200);
                    animation2->setStartValue(QRect(data[i]->x(),data[i]->y(),data[i]->width(),data[i]->height()));
                    animation2->setEndValue(QRect(x0,data[i]->y(),data[i]->width(),data[i]->height()));
                    animation2->start();
                    t=data[k];
                    data[k]=data[i];
                    data[i]=t;
                    sleep(250);
                    data[i]->setStyleSheet("background-color:rgb(128,0,128);");
                    data[k]->setStyleSheet("background-color:rgb(128,0,128);");
                }
                else
                {
                    int t,s;
                    t=data[k]->height();
                    s=data[i]->height();
                    data[k]->setGeometry(data[k]->x(),800-s,data[k]->width(),s);
                    data[i]->setGeometry(data[i]->x(),800-t,data[i]->width(),t);
                    data[i]->setStyleSheet("background-color:rgb(255,255,255);");
                    data[k]->setStyleSheet("background-color:rgb(255,255,255);");
                    sleep(20);
                    data[i]->setStyleSheet("background-color:rgb(128,0,128);");
                    data[k]->setStyleSheet("background-color:rgb(128,0,128);");
                }
            }

        }
        lock=0;
    }
}

void Widget::startqui()
{
    if(lock==1)
    {

    }
    else
    {
        lock=1;
        quickSort(0,num);
        lock=0;
        stop=0;
        quit=0;
    }
}
void Widget::quickSort(int base,int len)
{
    int i=base,j=base+len-1;
    if(len<=1)
    {
        return ;
    }
    data[i]->setStyleSheet("background-color:rgb(255,255,255);");
    data[j]->setStyleSheet("background-color:rgb(255,255,255);");
    while(1)
    {
        while(data[j]->height()>=data[base]->height() && j!=i)
        {
            while(stop==1)
            {
                if(quit==1)
                {
                    data[i]->setStyleSheet("background-color:rgb(128,0,128);");
                    data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                    return;
                }
                else
                {
                    if(num==20)
                    {
                        sleep(100);
                    }
                    else
                    {
                        sleep(20);
                    }
                }
            }
            data[j]->setStyleSheet("background-color:rgb(128,0,128);");
            j--;
            data[j]->setStyleSheet("background-color:rgb(255,255,255);");
            if(num==20)
            {
                sleep(100);
            }
            else
            {
                sleep(20);
            }
        }
        while(data[i]->height()<=data[base]->height() && j!=i)
        {
            while(stop==1)
            {
                if(quit==1)
                {
                    data[i]->setStyleSheet("background-color:rgb(128,0,128);");
                    data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                    return;
                }
                else
                {
                    sleep(100);
                }
            }
            data[i]->setStyleSheet("background-color:rgb(128,0,128);");
            i++;
            data[i]->setStyleSheet("background-color:rgb(255,255,255);");
            if(num==20)
            {
                sleep(100);
            }
            else
            {
                sleep(20);
            }
        }
        if(i!=j)
        {
            if(num==20)
            {
                DataButton *t=NULL;
                int x0=data[j]->x();
                int x1=data[i]->x();
                QPropertyAnimation *animation1=new QPropertyAnimation(data[j],"geometry");
                animation1->setDuration(200);
                animation1->setStartValue(QRect(data[j]->x(),data[j]->y(),data[j]->width(),data[j]->height()));
                animation1->setEndValue(QRect(x1,data[j]->y(),data[j]->width(),data[j]->height()));
                animation1->start();
                QPropertyAnimation *animation2=new QPropertyAnimation(data[i],"geometry");
                animation2->setDuration(200);
                animation2->setStartValue(QRect(data[i]->x(),data[i]->y(),data[i]->width(),data[i]->height()));
                animation2->setEndValue(QRect(x0,data[i]->y(),data[i]->width(),data[i]->height()));
                animation2->start();
                t=data[j];
                data[j]=data[i];
                data[i]=t;
                sleep(250);//300 100
            }
            else
            {
                int t,s;
                t=data[j]->height();
                s=data[i]->height();
                data[j]->setGeometry(data[j]->x(),800-s,width,s);
                data[i]->setGeometry(data[i]->x(),800-t,width,t);
                sleep(20);
            }
        }
        else
        {
            data[base]->setStyleSheet("background-color:rgb(255,255,255);");
            if(num==20)
            {
                DataButton *t=NULL;
                int x0=data[base]->x();
                int x1=data[i]->x();
                QPropertyAnimation *animation1=new QPropertyAnimation(data[base],"geometry");
                animation1->setDuration(200);
                animation1->setStartValue(QRect(data[base]->x(),data[base]->y(),data[base]->width(),data[base]->height()));
                animation1->setEndValue(QRect(x1,data[base]->y(),data[base]->width(),data[base]->height()));
                animation1->start();
                QPropertyAnimation *animation2=new QPropertyAnimation(data[i],"geometry");
                animation2->setDuration(200);
                animation2->setStartValue(QRect(data[i]->x(),data[i]->y(),data[i]->width(),data[i]->height()));
                animation2->setEndValue(QRect(x0,data[i]->y(),data[i]->width(),data[i]->height()));
                animation2->start();
                t=data[base];
                data[base]=data[i];
                data[i]=t;
                sleep(250);//300 100
            }
            else
            {
                int t,s;
                t=data[base]->height();
                s=data[i]->height();
                data[base]->setGeometry(data[base]->x(),800-s,width,s);
                data[i]->setGeometry(data[i]->x(),800-t,width,t);
                sleep(20);
            }
            data[base]->setStyleSheet("background-color:rgb(128,0,128);");
            data[i]->setStyleSheet("background-color:rgb(128,0,128);");
            data[j]->setStyleSheet("background-color:rgb(128,0,128);");
            quickSort(base,i-base);
            while(stop==1)
            {
                if(quit==1)
                {
                    data[i]->setStyleSheet("background-color:rgb(128,0,128);");
                    data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                    return;
                }
                else
                {
                    sleep(100);
                }
            }
            quickSort(i+1,len+base-i-1);
            return ;
        }

    }
}

void Widget::countingSort()
{
    if(lock==1)
    {

    }
    else
    {
        lock=1;
        for(int i=0;i<700;i++)
        {
            tong[i]=new Tong;
        }
        for(int i=0;i<num;i++)
        {
            tong[data[i]->height()]->used=1;
            tong[data[i]->height()]->num[tong[data[i]->height()]->shu++]=i;     //
            data[i]->setStyleSheet("background-color:rgb(255,255,255);");
            if(num==20)
            {
                sleep(30);
            }
            else
            {
                sleep(10);
            }

        }
        int j=0;
        for(int i=0;i<700;i++)
        {
            if(tong[i]->used==1)
            {
                if(j==0)
                {
                    tong[i]->x=250;
                }
                else
                {
                    tong[i]->x=250+interval*j;
                }
                j=j+tong[i]->shu;
            }
        }
        for(int j=0;j<num;j++)
        {
            QPropertyAnimation *animation1=new QPropertyAnimation(data[j],"geometry");
            animation1->setDuration(200);
            animation1->setStartValue(QRect(data[j]->x(),data[j]->y(),data[j]->width(),data[j]->height()));
            animation1->setEndValue(QRect(tong[data[j]->height()]->x,data[j]->y()-100,data[j]->width(),data[j]->height()));
            animation1->start();
            tong[data[j]->height()]->x=tong[data[j]->height()]->x+interval;
            sleep(100);
        }
        sleep(500);
        DataButton *s[num];
        for(int j=0;j<num;j++)
        {
            s[j]=NULL;
        }
        for(int j=0;j<num;j++)
        {
            s[(data[j]->x()-250)/interval]=data[j];
        }
        for(int j=0;j<num;j++)
        {
            data[j]=s[j];
        }
        for(int j=0;j<num;j++)
        {
            QPropertyAnimation *animation1=new QPropertyAnimation(data[j],"geometry");
            animation1->setDuration(200);
            animation1->setStartValue(QRect(data[j]->x(),data[j]->y(),data[j]->width(),data[j]->height()));
            animation1->setEndValue(QRect(data[j]->x(),data[j]->y()+100,data[j]->width(),data[j]->height()));
            animation1->start();
            data[j]->setStyleSheet("background-color:rgb(128,0,128);");
            sleep(100);
        }
        lock=0;
    }
}

void Widget::shellSort()
{
    if(lock==1)
    {

    }
    else
    {
        lock=1;
        xier->setText("排序中...");
        int gap=num;
        while(gap>1)
        {
            gap=gap/3+1;
            for(int i=gap;i<num;i++)
            {
                for(int j=i;j>=gap;j-=gap)
                {
                    while(stop==1)
                    {
                        if(quit==1)
                        {
                            quit=0;
                            lock=0;
                            stop=0;
                            xier->setText("希尔排序");
                            data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                            return;
                        }
                        else
                        {
                            sleep(100);
                        }
                    }
                    data[j]->setStyleSheet("background-color:rgb(255,255,255);");
                    if(data[j]->height()<data[j-gap]->height())
                    {
                        data[j-gap]->setStyleSheet("background-color:rgb(255,255,255);");
                        if(num==20)
                        {
                            DataButton *t=data[j];
                            int x0=data[j]->x();
                            int x1=data[j-gap]->x();
                            QPropertyAnimation *animation1=new QPropertyAnimation(data[j],"geometry");
                            animation1->setDuration(200);
                            animation1->setStartValue(QRect(data[j]->x(),data[j]->y(),data[j]->width(),data[j]->height()));
                            animation1->setEndValue(QRect(x1,data[j]->y(),data[j]->width(),data[j]->height()));
                            animation1->start();
                            QPropertyAnimation *animation2=new QPropertyAnimation(data[j-gap],"geometry");
                            animation2->setDuration(200);
                            animation2->setStartValue(QRect(data[j-gap]->x(),data[j-gap]->y(),data[j-gap]->width(),data[j-gap]->height()));
                            animation2->setEndValue(QRect(x0,data[j-gap]->y(),data[j-gap]->width(),data[j-gap]->height()));
                            animation2->start();
                            data[j]=data[j-gap];
                            data[j-gap]=t;
                            sleep(250);
                        }
                        else
                        {
                            int t,s;
                            data[j]->setStyleSheet("background-color:rgb(255,255,255);");
                            data[j-gap]->setStyleSheet("background-color:rgb(255,255,255);");
                            t=data[j]->height();
                            s=data[j-gap]->height();
                            data[j]->setGeometry(data[j]->x(),800-s,data[j]->width(),s);
                            data[j-gap]->setGeometry(data[j-gap]->x(),800-t,data[j-gap]->width(),t);
                            sleep(20);
                        }
                        data[j-gap]->setStyleSheet("background-color:rgb(128,0,128);");
                        data[j]->setStyleSheet("background-color:rgb(128,0,128);");

                    }
                    else
                    {
                        data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                        if(num==20)
                        {
                            sleep(100);
                        }
                        else
                        {
                            sleep(20);
                        }
                        break;
                    }

                }
            }
        }
        xier->setText("希尔排序");
        lock=0;
    }
}


void Widget::insectionSort()
{
    if(lock==1)
    {

    }
    else
    {
        lock=1;
        int x0,x1;
        for(int i=1;i<num;i++){
            for(int j=i;j>0;j--){
                data[j]->setStyleSheet("background-color:rgb(255,255,255);");
                if(data[j]->height() < data[j-1]->height())
                {
                    if(num==20)
                    {
                        data[j-1]->setStyleSheet("background-color:rgb(255,255,255);");
                        DataButton *t=NULL;
                        x0=data[j]->x();
                        x1=data[j-1]->x();
                        QPropertyAnimation *animation1=new QPropertyAnimation(data[j],"geometry");
                        animation1->setDuration(200);
                        animation1->setStartValue(QRect(data[j]->x(),data[j]->y(),data[j]->width(),data[j]->height()));
                        animation1->setEndValue(QRect(x1,data[j]->y(),data[j]->width(),data[j]->height()));
                        animation1->start();
                        QPropertyAnimation *animation2=new QPropertyAnimation(data[j-1],"geometry");
                        animation2->setDuration(200);
                        animation2->setStartValue(QRect(data[j-1]->x(),data[j-1]->y(),data[j-1]->width(),data[j-1]->height()));
                        animation2->setEndValue(QRect(x0,data[j-1]->y(),data[j-1]->width(),data[j-1]->height()));
                        animation2->start();
                        t=data[j];
                        data[j]=data[j-1];
                        data[j-1]=t;
                        sleep(250);//300 100
                    }
                    else
                    {
                        int t,s;
                        data[j]->setStyleSheet("background-color:rgb(255,255,255);");
                        data[j-1]->setStyleSheet("background-color:rgb(255,255,255);");
                        t=data[j]->height();
                        s=data[j-1]->height();
                        data[j]->setGeometry(data[j]->x(),800-s,data[j]->width(),s);
                        data[j-1]->setGeometry(data[j-1]->x(),800-t,data[j-1]->width(),t);
                        sleep(20);
                    }
                }
                else
                {
                    if(num==20)
                    {
                        sleep(100);
                    }
                    else
                    {
                        sleep(20);
                    }
                    data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                    data[j-1]->setStyleSheet("background-color:rgb(128,0,128);");
                    break;
                }
                while(stop==1)
                {
                    if(quit==1)
                    {
                        quit=0;
                        lock=0;
                        stop=0;
                        data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                        data[j-1]->setStyleSheet("background-color:rgb(128,0,128);");
                        return;
                    }
                    else
                    {
                        sleep(100);
                    }
                }
                data[j]->setStyleSheet("background-color:rgb(128,0,128);");
                data[j-1]->setStyleSheet("background-color:rgb(128,0,128);");
            }
            data[i]->setStyleSheet("background-color:rgb(128,0,128);");
        }
        lock=0;
    }
}

Widget::~Widget()
{

}
