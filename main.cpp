#include "widg.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Qt::WindowFlags flags = 0;
    flags |= Qt::FramelessWindowHint;

    BaseBoard w;
    w.resize(640,320);
    w.move(400,200);
    w.setWindowFlags(flags);//去标题边框
    w.show();

    return app.exec();
}
