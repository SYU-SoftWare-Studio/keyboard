#include "mybutton.h"

#include <QtDebug>

myCloseButton::myCloseButton(QString name,QWidget *parent,int id):
    QPushButton(name,parent),id(id){
    connect(this,SIGNAL(clicked()),parent,SLOT(hidden()));

}


myCloseButton::~myCloseButton(){

}



myOutputButton::myOutputButton(QString name,QWidget *parent,int id):
    QPushButton(name,parent),id(id){

}


//void myOutputButton::changeFunByTab(){

//};

myOutputButton::~myOutputButton(){}
