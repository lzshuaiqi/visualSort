#ifndef TONG_H
#define TONG_H
#include<iostream>
#include<QTime>
using namespace std;

class Tong{
public:
    Tong(){
        shu=0;
        used=0;
        x=0;
    }
private:
    friend class Widget;
    int num[40];
    int x;
    int shu;
    bool used;
};
#endif // TONG_H
