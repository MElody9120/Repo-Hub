/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created: Wed Jul 15 02:35:24 2020
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *UsrLineEdit;
    QLineEdit *PswLineEdit;
    QPushButton *LoginBtd;
    QPushButton *ExitBtd;
    QPushButton *HelpBtd;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(400, 300);
        label = new QLabel(LoginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 50, 80, 17));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 100, 80, 17));
        UsrLineEdit = new QLineEdit(LoginDialog);
        UsrLineEdit->setObjectName(QString::fromUtf8("UsrLineEdit"));
        UsrLineEdit->setGeometry(QRect(180, 50, 200, 27));
        PswLineEdit = new QLineEdit(LoginDialog);
        PswLineEdit->setObjectName(QString::fromUtf8("PswLineEdit"));
        PswLineEdit->setGeometry(QRect(180, 100, 200, 27));
        LoginBtd = new QPushButton(LoginDialog);
        LoginBtd->setObjectName(QString::fromUtf8("LoginBtd"));
        LoginBtd->setGeometry(QRect(40, 170, 92, 27));
        ExitBtd = new QPushButton(LoginDialog);
        ExitBtd->setObjectName(QString::fromUtf8("ExitBtd"));
        ExitBtd->setGeometry(QRect(290, 170, 92, 27));
        HelpBtd = new QPushButton(LoginDialog);
        HelpBtd->setObjectName(QString::fromUtf8("HelpBtd"));
        HelpBtd->setGeometry(QRect(160, 170, 92, 27));

        retranslateUi(LoginDialog);
        QObject::connect(ExitBtd, SIGNAL(clicked()), LoginDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoginDialog", "Username", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LoginDialog", "Password", 0, QApplication::UnicodeUTF8));
        LoginBtd->setText(QApplication::translate("LoginDialog", "Login", 0, QApplication::UnicodeUTF8));
        ExitBtd->setText(QApplication::translate("LoginDialog", "Exit", 0, QApplication::UnicodeUTF8));
        HelpBtd->setText(QApplication::translate("LoginDialog", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
