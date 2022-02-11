#include <QApplication>
#include "MainWidget.h"
#include "Login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

     Login login;
     login.show();

     MainWidget mWidget;
    //mWidget.show();
    QObject::connect(&login, SIGNAL(showMainSignal()), &mWidget, SLOT(receiveLogin()));

    QObject::connect(&mWidget, SIGNAL(exitSignal()), &login, SLOT(exitLogin()));

    a.exec();
    return 0;
}
