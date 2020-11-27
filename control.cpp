
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

bool Control::reduceAPushButton(QString name){
    QPushButton nPushButton(name);
    nPushButton.setParent(&w);
    nPushButton.setGeometry(QRect(100,100,100,100));

    return true;
}

bool Control::deleteAButton(){return true;}

bool Control::initial(){return true;}
