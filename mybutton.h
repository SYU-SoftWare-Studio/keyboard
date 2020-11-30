#ifndef MYBUTTON_H
#define MYBUTTON_H


#include <QPushButton>
class myCloseButton:public QPushButton
{
public:
    myCloseButton(QString name,QWidget *parent,int id);
    //void mousePressEvent(QMouseEvent *e);
    //int getMyId(){}//获取自己的id
    ~myCloseButton();
private:
    int id;
    //int state;//按键的两种输出状态
public slots:
    //void click();
};


class myOutputButton: public QPushButton{
public:
    myOutputButton(QString name,QWidget *parent,int id);
    ~myOutputButton();
    int getId(){return id;};
private:
    int id;
    bool state;

public slots:
    void changeFuncByTab();
    void changeFuncByShift();
//    void changeFuncBy
};


class myFunButton{};


#endif // MYBUTTON_H
