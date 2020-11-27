
#include "control.h"

#include <QApplication>

#include <QScreen>

//QList<QScreen *> list_screen = QGuiApplication::screens();
//    QRect rect = list_screen.at(0)->geometry();
Control::Control(QWidget *w):w(w){
    QList<QScreen *> list_screen = QGuiApplication::screens();
    QRect rect = list_screen.at(0)->geometry();
    high=rect.height();
    width=rect.width();
}

Control::~Control(){
    buttonArray.clear();
}

//2020/11/27 无法解决生命周期的问题
//bool Control::reduceAPushButton(QString name){
//    QPushButton nPushButton(name);
//    nPushButton.setParent(&w);
//    nPushButton.setGeometry(300,300,200,500);
//    nPushButton.show();
//    return true;
//}

bool Control::deleteAButton(){return true;}

bool Control::initial(){return true;}
