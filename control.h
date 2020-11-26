#ifndef LAYOUT_H
#define LAYOUT_H

#include <vector>
#include <QPushButton>
//控件管理类
class Control{
public:
    Control();
    ~Control();
    bool reduceAButton();//生产一个按钮
    bool deleteAButton();//删除一个按钮
    bool initial();//初始化键盘
private:
    int size=4;
    std::vector<std::vector<QPushButton>> buttonArray;
};


#endif // LAYOUT_H
