#include "baseboard.h"
#include <QApplication>
#include <QScreen>

#include <iostream>

using namespace std;


//关于第一层容器的构造函数
BaseBoard::BaseBoard(QWidget* parent):QWidget(parent),m_bMoving(false){
    //设置背景
    buttonArry = new QButtonGroup(this);
    //关闭程序后不会弹出消息框
    QApplication::setQuitOnLastWindowClosed(true);
    //获取屏幕宽高
    QList<QScreen *> list_screen = QGuiApplication::screens();
    QRect rect = list_screen.at(0)->geometry();
    height=rect.height();
    width=rect.width();
    //初始化buttonName字典
    buttonNames = {
      "ESC","`","1","2","3","4","5","6","7","8","9","0","-","=","BACKSPACE",
        "TAB","q","w","e","r","t","y","u","i","o","p","[","]","\\","DEL",
        "CapsLock","a","s","d","f","g","h","j","k","l",";","'","Enter",
        "Shift","z","x","c","v","b","n","m",",",".","/","↑","Shift",
        "Fn","Ctrl","Win","Alt","中","Space","Alt","Ctrl","←","↓","→","关闭键盘"
    };



}
void BaseBoard::display(){
    this->show();
}
void BaseBoard::hidden(){
    this->hide();
}

void BaseBoard::onclick(QSystemTrayIcon::ActivationReason reson){
    if(reson == QSystemTrayIcon::Trigger){
        cout<<"C++";
        this->show();
    }
}

bool BaseBoard::makeAPushButton(QString name,QRect pointer,int id){
    QPushButton* nPButton = new QPushButton(name,this);
    nPButton->setGeometry(pointer);
    nPButton->show();
    QString style = QString("QPushButton{color: white;font-size:%1px;background:rgba(160,160,160,0.2)}"
                            "QPushButton:hover{background:rgba(203,234,255,0.7);color:black}"
                            "QPushButton:pressed{background:rgba(203,234,255,0.7)}").arg(width*0.0125);
    nPButton->setStyleSheet(style);
    buttonArry->addButton(nPButton,id);
    return true;
}

bool BaseBoard::makeAFuncPushButton(QString name, QRect pointer,int id){
    QPushButton* nPButton = new QPushButton(name,this);
    nPButton->setGeometry(pointer);
    nPButton->setCheckable(true);
    nPButton->setAutoExclusive(true);
    nPButton->show();
    QString style = QString("QPushButton{color: white;font-size:%1px;background:rgba(160,160,160,0.2)}"
                            "QPushButton:pressed,QPushButton:checked{background:rgba(124,239,255,0.4)}").arg(width*0.0125);
    nPButton->setStyleSheet(style);
    buttonArry->addButton(nPButton,id);
    return true;
};

BaseBoard::~BaseBoard(){}

bool BaseBoard::basicLayout(){
    int const unit   = width/16.2;
    int const margin = unit*0.05;
    int const hei  = height/12;
    int id     = 1;//button的id
    int length = 0;
    int index  = 0;//buttonName的指针
    //this is the first line pain
    for (int i=0;i<14;i++) {
        makeAPushButton(buttonNames[index],QRect(length,hei,unit,hei-margin),id);
        id++;
        length = length + unit + margin;
        index++;
    }
    makeAPushButton(buttonNames[index],QRect(length,hei,width-length,hei-margin),id);
    index++;length=0;id++;

    //this in the second pain fuck c++
    makeAPushButton(buttonNames[index],QRect(length,2*hei,1.5*unit,hei-margin),id);
    index++;length=length + 1.5*unit + margin;id++;
    for(int i=0;i<13;i++){
        makeAPushButton(buttonNames[index],QRect(length,2*hei,unit,hei-margin),id);
        id++;
        length = length + unit + margin;
        index++;
    }
    makeAPushButton(buttonNames[index],QRect(length,2*hei,width-length,hei-margin),id);
    index++;length=0;id++;

    //start third pain
    makeAFuncPushButton(buttonNames[index],QRect(length,3*hei,2*unit,hei-margin),id);
    index++;length=length + 2*unit + margin;id++;
    for(int i=0;i<11;i++){
        makeAPushButton(buttonNames[index],QRect(length,3*hei,unit,hei-margin),id);
        id++;
        length = length + unit + margin;
        index++;
    }
    makeAPushButton(buttonNames[index],QRect(length,3*hei,width-length,hei-margin),id);
    index++;length=0;id++;

    //this is forth pain
    makeAFuncPushButton(buttonNames[index],QRect(length,4*hei,2.5*unit,hei-margin),id);
    index++;length=length + 2.5*unit + margin;id++;
    for(int i=0;i<11;i++){
        makeAPushButton(buttonNames[index],QRect(length,4*hei,unit,hei-margin),id);
        id++;
        length = length + unit + margin;
        index++;
    }
    makeAFuncPushButton(buttonNames[index],QRect(length,4*hei,width-length,hei-margin),id);
    index++;length=0;id++;

    //this is most pain
    for (int i = 0;i<4;i++) {//最后一行前四个功能按钮
        makeAFuncPushButton(buttonNames[index],QRect(length,5*hei,unit,hei-margin),id);
        id++;
        length = length + unit + margin;
        index++;
    }
    makeAPushButton(buttonNames[index],QRect(length,5*hei,unit,hei-margin),id);
    index++;length=length + unit + margin;id++;
    makeAPushButton(buttonNames[index],QRect(length,5*hei,4.5*unit+margin*2,hei-margin),id);
    index++;length=length + 4.5*unit + margin*3;id++;
    makeAFuncPushButton(buttonNames[index],QRect(length,5*hei,unit,hei-margin),id);
    index++;length=length + unit + margin;id++;
    makeAFuncPushButton(buttonNames[index],QRect(length,5*hei,unit,hei-margin),id);
    index++;length=length + unit + margin;id++;
    for (int i = 0;i<3;i++) {
        makeAPushButton(buttonNames[index],QRect(length,5*hei,unit,hei-margin),id);
        id++;
        length = length + unit + margin;
        index++;
    }
    makeAPushButton(buttonNames[index],QRect(length,5*hei,width-length,hei-margin),id);
    return true;
}


int BaseBoard::initialze(){
    basicLayout();
    return 0;
}


