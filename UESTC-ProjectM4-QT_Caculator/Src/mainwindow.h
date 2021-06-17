#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_mod_pushButton_clicked();
    void on__7_pushButton_clicked();

    void on__1_pushButton_clicked();

    void on_input_lineEdit_editingFinished();

    void on__8_pushButton_clicked();

    void on__9_pushButton_clicked();

    void on__4_pushButton_clicked();

    void on__5_pushButton_clicked();

    void on__6_pushButton_clicked();

    void on__2_pushButton_clicked();

    void on__3_pushButton_clicked();

    void on_pushButton_0_clicked();

    void on_cleanInput_pushButton_clicked();

    void on_decimal_pushButton_clicked();

    void on_add_pushButton_clicked();

    void on_sub_pushButton_clicked();

    void on_time_pushButton_clicked();

    void on_div_pushButton_clicked();

    void on_del_pushButton_clicked();

    void on_pushButton_1_clicked();

    void on_equal_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void inputTextDisplay(); //ʾ
    void recordTextDisplay(); //¼ֶʾ
    void errorButtonLocker();   //
    void errorButtonUnlocker(); //
    void recordplainLineDisplay(); //

    double sumStackNum();   //ջ
    double heigOp(double inputDouble);
};

#endif // MAINWINDOW_H
