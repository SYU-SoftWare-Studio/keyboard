#include "baseboard.h"
#include <QApplication>
#include <QScreen>

#include <iostream>

using namespace std;


//关于第一层容器的构造函数
BaseBoard::BaseBoard(QWidget* parent):QWidget(parent),m_bMoving(false){
    //设置背景
    buttonArry = new QButtonGroup(this);
    QPalette palette;
    palette.setColor(QPalette::Background, Qt::white);
    setPalette(palette);
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
        "Fn","Ctrl","Win","Alt","中","Space","Alt","Ctrl","←","↓","→"
    };
}
void BaseBoard::display(){
    this->show();
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
    QString style = QString("color: black;font-size:%1px").arg(width*0.0125);
    nPButton->setStyleSheet(style);
    buttonArry->addButton(nPButton,id);
    return true;
}

bool BaseBoard::makeAFuncPushButton(QString name, QRect pointer,int id){
    QPushButton* nPButton = new QPushButton(name,this);
    nPButton->setGeometry(pointer);
    nPButton->setCheckable(true);
//    nPButton->setChecked(true);//只能设置一个
    nPButton->setAutoExclusive(true);
    nPButton->show();
    buttonArry->addButton(nPButton,id);
    return true;
};

BaseBoard::~BaseBoard(){}



int BaseBoard::initialze(){
    int id     = 1;
    int length = 0;
    int index  = 0;
    int const hei  = height/12;
    int const unit = width/32;
    for (int i=0;i<14;i++) {
        makeAPushButton(buttonNames[index],QRect(length,hei*1.05,2*unit,0.95*hei),id);
        id++;
        length = length + 2.08*unit;
        index++;
    }

    return 0;

}


