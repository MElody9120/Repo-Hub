#include <QtGui/QApplication>
#include "mainwindow.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication Calculator(argc, argv);
    MainWindow w;
    LoginDialog dlg;
    dlg.setWindowTitle("Login Calculator");
    if(dlg.exec()== QDialog::Accepted){
        w.setWindowTitle("Simple Calculator");
        w.show();
    }
    return Calculator.exec();
}
