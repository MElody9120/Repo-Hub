#include <qmessagebox.h>
#include <qlineedit.h>
#include <qstring.h>
#include "logindialog.h"
#include "ui_logindialog.h"
/**
  * @date 2020/7/14 @author Melody
  * @brief  LoginDialog
*/
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_LoginBtd_clicked()
{
    ui->PswLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->UsrLineEdit->setPlaceholderText(QString("User name only English"));
    if(ui->UsrLineEdit->text() == tr("Melody") &&
       ui->PswLineEdit->text() == tr("0000"))
    {
        accept();
    }else{
        QMessageBox::warning(this,tr("Warning"),
                             tr("User name or Password Error!\n Please Try again!"),
                             QMessageBox::Yes);
    }
}

void LoginDialog::on_HelpBtd_clicked()
{
    QMessageBox::information(this,tr("Help"),
                         tr("You must input Your User name and Password for login Calculator"),
                         QMessageBox::Yes);
}
