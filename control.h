#ifndef LAYOUT_H
#define LAYOUT_H

#include <vector>
#include <QPushButton>

#include "widg.h"

//控件管理类
class Control{
public:
    Control(BaseBoard &); //!!!!!
    ~Control();
    bool reduceAButton();//生产一个按钮
    bool deleteAButton();//删除一个按钮
    bool initial();//初始化键盘
private:
    BaseBoard w;
    int size=4;     //行
    std::vector<std::vector<QPushButton>> buttonArray;
};


#endif // LAYOUT_H
