#ifndef WIDG_H
#define WIDG_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include <QPushButton>
//#include <QRadioButton>
#include <QButtonGroup>

#include <vector>
#include <string>


//template <typename T>
//窗体抽象类
//class Widg : public QWidget
//{
//public:
//    Widg(QWidget *parent = Q_NULLPTR);
//    virtual ~Widg();

//    virtual int initialze() = 0;

//protected:
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//};

//最底层容器
class BaseBoard:
        public QWidget{
    Q_OBJECT
public:
    BaseBoard(QWidget *parent = Q_NULLPTR);
    ~BaseBoard();
    QButtonGroup* buttonArry;
    void onclick(QSystemTrayIcon::ActivationReason);
    bool makeAPushButton(QString,QRect,int);  //生成普通按钮
    bool makeAFuncPushButton(QString,QRect,int); //生成功能按钮
    int initialze();//override
    std::vector<QString> buttonNames;
private:
    bool m_bMoving;         // 移动标志
    QPoint m_pointPosition; // 移动位置
    int height;
    int width;
public slots:
    void display();

//public slots:
//    void rmf();
};

#endif // WIDG_H
