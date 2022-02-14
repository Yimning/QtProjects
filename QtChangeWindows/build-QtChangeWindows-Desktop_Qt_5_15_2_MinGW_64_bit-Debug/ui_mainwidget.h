/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mainwidget
{
public:

    void setupUi(QWidget *Mainwidget)
    {
        if (Mainwidget->objectName().isEmpty())
            Mainwidget->setObjectName(QString::fromUtf8("Mainwidget"));
        Mainwidget->resize(800, 600);

        retranslateUi(Mainwidget);

        QMetaObject::connectSlotsByName(Mainwidget);
    } // setupUi

    void retranslateUi(QWidget *Mainwidget)
    {
        Mainwidget->setWindowTitle(QCoreApplication::translate("Mainwidget", "Mainwidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mainwidget: public Ui_Mainwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
