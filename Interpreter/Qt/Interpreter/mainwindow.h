#pragma once

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

private slots:
    void on_pushButton_clicked();
    void variable(QString&);
    void print(QString&);
    void loop(QString&, int);
    void compare(QString&, QString&, int&, QWidget*);
    void initialize(QString&, QString&, QWidget*);

private:
    Ui::MainWindow *ui;
};
