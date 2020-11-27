#ifndef WIDG_H
#define WIDG_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include <QPushButton>

#include <vector>

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
    void onclick(QSystemTrayIcon::ActivationReason);
    bool makeAPushButton(QString,QRect);
    std::vector<QPushButton*> buttonArry;

    int initialze();//override
private:
    bool m_bMoving;         // 移动标志
    QPoint m_pointPosition; // 移动位置
public slots:
    void display();

//public slots:
//    void rmf();
};

#endif // WIDG_H
