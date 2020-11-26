#include "widg.h"
#include <QApplication>

//关于第一层容器的构造函数
BaseBoard::BaseBoard(QWidget* parent):QWidget(parent),m_bMoving(false){
    //设置背景
    QPalette palette;
    palette.setColor(QPalette::Background, Qt::white);
    setPalette(palette);
    //关闭程序后不会弹出消息框
    QApplication::setQuitOnLastWindowClosed(false);
}

BaseBoard::~BaseBoard(){}
//int BaseBoard::initialze(){
//    return 0;
//}


