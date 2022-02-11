#include<QDebug>
#include "Login.h"


Login::Login(QWidget *parent)
    : QWidget(parent)
{
    this->resize(100,100);
    setUI();
    connect(btnCLOSE,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnOK,SIGNAL(clicked()),this,SLOT(on_Login()));
    initialSignal();
    setWindowTitle("StuInfo System");

}

Login::~Login()
{
}

void Login::setUI()
{
    label3 = new QLabel(tr("Qt学生信息管理系统"));
    QFont font = label3->font();
    font.setPointSize(20);
    label3->setFont(font);
    //登录标题
    label1 = new QLabel(tr("用户名:"));
    name = new QLineEdit;
    QHBoxLayout *input_name = new QHBoxLayout;
    input_name->addWidget(label1);
    input_name->addWidget(name);
    //输入用户名
    label2 = new QLabel(tr("密  码:"));
    password = new QLineEdit;
    QHBoxLayout *input_password = new QHBoxLayout;
    input_password->addWidget(label2);
    input_password->addWidget(password);
    //输入密码
    btnOK = new QPushButton(tr("确定"));
    btnCLOSE = new QPushButton(tr("取消"));
    QHBoxLayout *button = new QHBoxLayout;
    button->addWidget(btnOK);
    button->addStretch();
    button->addWidget(btnCLOSE);
    //操作按钮
    QVBoxLayout *page = new QVBoxLayout;
    page->addWidget(label3);
    page->addLayout(input_name);
    page->addLayout(input_password);
    page->addLayout(button);
    //构建主页面框架
    setLayout(page);//完成布局
}

void Login::initialSignal()
{
    this->update();
    this->repaint();
}



void Login::exitLogin()
{
    this->show();
    this->initialSignal();
    name->setText("");
    password->setText("");
}

void Login::on_Login()
{
    static int cout = 0;
    int  i = 1;
    QString user = name->text();
    QString pass = password->text();
    QString p="";
    int lenth = pass.count();
    for(int i=0;i<lenth;i++)p.append("*");
    password->setText(p);
    if(user=="1"&&pass=="1"){
       QMessageBox msgBox;
       msgBox.setText("登录成功\nWelcome!");
       msgBox.exec();
       this->hide();
       emit showMainSignal();
    }
    else{
        cout++;
        i = 5-cout;

        if(cout>=5)
        {
            QMessageBox msgBox;
            msgBox.setText("由于操作失败多次,系统暂禁止登录\n");
            msgBox.exec();
            disconnect(btnOK,SIGNAL(clicked),this,SLOT(on_Login()));
            btnOK->setDisabled(true);
        }else
        {
            p = QString("登录失败,还剩%1次机会").arg(i);
            QMessageBox msgBox;
            msgBox.setText(p);
            msgBox.exec();
        }
    }

    int len = user.count();
    if(len==0||lenth==0)
    {
        QMessageBox msgBox;
        msgBox.setText("未输入内容\n禁止登录");
        msgBox.exec();
        cout--;
    }
   // label3->setText(p);
}
