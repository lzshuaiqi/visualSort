#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include"databutton.h"
#include<QMouseEvent>
#include"tong.h"
#include"funcbutton.h"

class Widget : public QWidget
{
    Q_OBJECT

public:

    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    static int num;
    static int width;
    static int interval;
    static int flag;
    static bool lock;
    static bool stop;
    static bool quit;


    DataButton *data[60];
    Tong *tong[700];

    FuncButton *random;
    FuncButton *done;
    FuncButton *zanting;
    FuncButton *kaishi;
    FuncButton *exit;
    FuncButton *change;
    FuncButton *mao;
    FuncButton *xua;
    FuncButton *qui;
    FuncButton *ton;
    FuncButton *xier;
    FuncButton *gui;
    FuncButton *cha;
    FuncButton *bogo;

    void bubbleSort();
    void selectionSort();
    void startqui();
    void quickSort(int base,int len);
    void countingSort();
    void shellSort();
    void merge(int left, int mid, int right);
    void mergeSort();
    void mergeSort1(int left, int right);
   // void mergeSort2(int left, int right);
    void insectionSort();
    void bogoSort();

    void randomF();
    void doneF();
    void Lengthen();
    void zantingF();
    void exitF();
    void changeF();
    void kaishiF();
};

#endif // WIDGET_H
