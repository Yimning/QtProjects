#include "mainwidget.h"

#include <QApplication>

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w; // 执行MainWidget的构造函数
    w.show();
    return a.exec();
}
