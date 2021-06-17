#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

/**
  * @date 2020/7/14 @author Melody
  * @brief  LoginDialog
*/

namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
private:
    Ui::LoginDialog *ui;

private slots:
    void on_HelpBtd_clicked();
    void on_LoginBtd_clicked();
};

#endif // LOGINDIALOG_H
