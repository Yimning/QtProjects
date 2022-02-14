#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    this->setParent(parent);
    this->setWindowTitle(tr("老大"));
    this->resize(QSize(500, 500));

    bt1 = new QPushButton(this);
    bt1->setText(tr("关闭窗口"));
    bt1->move(QPoint(50, 50));

    /**
     * bt1: 信号发出者, 指针类型
     * &QPushButton::pressed: 信号的发射  &发送者的类名::信号名字
     * this: 信号接受者, 指针类型
     * &MainWidget::close: 信号的处理  &接收的类名::槽名字
     *
     */
    connect(bt1, &QPushButton::pressed, this, &MainWidget::close);

    bt2 = new QPushButton(this);
    bt2->setText(tr("隐藏关闭窗口按钮以及改变自身文本内容"));
    bt2->move(QPoint(100, 100));

    /**
     * Qt5: 槽和普通的C++成员函数几乎是一样的
     * 可以是虚函数，可以被重载，可以是public slots、protected slots、private slots，可以被其他C++成员函数直接调用
     * 唯一不同的是：槽还可以和信号连接在一起，在这种情况下，信号被发射时，会自动调用这个槽
     * 槽不需要信号传过来的参数时，可以不要参数；但槽函数一旦要参数，其参数个数，类型，顺序必须要和对应的信号保持一致。另外，槽函数的参数不能有缺省值。
     * 由于信号的返回值为void, 槽必须和信号的返回值保持一致, 因此槽的返回值为void
     *
     */
    connect(bt2, &QPushButton::released, this, &MainWidget::myButtonReleasedSlot);
    connect(bt2, &QPushButton::released, bt1, &QPushButton::hide);

    bt3 = new QPushButton(this);
    bt3->setText(tr("切换到子窗口"));
    bt3->move(QPoint(150, 150));

    sw = new SubWidget();
    connect(bt3, &QPushButton::released, this, &MainWidget::myChangeWin);

    void (SubWidget::*funSignal)() = &SubWidget::mySignal;
    void (SubWidget::*funSignalParm)(int, QString) = &SubWidget::mySignalParm;
    void (MainWidget::*funSlot)() = &MainWidget::myDealSub;
    void (MainWidget::*funSlotParm)(int, QString) = &MainWidget::myDealSubParm;
    connect(sw, funSignal, this, funSlot);
    connect(sw, funSignalParm, this, funSlotParm);

    /**
     * Lambda 表达式, 匿名函数对象
     * C++11 新增加的特性, 编译时需要添加参数C++11
     * Qt配合信号一起使用, 非常方便
     */
    QPushButton *bt4 = new QPushButton(this);
    bt4->setText(tr("Lambda表达式并统计次数"));
    bt4->move(QPoint(200, 200));
    int cout = 0;
    connect(bt4, &QPushButton::clicked, this,
        // = : 把外部所有局部变量、类中所有成员以值传递方式
        // this : 类中所有成员以值传递方式
        // & : 把外部所有局部变量, 引用符号
        [=](bool isCheck) mutable {
            cout++;
            bt4->setText(tr("点击次数: ") + QString::number(cout));
            qDebug() << tr("这是一个Lambda表达式测试输出").toStdString().c_str();
            qDebug() << tr("打印参数: ").toStdString().c_str() << isCheck;
        });
}

MainWidget::~MainWidget()
{
    // 直接或间接继承于QObject的对象, 在释放的内存的时候, 会自动调用析构函数, 释放子对象的内存
    // 故QPushButton bt1 bt2 bt3 bt4 会随着QWidget MainWidget的释放而自动调用子对象的析构函数, 释放子对象的内存
}

void MainWidget::myButtonReleasedSlot()
{
    if (bt2 != nullptr)
    {
        bt2->setText(tr("发送信号, 槽处理完成 ..."));
    }
}

void MainWidget::myChangeWin()
{
    this->hide();
    sw->show();
}

void MainWidget::myDealSub()
{
    this->show();
    sw->hide();
}

void MainWidget::myDealSubParm(int num, QString str)
{
    qDebug() << "num: " << num << " str: " << str.toUtf8().data();
    qDebug() << "num: " << num << " str: " << str.toStdString().c_str();

    qWarning() << "num: " << num << " str: " << str.toUtf8().data();
    qInfo() << "num: " << num << " str: " << str.toUtf8().data();
    //qFatal(str.toUtf8().data());
}
