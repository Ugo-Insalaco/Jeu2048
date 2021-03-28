#include "mycase.h"

MyCase::MyCase(QObject *parent) : QObject(parent)
{
    val=0;
}

MyCase& MyCase::operator=(const MyCase &myCase){
    if(this != &myCase){
        val = myCase.val;
    }
    return *this;
}

QString MyCase::readValue(){
    if(val==0){
        return "";
    }
    else{
        return QString::number(val);
    }
}


int MyCase::getValue()
{
    return val;
}

void MyCase::setValue(int value){
    val = value;
}

