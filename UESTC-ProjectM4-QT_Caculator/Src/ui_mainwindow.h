/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jul 9 08:34:43 2020
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *record_lineEdit;
    QLineEdit *input_lineEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *mod_pushButton;
    QPushButton *pushButton_1;
    QPushButton *cleanInput_pushButton;
    QPushButton *del_pushButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *_7_pushButton;
    QPushButton *_8_pushButton;
    QPushButton *_9_pushButton;
    QPushButton *div_pushButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *_4_pushButton;
    QPushButton *_5_pushButton;
    QPushButton *_6_pushButton;
    QPushButton *time_pushButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *_1_pushButton;
    QPushButton *_2_pushButton;
    QPushButton *_3_pushButton;
    QPushButton *sub_pushButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *decimal_pushButton;
    QPushButton *pushButton_0;
    QPushButton *equal_pushButton;
    QPushButton *add_pushButton;
    QPlainTextEdit *record_plainTextEdit;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(930, 540);
        MainWindow->setMinimumSize(QSize(730, 540));
        MainWindow->setMaximumSize(QSize(930, 540));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 711, 471));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        record_lineEdit = new QLineEdit(verticalLayoutWidget);
        record_lineEdit->setObjectName(QString::fromUtf8("record_lineEdit"));
        record_lineEdit->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(12);
        record_lineEdit->setFont(font);
        record_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        record_lineEdit->setReadOnly(true);

        verticalLayout->addWidget(record_lineEdit);

        input_lineEdit = new QLineEdit(verticalLayoutWidget);
        input_lineEdit->setObjectName(QString::fromUtf8("input_lineEdit"));
        input_lineEdit->setMinimumSize(QSize(0, 80));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Book Antiqua"));
        font1.setPointSize(50);
        input_lineEdit->setFont(font1);
        input_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(input_lineEdit);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        mod_pushButton = new QPushButton(verticalLayoutWidget);
        mod_pushButton->setObjectName(QString::fromUtf8("mod_pushButton"));
        mod_pushButton->setMinimumSize(QSize(0, 45));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Book Antiqua"));
        font2.setPointSize(36);
        mod_pushButton->setFont(font2);

        horizontalLayout_6->addWidget(mod_pushButton);

        pushButton_1 = new QPushButton(verticalLayoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(0, 45));
        pushButton_1->setFont(font2);

        horizontalLayout_6->addWidget(pushButton_1);

        cleanInput_pushButton = new QPushButton(verticalLayoutWidget);
        cleanInput_pushButton->setObjectName(QString::fromUtf8("cleanInput_pushButton"));
        cleanInput_pushButton->setMinimumSize(QSize(0, 45));
        cleanInput_pushButton->setFont(font2);

        horizontalLayout_6->addWidget(cleanInput_pushButton);

        del_pushButton = new QPushButton(verticalLayoutWidget);
        del_pushButton->setObjectName(QString::fromUtf8("del_pushButton"));
        del_pushButton->setMinimumSize(QSize(0, 45));
        del_pushButton->setFont(font2);
        QIcon icon;
        icon.addFile(QString::fromUtf8("del.png"), QSize(), QIcon::Normal, QIcon::Off);
        del_pushButton->setIcon(icon);
        del_pushButton->setIconSize(QSize(140, 41));

        horizontalLayout_6->addWidget(del_pushButton);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        _7_pushButton = new QPushButton(verticalLayoutWidget);
        _7_pushButton->setObjectName(QString::fromUtf8("_7_pushButton"));
        _7_pushButton->setMinimumSize(QSize(0, 45));
        _7_pushButton->setFont(font2);
        _7_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_2->addWidget(_7_pushButton);

        _8_pushButton = new QPushButton(verticalLayoutWidget);
        _8_pushButton->setObjectName(QString::fromUtf8("_8_pushButton"));
        _8_pushButton->setMinimumSize(QSize(0, 45));
        _8_pushButton->setFont(font2);
        _8_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_2->addWidget(_8_pushButton);

        _9_pushButton = new QPushButton(verticalLayoutWidget);
        _9_pushButton->setObjectName(QString::fromUtf8("_9_pushButton"));
        _9_pushButton->setMinimumSize(QSize(0, 45));
        _9_pushButton->setFont(font2);
        _9_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_2->addWidget(_9_pushButton);

        div_pushButton = new QPushButton(verticalLayoutWidget);
        div_pushButton->setObjectName(QString::fromUtf8("div_pushButton"));
        div_pushButton->setMinimumSize(QSize(0, 45));
        div_pushButton->setFont(font2);
        div_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_2->addWidget(div_pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        _4_pushButton = new QPushButton(verticalLayoutWidget);
        _4_pushButton->setObjectName(QString::fromUtf8("_4_pushButton"));
        _4_pushButton->setMinimumSize(QSize(0, 45));
        _4_pushButton->setFont(font2);
        _4_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_4->addWidget(_4_pushButton);

        _5_pushButton = new QPushButton(verticalLayoutWidget);
        _5_pushButton->setObjectName(QString::fromUtf8("_5_pushButton"));
        _5_pushButton->setMinimumSize(QSize(0, 45));
        _5_pushButton->setFont(font2);
        _5_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_4->addWidget(_5_pushButton);

        _6_pushButton = new QPushButton(verticalLayoutWidget);
        _6_pushButton->setObjectName(QString::fromUtf8("_6_pushButton"));
        _6_pushButton->setMinimumSize(QSize(0, 45));
        _6_pushButton->setFont(font2);
        _6_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_4->addWidget(_6_pushButton);

        time_pushButton = new QPushButton(verticalLayoutWidget);
        time_pushButton->setObjectName(QString::fromUtf8("time_pushButton"));
        time_pushButton->setMinimumSize(QSize(0, 45));
        time_pushButton->setFont(font2);
        time_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_4->addWidget(time_pushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        _1_pushButton = new QPushButton(verticalLayoutWidget);
        _1_pushButton->setObjectName(QString::fromUtf8("_1_pushButton"));
        _1_pushButton->setMinimumSize(QSize(0, 45));
        _1_pushButton->setFont(font2);
        _1_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_5->addWidget(_1_pushButton);

        _2_pushButton = new QPushButton(verticalLayoutWidget);
        _2_pushButton->setObjectName(QString::fromUtf8("_2_pushButton"));
        _2_pushButton->setMinimumSize(QSize(0, 45));
        _2_pushButton->setFont(font2);
        _2_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_5->addWidget(_2_pushButton);

        _3_pushButton = new QPushButton(verticalLayoutWidget);
        _3_pushButton->setObjectName(QString::fromUtf8("_3_pushButton"));
        _3_pushButton->setMinimumSize(QSize(0, 45));
        _3_pushButton->setFont(font2);
        _3_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_5->addWidget(_3_pushButton);

        sub_pushButton = new QPushButton(verticalLayoutWidget);
        sub_pushButton->setObjectName(QString::fromUtf8("sub_pushButton"));
        sub_pushButton->setMinimumSize(QSize(0, 45));
        sub_pushButton->setFont(font2);
        sub_pushButton->setIconSize(QSize(45, 16));

        horizontalLayout_5->addWidget(sub_pushButton);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        decimal_pushButton = new QPushButton(verticalLayoutWidget);
        decimal_pushButton->setObjectName(QString::fromUtf8("decimal_pushButton"));
        decimal_pushButton->setMinimumSize(QSize(0, 45));
        decimal_pushButton->setFont(font2);

        horizontalLayout_3->addWidget(decimal_pushButton);

        pushButton_0 = new QPushButton(verticalLayoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setMinimumSize(QSize(0, 45));
        pushButton_0->setFont(font2);

        horizontalLayout_3->addWidget(pushButton_0);

        equal_pushButton = new QPushButton(verticalLayoutWidget);
        equal_pushButton->setObjectName(QString::fromUtf8("equal_pushButton"));
        equal_pushButton->setMinimumSize(QSize(0, 45));
        equal_pushButton->setFont(font2);

        horizontalLayout_3->addWidget(equal_pushButton);

        add_pushButton = new QPushButton(verticalLayoutWidget);
        add_pushButton->setObjectName(QString::fromUtf8("add_pushButton"));
        add_pushButton->setMinimumSize(QSize(0, 45));
        add_pushButton->setFont(font2);

        horizontalLayout_3->addWidget(add_pushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        record_plainTextEdit = new QPlainTextEdit(centralWidget);
        record_plainTextEdit->setObjectName(QString::fromUtf8("record_plainTextEdit"));
        record_plainTextEdit->setGeometry(QRect(730, 10, 191, 471));
        record_plainTextEdit->setMaximumSize(QSize(191, 471));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 930, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        record_lineEdit->setText(QString());
        input_lineEdit->setText(QString());
        mod_pushButton->setText(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("MainWindow", "CE", 0, QApplication::UnicodeUTF8));
        cleanInput_pushButton->setText(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        del_pushButton->setText(QString());
        _7_pushButton->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        _8_pushButton->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        _9_pushButton->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        div_pushButton->setText(QApplication::translate("MainWindow", "\303\267", 0, QApplication::UnicodeUTF8));
        _4_pushButton->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        _5_pushButton->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        _6_pushButton->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        time_pushButton->setText(QApplication::translate("MainWindow", "\303\227", 0, QApplication::UnicodeUTF8));
        _1_pushButton->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        _2_pushButton->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        _3_pushButton->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        sub_pushButton->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        decimal_pushButton->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        pushButton_0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        equal_pushButton->setText(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        add_pushButton->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
