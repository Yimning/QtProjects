#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QTableWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include "EditStuMessBox.h"
#include <QFile>
#include <QDataStream>
#include "Student.h"
#include "Tool.h"
#include "MainWidget.h"
//自定义主窗口
#include <QMessageBox>

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QLayout>


#include <QTimer>
#include <QTime>
#include <QTimerEvent>

class Login : public QWidget
{
    Q_OBJECT
private:
    QPushButton* btnOK;
    QPushButton* btnCLOSE;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLineEdit *name;
    QLineEdit *password;
signals:
  void showMainSignal();

private slots:
    void setUI();
    void initial();
    void on_Login();

    void exitLogin();

    void onbtnStart();

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    int timerId;
    int countDown;
    int time;
    static int loginNum;
    virtual void timerEvent(QTimerEvent* event);
};
#endif // LOGIN_H
