

#include "widg.h"


#include <QApplication>
#include <QWidget>
#include <QScreen>
#include <QRect>
#include <QtDebug>
#include <QSystemTrayIcon>


#include <iostream>
#include <utility>
using namespace std;



//获取屏幕大小
pair<int,int> getScreenSize(){
    QList<QScreen *> list_screen = QGuiApplication::screens();
    QRect rect = list_screen.at(0)->geometry();
    pair<int,int> p;
    p = make_pair(rect.width(),rect.height());
    return p;
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    pair<int,int> screenSize = getScreenSize();
    qDebug() << screenSize.first << screenSize.second;


    BaseBoard w;
    w.resize(screenSize.first,screenSize.second/2);
    w.move(0,screenSize.second/2);
    w.setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);


    QSystemTrayIcon system_tray;
    system_tray.setToolTip(QString("12312"));
    system_tray.setIcon(QIcon(":\\icon\\123.jpg"));

    system_tray.connect(&system_tray , SIGNAL(activated(QSystemTrayIcon::ActivationReason)), &w ,
                        SLOT(display()));
    system_tray.show();

    return app.exec();


}
