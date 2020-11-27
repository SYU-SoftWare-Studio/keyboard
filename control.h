#ifndef LAYOUT_H
#define LAYOUT_H

#include <vector>

#include <QRect>
#include <QRadioButton>
#include <QPushButton>

#include "baseboard.h"

//控件管理类
class Control{
public:
    Control(QWidget *); //传入baseboard的对象用于在其上操作
    ~Control();
    bool reduceAPushButton(QString);//生产一个push按钮
    bool reduceARadioButton(QRect,QRect);//生产一个radio按钮
    bool deleteAButton();//删除一个按钮
    bool initial();//初始化键盘
private:
    QWidget w;
    int high;
    int width;
    int size=4;     //行
    std::vector<std::vector<QPushButton*>> buttonArray;
};


#endif // LAYOUT_H
