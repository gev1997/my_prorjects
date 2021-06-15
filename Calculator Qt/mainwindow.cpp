#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_0_clicked()
{
    ui->input_text->insertPlainText("0");
}

void MainWindow::on_button_1_clicked()
{
    ui->input_text->insertPlainText("1");
}

void MainWindow::on_button_2_clicked()
{
    ui->input_text->insertPlainText("2");
}

void MainWindow::on_button_3_clicked()
{
    ui->input_text->insertPlainText("3");
}

void MainWindow::on_button_4_clicked()
{
    ui->input_text->insertPlainText("4");
}

void MainWindow::on_button_5_clicked()
{
    ui->input_text->insertPlainText("5");
}

void MainWindow::on_button_6_clicked()
{
    ui->input_text->insertPlainText("6");
}

void MainWindow::on_button_7_clicked()
{
    ui->input_text->insertPlainText("7");
}

void MainWindow::on_button_8_clicked()
{
    ui->input_text->insertPlainText("8");
}

void MainWindow::on_button_9_clicked()
{
    ui->input_text->insertPlainText("9");
}

void MainWindow::on_button_dot_clicked()
{
    ui->input_text->insertPlainText(".");
}

void MainWindow::on_button_add_clicked()
{
    function('+');
}

void MainWindow::on_button_sub_clicked()
{
    function('-');
}

void MainWindow::on_button_mul_clicked()
{
    function('*');
}

void MainWindow::on_button_div_clicked()
{
    function('/');
}

void MainWindow::on_button_pow_clicked()
{
    QString tmp = ui->input_text->toPlainText();
    ui->input_text->clear();
    result = pow(tmp.toDouble(), 2);
    ui->output_text->setPlainText(QString::number(result));
}

void MainWindow::on_button_sqrt_clicked()
{
    QString tmp = ui->input_text->toPlainText();
    ui->input_text->clear();
    result = sqrt(tmp.toDouble());
    ui->output_text->setPlainText(QString::number(result));
}

void MainWindow::on_button_equal_clicked()
{
    QString tmp = ui->input_text->toPlainText();
    ui->input_text->clear();

    if (result == 0) {
         ui->output_text->setPlainText(tmp);
    }
    else {
        value = tmp.toDouble();

        if (current_operator == '+') {
            result += value;
        }
        else if (current_operator == '-') {
            result -= value;
        }
        else if (current_operator == '*') {
            result *= value;
        }
        else if (current_operator == '/') {
            result /= value;
        }

        ui->output_text->setPlainText(QString::number(result));
    }
}

void MainWindow::on_button_clear_clicked()
{
    ui->input_text->clear();
    ui->output_text->clear();

    result = 0;
    value = 0;
}

void MainWindow::function(QChar op) {
    current_operator = op;

    QString tmp = ui->input_text->toPlainText();
    ui->input_text->clear();

    ui->output_text->insertPlainText(tmp);
    ui->output_text->insertPlainText("\n");
    ui->output_text->insertPlainText(op);

    if (result == 0){
        result = tmp.toDouble();
    }
    else {
        value = tmp.toDouble();
        result += value;
        value = 0;
        ui->output_text->clear();
        ui->output_text->insertPlainText(QString::number(result));
        ui->output_text->insertPlainText("\n");
        ui->output_text->insertPlainText(op);
    }
}
