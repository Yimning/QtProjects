#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtCore/QDebug>

#include "ui_mainwidget.h"

#include "subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

signals:

public slots:
    void myButtonReleasedSlot();
    void myChangeWin();
    void myDealSub();
    void myDealSubParm(int, QString);

private:
    Ui::Mainwidget  ui;

    QPushButton * bt1;
    QPushButton * bt2;
    QPushButton * bt3;

    SubWidget * sw;
};

#endif // MAINWIDGET_H
