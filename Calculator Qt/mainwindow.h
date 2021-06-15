#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double result = 0;
    double value = 0;
    QChar current_operator;

private slots:
    void on_button_0_clicked();
    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();
    void on_button_dot_clicked();
    void on_button_add_clicked();
    void on_button_sub_clicked();
    void on_button_mul_clicked();
    void on_button_div_clicked();
    void on_button_pow_clicked();
    void on_button_sqrt_clicked();
    void on_button_equal_clicked();
    void on_button_clear_clicked();
    void function(QChar);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
