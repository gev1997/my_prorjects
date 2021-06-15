#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QIcon>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int step = 1;

    int get_i = 0;
    int get_j = 0;
    int set_i = 0;
    int set_j = 0;

    QIcon w_pawn;
    QIcon w_rock;
    QIcon w_knight;
    QIcon w_bishop;
    QIcon w_queen;
    QIcon w_king;

    QIcon b_pawn;
    QIcon b_rock;
    QIcon b_knight;
    QIcon b_bishop;
    QIcon b_queen;
    QIcon b_king;

    QIcon empty_icon;

    class player {
    public:
        char pawn[8] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
        char rock[2] = {'a', 'a'};
        char knight[2] = {'a', 'a'};
        char bishop[2] = {'a', 'a'};
        char queen = 'a';
        char king = 'a';
    };
    player white;
    player black;

    int current_player = 0;

    char* board[8][8];
    char dash[8][8];

    char empty = '-';

    QPushButton* button_board[8][8];

    void set_new_board();
    bool check_step(int, int, int, int);
    bool checkmate_white();
    bool checkmate_black();
    void move(int, int, int, int);

    void button_step(int, int, int, int);

private slots:
    void on_board_00_clicked();
    void on_board_01_clicked();
    void on_board_02_clicked();
    void on_board_03_clicked();
    void on_board_04_clicked();
    void on_board_05_clicked();
    void on_board_06_clicked();
    void on_board_07_clicked();
    void on_board_10_clicked();
    void on_board_11_clicked();
    void on_board_12_clicked();
    void on_board_13_clicked();
    void on_board_14_clicked();
    void on_board_15_clicked();
    void on_board_16_clicked();
    void on_board_17_clicked();
    void on_board_20_clicked();
    void on_board_21_clicked();
    void on_board_22_clicked();
    void on_board_23_clicked();
    void on_board_24_clicked();
    void on_board_25_clicked();
    void on_board_26_clicked();
    void on_board_27_clicked();
    void on_board_30_clicked();
    void on_board_31_clicked();
    void on_board_32_clicked();
    void on_board_33_clicked();
    void on_board_34_clicked();
    void on_board_35_clicked();
    void on_board_36_clicked();
    void on_board_37_clicked();
    void on_board_40_clicked();
    void on_board_41_clicked();
    void on_board_42_clicked();
    void on_board_43_clicked();
    void on_board_44_clicked();
    void on_board_45_clicked();
    void on_board_46_clicked();
    void on_board_47_clicked();
    void on_board_50_clicked();
    void on_board_51_clicked();
    void on_board_52_clicked();
    void on_board_53_clicked();
    void on_board_54_clicked();
    void on_board_55_clicked();
    void on_board_56_clicked();
    void on_board_57_clicked();
    void on_board_60_clicked();
    void on_board_61_clicked();
    void on_board_62_clicked();
    void on_board_63_clicked();
    void on_board_64_clicked();
    void on_board_65_clicked();
    void on_board_66_clicked();
    void on_board_67_clicked();
    void on_board_70_clicked();
    void on_board_71_clicked();
    void on_board_72_clicked();
    void on_board_73_clicked();
    void on_board_74_clicked();
    void on_board_75_clicked();
    void on_board_76_clicked();
    void on_board_77_clicked();

    void on_current_player_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
