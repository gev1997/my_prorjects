#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

//MainWindow ctor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    w_pawn.addFile(QString::fromUtf8("./pieces/w_pawn.png"), QSize(), QIcon::Normal, QIcon::Off);
    w_rock.addFile(QString::fromUtf8("./pieces/w_rock.png"), QSize(), QIcon::Normal, QIcon::Off);
    w_knight.addFile(QString::fromUtf8("./pieces/w_knight.png"), QSize(), QIcon::Normal, QIcon::Off);
    w_bishop.addFile(QString::fromUtf8("./pieces/w_bishop.png"), QSize(), QIcon::Normal, QIcon::Off);
    w_queen.addFile(QString::fromUtf8("./pieces/w_queen.png"), QSize(), QIcon::Normal, QIcon::Off);
    w_king.addFile(QString::fromUtf8("./pieces/w_king.png"), QSize(), QIcon::Normal, QIcon::Off);

    b_pawn.addFile(QString::fromUtf8("./pieces/b_pawn.png"), QSize(), QIcon::Normal, QIcon::Off);
    b_rock.addFile(QString::fromUtf8("./pieces/b_rock.png"), QSize(), QIcon::Normal, QIcon::Off);
    b_knight.addFile(QString::fromUtf8("./pieces/b_knight.png"), QSize(), QIcon::Normal, QIcon::Off);
    b_bishop.addFile(QString::fromUtf8("./pieces/b_bishop.png"), QSize(), QIcon::Normal, QIcon::Off);
    b_queen.addFile(QString::fromUtf8("./pieces/b_queen.png"), QSize(), QIcon::Normal, QIcon::Off);
    b_king.addFile(QString::fromUtf8("./pieces/b_king.png"), QSize(), QIcon::Normal, QIcon::Off);

    ui->setupUi(this);

    //buttons array
    button_board[0][0] = ui->board_00;
    button_board[0][1] = ui->board_01;
    button_board[0][2] = ui->board_02;
    button_board[0][3] = ui->board_03;
    button_board[0][4] = ui->board_04;
    button_board[0][5] = ui->board_05;
    button_board[0][6] = ui->board_06;
    button_board[0][7] = ui->board_07;

    button_board[1][0] = ui->board_10;
    button_board[1][1] = ui->board_11;
    button_board[1][2] = ui->board_12;
    button_board[1][3] = ui->board_13;
    button_board[1][4] = ui->board_14;
    button_board[1][5] = ui->board_15;
    button_board[1][6] = ui->board_16;
    button_board[1][7] = ui->board_17;

    button_board[2][0] = ui->board_20;
    button_board[2][1] = ui->board_21;
    button_board[2][2] = ui->board_22;
    button_board[2][3] = ui->board_23;
    button_board[2][4] = ui->board_24;
    button_board[2][5] = ui->board_25;
    button_board[2][6] = ui->board_26;
    button_board[2][7] = ui->board_27;

    button_board[3][0] = ui->board_30;
    button_board[3][1] = ui->board_31;
    button_board[3][2] = ui->board_32;
    button_board[3][3] = ui->board_33;
    button_board[3][4] = ui->board_34;
    button_board[3][5] = ui->board_35;
    button_board[3][6] = ui->board_36;
    button_board[3][7] = ui->board_37;

    button_board[4][0] = ui->board_40;
    button_board[4][1] = ui->board_41;
    button_board[4][2] = ui->board_42;
    button_board[4][3] = ui->board_43;
    button_board[4][4] = ui->board_44;
    button_board[4][5] = ui->board_45;
    button_board[4][6] = ui->board_46;
    button_board[4][7] = ui->board_47;

    button_board[5][0] = ui->board_50;
    button_board[5][1] = ui->board_51;
    button_board[5][2] = ui->board_52;
    button_board[5][3] = ui->board_53;
    button_board[5][4] = ui->board_54;
    button_board[5][5] = ui->board_55;
    button_board[5][6] = ui->board_56;
    button_board[5][7] = ui->board_57;

    button_board[6][0] = ui->board_60;
    button_board[6][1] = ui->board_61;
    button_board[6][2] = ui->board_62;
    button_board[6][3] = ui->board_63;
    button_board[6][4] = ui->board_64;
    button_board[6][5] = ui->board_65;
    button_board[6][6] = ui->board_66;
    button_board[6][7] = ui->board_67;

    button_board[7][0] = ui->board_70;
    button_board[7][1] = ui->board_71;
    button_board[7][2] = ui->board_72;
    button_board[7][3] = ui->board_73;
    button_board[7][4] = ui->board_74;
    button_board[7][5] = ui->board_75;
    button_board[7][6] = ui->board_76;
    button_board[7][7] = ui->board_77;

    //black pieces icons
    button_board[0][0]->setIcon(b_rock);
    button_board[0][1]->setIcon(b_knight);
    button_board[0][2]->setIcon(b_bishop);
    button_board[0][3]->setIcon(b_queen);
    button_board[0][4]->setIcon(b_king);
    button_board[0][5]->setIcon(b_bishop);
    button_board[0][6]->setIcon(b_knight);
    button_board[0][7]->setIcon(b_rock);

    //white pieces icons
    button_board[7][0]->setIcon(w_rock);
    button_board[7][1]->setIcon(w_knight);
    button_board[7][2]->setIcon(w_bishop);
    button_board[7][3]->setIcon(w_queen);
    button_board[7][4]->setIcon(w_king);
    button_board[7][5]->setIcon(w_bishop);
    button_board[7][6]->setIcon(w_knight);
    button_board[7][7]->setIcon(w_rock);

    //white and black pawns
    for (int i = 0; i < 8; ++i) {
        button_board[1][i]->setIcon(b_pawn);
        button_board[6][i]->setIcon(w_pawn);
    }

    //set empty board pieces with empty icons
    for (int i = 2; i <= 5; ++i) {
        for (int j = 0; j < 8; ++j) {
            button_board[i][j]->setIcon(empty_icon);
        }
    }

    //set icons size for all board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            button_board[i][j]->setIconSize(QSize(46,46));
        }
    }

    set_new_board();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_step(int L_get_i, int L_get_j, int L_set_i, int L_set_j) {
    if (step == 1) {
        get_i = L_get_i;
        get_j = L_get_j;

        button_board[get_i][get_j]->setIconSize(QSize(35, 35));

        ++step;
    }
    else if(step == 2) {
        set_i = L_set_i;
        set_j = L_set_j;

        button_board[get_i][get_j]->setIconSize(QSize(46, 46));

        if (check_step(get_i, get_j, set_i, set_j)) {
            if (current_player % 2 == 0) {
                ui->centralwidget->setStyleSheet("background-color: black");
            }
            else {
               ui->centralwidget->setStyleSheet("background-color: white");
            }

            ++current_player;

            get_i = 0; get_j = 0; set_i = 0; set_j = 0;
        }

        step = 1;
    }
}

void MainWindow::on_board_00_clicked()
{
    button_step(0, 0, 0, 0);
}

void MainWindow::on_board_01_clicked()
{
    button_step(0, 1, 0, 1);
}

void MainWindow::on_board_02_clicked()
{
    button_step(0, 2, 0, 2);
}

void MainWindow::on_board_03_clicked()
{
    button_step(0, 3, 0, 3);
}

void MainWindow::on_board_04_clicked()
{
    button_step(0, 4, 0, 4);
}

void MainWindow::on_board_05_clicked()
{
    button_step(0, 5, 0, 5);
}

void MainWindow::on_board_06_clicked()
{
    button_step(0, 6, 0, 6);
}

void MainWindow::on_board_07_clicked()
{
    button_step(0, 7, 0, 7);
}

void MainWindow::on_board_10_clicked()
{
    button_step(1, 0, 1, 0);
}

void MainWindow::on_board_11_clicked()
{
    button_step(1, 1, 1, 1);
}

void MainWindow::on_board_12_clicked()
{
    button_step(1, 2, 1, 2);
}

void MainWindow::on_board_13_clicked()
{
    button_step(1, 3, 1, 3);
}

void MainWindow::on_board_14_clicked()
{
    button_step(1, 4, 1, 4);
}

void MainWindow::on_board_15_clicked()
{
    button_step(1, 5, 1, 5);
}

void MainWindow::on_board_16_clicked()
{
    button_step(1, 6, 1, 6);
}

void MainWindow::on_board_17_clicked()
{
    button_step(1, 7, 1, 7);
}

void MainWindow::on_board_20_clicked()
{
    button_step(2, 0, 2, 0);
}

void MainWindow::on_board_21_clicked()
{
    button_step(2, 1, 2, 1);
}

void MainWindow::on_board_22_clicked()
{
    button_step(2, 2, 2, 2);
}

void MainWindow::on_board_23_clicked()
{
    button_step(2, 3, 2, 3);
}

void MainWindow::on_board_24_clicked()
{
    button_step(2, 4, 2, 4);
}

void MainWindow::on_board_25_clicked()
{
    button_step(2, 5, 2, 5);
}

void MainWindow::on_board_26_clicked()
{
    button_step(2, 6, 2, 6);
}

void MainWindow::on_board_27_clicked()
{
    button_step(2, 7, 2, 7);
}

void MainWindow::on_board_30_clicked()
{
    button_step(3, 0, 3, 0);
}

void MainWindow::on_board_31_clicked()
{
    button_step(3, 1, 3, 1);
}

void MainWindow::on_board_32_clicked()
{
    button_step(3, 2, 3, 2);
}

void MainWindow::on_board_33_clicked()
{
    button_step(3, 3, 3, 3);
}

void MainWindow::on_board_34_clicked()
{
    button_step(3, 4, 3, 4);
}

void MainWindow::on_board_35_clicked()
{
    button_step(3, 5, 3, 5);
}

void MainWindow::on_board_36_clicked()
{
    button_step(3, 6, 3, 6);
}

void MainWindow::on_board_37_clicked()
{
    button_step(3, 7, 3, 7);
}

void MainWindow::on_board_40_clicked()
{
    button_step(4, 0, 4, 0);
}

void MainWindow::on_board_41_clicked()
{
    button_step(4, 1, 4, 1);
}

void MainWindow::on_board_42_clicked()
{
    button_step(4, 2, 4, 2);
}

void MainWindow::on_board_43_clicked()
{
    button_step(4, 3, 4, 3);
}

void MainWindow::on_board_44_clicked()
{
    button_step(4, 4, 4, 4);
}

void MainWindow::on_board_45_clicked()
{
    button_step(4, 5, 4, 5);
}

void MainWindow::on_board_46_clicked()
{
    button_step(4, 6, 4, 6);
}

void MainWindow::on_board_47_clicked()
{
    button_step(4, 7, 4, 7);
}

void MainWindow::on_board_50_clicked()
{
    button_step(5, 0, 5, 0);
}

void MainWindow::on_board_51_clicked()
{
    button_step(5, 1, 5, 1);
}

void MainWindow::on_board_52_clicked()
{
    button_step(5, 2, 5, 2);
}

void MainWindow::on_board_53_clicked()
{
    button_step(5, 3, 5, 3);
}

void MainWindow::on_board_54_clicked()
{
    button_step(5, 4, 5, 4);
}

void MainWindow::on_board_55_clicked()
{
    button_step(5, 5, 5, 5);
}

void MainWindow::on_board_56_clicked()
{
    button_step(5, 6, 5, 6);
}

void MainWindow::on_board_57_clicked()
{
    button_step(5, 7, 5, 7);
}

void MainWindow::on_board_60_clicked()
{
    button_step(6, 0, 6, 0);
}

void MainWindow::on_board_61_clicked()
{
    button_step(6, 1, 6, 1);
}

void MainWindow::on_board_62_clicked()
{
    button_step(6, 2, 6, 2);
}

void MainWindow::on_board_63_clicked()
{
    button_step(6, 3, 6, 3);
}

void MainWindow::on_board_64_clicked()
{
    button_step(6, 4, 6, 4);
}

void MainWindow::on_board_65_clicked()
{
    button_step(6, 5, 6, 5);
}

void MainWindow::on_board_66_clicked()
{
    button_step(6, 6, 6, 6);
}

void MainWindow::on_board_67_clicked()
{
    button_step(6, 7, 6, 7);
}

void MainWindow::on_board_70_clicked()
{
    button_step(7, 0, 7, 0);
}

void MainWindow::on_board_71_clicked()
{
    button_step(7, 1, 7, 1);
}

void MainWindow::on_board_72_clicked()
{
    button_step(7, 2, 7, 2);
}

void MainWindow::on_board_73_clicked()
{
    button_step(7, 3, 7, 3);
}

void MainWindow::on_board_74_clicked()
{
    button_step(7, 4, 7, 4);
}

void MainWindow::on_board_75_clicked()
{
    button_step(7, 5, 7, 5);
}

void MainWindow::on_board_76_clicked()
{
    button_step(7, 6, 7, 6);
}

void MainWindow::on_board_77_clicked()
{
    button_step(7, 7, 7, 7);
}

//repair checkmate function call mesto
bool MainWindow::check_step(int get_i, int get_j, int set_i, int set_j) {

    if (current_player % 2 == 0) { //check if white turn

        //check if white piece turn on white piece
        if (   board[set_i][set_j] != &white.rock[0] && board[set_i][set_j] != &white.rock[1]
            && board[set_i][set_j] != &white.knight[0] && board[set_i][set_j] != &white.knight[1]
            && board[set_i][set_j] != &white.bishop[0] && board[set_i][set_j] != &white.bishop[1]
            && board[set_i][set_j] != &white.king && board[set_i][set_j] != &white.queen

            && board[set_i][set_j] != &white.pawn[0] && board[set_i][set_j] != &white.pawn[1]
            && board[set_i][set_j] != &white.pawn[2] && board[set_i][set_j] != &white.pawn[3]
            && board[set_i][set_j] != &white.pawn[4] && board[set_i][set_j] != &white.pawn[5]
            && board[set_i][set_j] != &white.pawn[6] && board[set_i][set_j] != &white.pawn[7]

            //check if white player try get black piece
            && board[get_i][get_j] != &black.rock[0] && board[get_i][get_j] != &black.rock[1]
            && board[get_i][get_j] != &black.knight[0] && board[get_i][get_j] != &black.knight[1]
            && board[get_i][get_j] != &black.bishop[0] && board[get_i][get_j] != &black.bishop[1]
            && board[get_i][get_j] != &black.king && board[get_i][get_j] != &black.queen

            && board[get_i][get_j] != &black.pawn[0] && board[get_i][get_j] != &black.pawn[1]
            && board[get_i][get_j] != &black.pawn[2] && board[get_i][get_j] != &black.pawn[3]
            && board[get_i][get_j] != &black.pawn[4] && board[get_i][get_j] != &black.pawn[5]
            && board[get_i][get_j] != &black.pawn[6] && board[get_i][get_j] != &black.pawn[7] )
        {
            //check step range for pawn
            for (int i = 0; i < 8; ++i) {
                if (board[get_i][get_j] == &white.pawn[i]) {
                    if (get_j == set_j && *board[set_i][set_j] == empty) {
                        if ((get_i - set_i == 2 || get_i - set_i == 1) && get_i == 6) {
                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_white()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                        if (get_i - set_i == 1) {
                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_white()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                    }
                    else if (*board[set_i][set_j] != empty && ((get_i - set_i == 1) && (set_j - get_j == 1 || get_j - set_j == 1))) {
                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                }
            }

            //check step range for rock
            if (board[get_i][get_j] == &white.rock[0] || board[get_i][get_j] == &white.rock[1]) {
                if (get_j == set_j) { //if step vertical
                    int tmp_get_i = get_i;
                    int tmp_set_i = set_i;

                    if (set_i < get_i) { //step up
                        while (tmp_get_i > tmp_set_i + 1) {
                            --tmp_get_i;
                            if (*board[tmp_get_i][set_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                    else if (set_i > get_i) { //step down
                        while (tmp_set_i > tmp_get_i + 1) {
                            --tmp_set_i;
                            if (*board[tmp_set_i][set_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                }//endif step vertical

                else if (get_i == set_i) { //if step horizontal
                    int tmp_get_j = get_j;
                    int tmp_set_j = set_j;

                    if (get_j < set_j) { //step right
                        while (tmp_get_j < tmp_set_j - 1) {
                            --tmp_set_j;
                            if (*board[set_i][tmp_set_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                    else if (get_j > set_j) { //step left
                        while (tmp_set_j < tmp_get_j - 1) {
                            --tmp_get_j;
                            if (*board[set_i][tmp_get_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                }//endif step horizontal
            }

            //check step range for knight
            if (board[get_i][get_j] == &white.knight[0] || board[get_i][get_j] == &white.knight[1]) {
                if ( (abs(get_i - set_i) == 2 && abs(get_j - set_j) == 1) ||
                        (abs(get_i - set_i) == 1 && abs(get_j - set_j) == 2) )
                {
                    move(get_i, get_j, set_i, set_j);
                    if (checkmate_white()) {
                        move(set_i, set_j, get_i, get_j);
                        return false;
                    }
                    return true;
                }
            }

            //check step range for bishop
            if (board[get_i][get_j] == &white.bishop[0] || board[get_i][get_j] == &white.bishop[1]) {
                if (abs(get_i - set_i) == abs(get_j - set_j)) {
                    int tmp_get_i = get_i;
                    int tmp_get_j = get_j;

                    int tmp_set_i = set_i;
                    int tmp_set_j = set_j;

                    if ((get_i > set_i) && (get_j > set_j)) { //left-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][--tmp_get_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                    else if ((get_i > set_i) && (get_j < set_j)) { //right-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j < tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][++tmp_get_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                    else if ((get_i < set_i) && (get_j > set_j)) { //left-down
                        while ((tmp_get_i < tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[++tmp_get_i][--tmp_get_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                    else if (((get_i < set_i) && (get_j < set_j))) { //rignt-down
                        while ((tmp_get_i + 1 < tmp_set_i) && (tmp_get_j + 1 < tmp_set_j)) {
                            if (*board[++tmp_get_i][++tmp_get_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                }
            }

            //check step range for queen
            if (board[get_i][get_j] == &white.queen) {
                int tmp_get_i = get_i;
                int tmp_get_j = get_j;
                int tmp_set_i = set_i;
                int tmp_set_j = set_j;

                if (get_i == set_i || get_j == set_j) { //check vertical-or-horizontal

                    if (get_j == set_j) { //if step vertical
                        if (set_i < get_i) { //step up
                            while (tmp_get_i > tmp_set_i + 1) {
                                --tmp_get_i;
                                if (*board[tmp_get_i][set_j] != empty) {
                                    if (checkmate_white()) {
                                        move(set_i, set_j, get_i, get_j);
                                        return false;
                                    }
                                    return false;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_white()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                        else if (set_i > get_i) { //step down
                            while (tmp_set_i > tmp_get_i + 1) {
                                --tmp_set_i;
                                if (*board[tmp_set_i][set_j] != empty) {
                                    if (checkmate_white()) {
                                        move(set_i, set_j, get_i, get_j);
                                        return false;
                                    }
                                    return false;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_white()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                    } //endif step vertical

                    else if (get_i == set_i) { //if step horizontal
                        if (get_j < set_j) { //step right
                            while (tmp_get_j < tmp_set_j - 1) {
                                --tmp_set_j;
                                if (*board[set_i][tmp_set_j] != empty) {
                                    if (checkmate_white()) {
                                        move(set_i, set_j, get_i, get_j);
                                        return false;
                                    }
                                    return false;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_white()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                        else if (get_j > set_j) { //step left
                            while (tmp_set_j < tmp_get_j - 1) {
                                --tmp_get_j;
                                if (*board[set_i][tmp_get_j] != empty) {
                                    if (checkmate_white()) {
                                        move(set_i, set_j, get_i, get_j);
                                        return false;
                                    }
                                    return false;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_white()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                    } //endif step horizontal

                } //end check vertical-or-horizontal

                if (abs(get_i - set_i) == abs(get_j - set_j)) { //check cross step
                    if ((get_i > set_i) && (get_j > set_j)) { //left-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][--tmp_get_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    } //end left-up

                    else if ((get_i > set_i) && (get_j < set_j)) { //right-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j < tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][++tmp_get_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    } //end right-up

                    else if ((get_i < set_i) && (get_j > set_j)) { //left-down
                        while ((tmp_get_i < tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[++tmp_get_i][--tmp_get_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    } //end left-down

                    else if (((get_i < set_i) && (get_j < set_j))) { //rignt-down
                        while ((tmp_get_i + 1 < tmp_set_i) && (tmp_get_j + 1 < tmp_set_j)) {
                            if (*board[++tmp_get_i][++tmp_get_j] != empty) {
                                if (checkmate_white()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_white()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    } //end right-down

                } //endif cross step
            }

            //check step range for king
            if (board[get_i][get_j] == &white.king) {
                if ( (abs(get_i - set_i) == 1 && get_j == set_j) || (abs(get_j - set_j) == 1 && get_i == set_i) ||
                        (abs(get_i - set_i) == 1 && abs(get_j - set_j) == 1) )
                {
                    move(get_i, get_j, set_i, set_j);
                    if (checkmate_white()) {
                        move(set_i, set_j, get_i, get_j);
                        return false;
                    }
                    return true;
                }
            }
        }
    }
    else { //check if black turn

        //check if black piece turn on black piece
        if (   board[set_i][set_j] != &black.rock[0] && board[set_i][set_j] != &black.rock[1]
            && board[set_i][set_j] != &black.knight[0] && board[set_i][set_j] != &black.knight[1]
            && board[set_i][set_j] != &black.bishop[0] && board[set_i][set_j] != &black.bishop[1]
            && board[set_i][set_j] != &black.king && board[set_i][set_j] != &black.queen

            && board[set_i][set_j] != &black.pawn[0] && board[set_i][set_j] != &black.pawn[1]
            && board[set_i][set_j] != &black.pawn[2] && board[set_i][set_j] != &black.pawn[3]
            && board[set_i][set_j] != &black.pawn[4] && board[set_i][set_j] != &black.pawn[5]
            && board[set_i][set_j] != &black.pawn[6] && board[set_i][set_j] != &black.pawn[7]

            //check if black player try get white piece
            && board[get_i][get_j] != &white.rock[0] && board[get_i][get_j] != &white.rock[1]
            && board[get_i][get_j] != &white.knight[0] && board[get_i][get_j] != &white.knight[1]
            && board[get_i][get_j] != &white.bishop[0] && board[get_i][get_j] != &white.bishop[1]
            && board[get_i][get_j] != &white.king && board[get_i][get_j] != &white.queen

            && board[get_i][get_j] != &white.pawn[0] && board[get_i][get_j] != &white.pawn[1]
            && board[get_i][get_j] != &white.pawn[2] && board[get_i][get_j] != &white.pawn[3]
            && board[get_i][get_j] != &white.pawn[4] && board[get_i][get_j] != &white.pawn[5]
            && board[get_i][get_j] != &white.pawn[6] && board[get_i][get_j] != &white.pawn[7] )
        {
            //check step range for pawn
            for (int i = 0; i < 8; ++i) {
                if (board[get_i][get_j] == &black.pawn[i]) {
                    if (get_j == set_j && *board[set_i][set_j] == empty) {
                        if ((set_i - get_i == 2 || set_i - get_i == 1) && get_i == 1) {
                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_black()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                        if (set_i - get_i == 1) {
                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_black()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                    }
                    else if (*board[set_i][set_j] != empty && ((set_i - get_i == 1) && (set_j - get_j == 1 || get_j - set_j == 1))) {
                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                }
            }

            //check step range for rock
            if (board[get_i][get_j] == &black.rock[0] || board[get_i][get_j] == &black.rock[1]) {
                if (get_j == set_j) { //if step vertical
                    int tmp_get_i = get_i;
                    int tmp_set_i = set_i;

                    if (set_i < get_i) { //step up
                        while (tmp_get_i > tmp_set_i + 1) {
                            --tmp_get_i;
                            if (*board[tmp_get_i][set_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                    else if (set_i > get_i) { //step down
                        while (tmp_set_i > tmp_get_i + 1) {
                            --tmp_set_i;
                            if (*board[tmp_set_i][set_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                } //endif step vertical

                else if (get_i == set_i) { //if step horizontal
                    int tmp_get_j = get_j;
                    int tmp_set_j = set_j;

                    if (get_j < set_j) { //step right
                        while (tmp_get_j < tmp_set_j - 1) {
                            --tmp_set_j;
                            if (*board[set_i][tmp_set_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                    else if (get_j > set_j) { //step left
                        while (tmp_set_j < tmp_get_j - 1) {
                            --tmp_get_j;
                            if (*board[set_i][tmp_get_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                } //endif step horizontal
            }

            //check step range for knight
            if (board[get_i][get_j] == &black.knight[0] || board[get_i][get_j] == &black.knight[1]) {
                if ( (abs(get_i - set_i) == 2 && abs(get_j - set_j) == 1) ||
                        (abs(get_i - set_i) == 1 && abs(get_j - set_j) == 2) )
                {
                    move(get_i, get_j, set_i, set_j);
                    if (checkmate_black()) {
                        move(set_i, set_j, get_i, get_j);
                        return false;
                    }
                    return true;
                }
            }

            //check step range for bishop
            if (board[get_i][get_j] == &black.bishop[0] || board[get_i][get_j] == &black.bishop[1]) {
                if (abs(get_i - set_i) == abs(get_j - set_j)) {
                    int tmp_get_i = get_i;
                    int tmp_get_j = get_j;

                    int tmp_set_i = set_i;
                    int tmp_set_j = set_j;

                    if ((get_i > set_i) && (get_j > set_j)) { //left-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][--tmp_get_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                    else if ((get_i > set_i) && (get_j < set_j)) { //right-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j < tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][++tmp_get_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                    else if ((get_i < set_i) && (get_j > set_j)) { //left-down
                        while ((tmp_get_i < tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[++tmp_get_i][--tmp_get_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                    else if (((get_i < set_i) && (get_j < set_j))) { //rignt-down
                        while ((tmp_get_i + 1 < tmp_set_i) && (tmp_get_j + 1 < tmp_set_j)) {
                            if (*board[++tmp_get_i][++tmp_get_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    }
                }
            }

            //check step range for queen
            if (board[get_i][get_j] == &black.queen) {
                int tmp_get_i = get_i;
                int tmp_get_j = get_j;
                int tmp_set_i = set_i;
                int tmp_set_j = set_j;

                if (get_i == set_i || get_j == set_j) { //check vertical-or-horizontal

                    if (get_j == set_j) { //if step vertical
                        if (set_i < get_i) { //step up
                            while (tmp_get_i > tmp_set_i + 1) {
                                --tmp_get_i;
                                if (*board[tmp_get_i][set_j] != empty) {
                                    if (checkmate_black()) {
                                        move(set_i, set_j, get_i, get_j);
                                        return false;
                                    }
                                    return false;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_black()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                        else if (set_i > get_i) { //step down
                            while (tmp_set_i > tmp_get_i + 1) {
                                --tmp_set_i;
                                if (*board[tmp_set_i][set_j] != empty) {
                                    if (checkmate_black()) {
                                        move(set_i, set_j, get_i, get_j);
                                        return false;
                                    }
                                    return false;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_black()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                    } //endif step vertical

                    else if (get_i == set_i) { //if step horizontal
                        if (get_j < set_j) { //step right
                            while (tmp_get_j < tmp_set_j - 1) {
                                --tmp_set_j;
                                if (*board[set_i][tmp_set_j] != empty) {
                                    if (checkmate_black()) {
                                        move(set_i, set_j, get_i, get_j);
                                        return false;
                                    }
                                    return false;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_black()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                        else if (get_j > set_j) { //step left
                            while (tmp_set_j < tmp_get_j - 1) {
                                --tmp_get_j;
                                if (*board[set_i][tmp_get_j] != empty) {
                                    if (checkmate_black()) {
                                        move(set_i, set_j, get_i, get_j);
                                        return false;
                                    }
                                    return false;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            if (checkmate_black()) {
                                move(set_i, set_j, get_i, get_j);
                                return false;
                            }
                            return true;
                        }
                    } //endif step horizontal

                } //end check vertical-or-horizontal

                if (abs(get_i - set_i) == abs(get_j - set_j)) { //check cross step
                    if ((get_i > set_i) && (get_j > set_j)) { //left-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][--tmp_get_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    } //end left-up

                    else if ((get_i > set_i) && (get_j < set_j)) { //right-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j < tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][++tmp_get_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    } //end right-up

                    else if ((get_i < set_i) && (get_j > set_j)) { //left-down
                        while ((tmp_get_i < tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[++tmp_get_i][--tmp_get_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    } //end left-down

                    else if (((get_i < set_i) && (get_j < set_j))) { //rignt-down
                        while ((tmp_get_i + 1 < tmp_set_i) && (tmp_get_j + 1 < tmp_set_j)) {
                            if (*board[++tmp_get_i][++tmp_get_j] != empty) {
                                if (checkmate_black()) {
                                    move(set_i, set_j, get_i, get_j);
                                    return false;
                                }
                                return false;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        if (checkmate_black()) {
                            move(set_i, set_j, get_i, get_j);
                            return false;
                        }
                        return true;
                    } //end right-down

                } //endif cross step
            }

            //check step range for king
            if (board[get_i][get_j] == &black.king) {
                if ( (abs(get_i - set_i) == 1 && get_j == set_j) || (abs(get_j - set_j) == 1 && get_i == set_i) ||
                        (abs(get_i - set_i) == 1 && abs(get_j - set_j) == 1) )
                {
                    move(get_i, get_j, set_i, set_j);
                    if (checkmate_black()) {
                        move(set_i, set_j, get_i, get_j);
                        return false;
                    }
                    return true;
                }
            }
        }
    }

    return false;
}

void MainWindow::set_new_board() {
    //initialize dashes with empty -
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            dash[i][j] = empty;
        }
    }

    //set board with dashes
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = &dash[i - 2][j];
        }
    }

    //set white pieces
    for (int i = 0; i < 8; ++i) {
        board[6][i] = &white.pawn[i];
    }

    board[7][0] = &white.rock[0];
    board[7][7] = &white.rock[1];
    board[7][1] = &white.knight[0];
    board[7][6] = &white.knight[1];
    board[7][2] = &white.bishop[0];
    board[7][5] = &white.bishop[1];
    board[7][3] = &white.queen;
    board[7][4] = &white.king;

    //set black pieces
    for (int i = 0; i < 8; ++i) {
        board[1][i] = &black.pawn[i];
    }

    board[0][0] = &black.rock[0];
    board[0][7] = &black.rock[1];
    board[0][1] = &black.knight[0];
    board[0][6] = &black.knight[1];
    board[0][2] = &black.bishop[0];
    board[0][5] = &black.bishop[1];
    board[0][3] = &black.queen;
    board[0][4] = &black.king;
}

bool MainWindow::checkmate_white() {
    int pos_i;
    int pos_j;

    for (int i = 0; i < 8; ++i) { //find location for white king
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == &white.king) {
                pos_i = i;
                pos_j = j;
                break;
            }
        }
    }

    if (pos_i != 0) { //up
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[--tmp_pos_i][tmp_pos_j] == empty) && (tmp_pos_i > 0)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &black.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.rock[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.rock[1]))
        {
            return true;
        }
    }

    if (pos_i != 7) { //down
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[++tmp_pos_i][tmp_pos_j] == empty) && (tmp_pos_i < 7)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &black.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.rock[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.rock[1]))
        {
            return true;
        }
    }

    if (pos_j != 0) { //left
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[tmp_pos_i][--tmp_pos_j] == empty) && (tmp_pos_j > 0)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &black.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.rock[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.rock[1]))
        {
            return true;
        }
    }

    if (pos_j != 7) { //right
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[tmp_pos_i][++tmp_pos_j] == empty) && (tmp_pos_j < 7)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &black.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.rock[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.rock[1]))
        {
            return true;
        }
    }

    if (pos_i != 0 && pos_j != 0) { //left-up
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[--tmp_pos_i][--tmp_pos_j] == empty)
            && (tmp_pos_i > 0)
            && (tmp_pos_j > 0)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &black.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.bishop[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.bishop[1]))
        {
            return true;
        }

        for (int i = 0; i < 7; ++i) {
            if (board[pos_i - 1][pos_j - 1] == &black.pawn[i]) {
                return true;
            }
        }
    }

    if (pos_i != 0 && pos_j != 7) { //right-up
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[--tmp_pos_i][++tmp_pos_j] == empty)
            && (tmp_pos_i > 0)
            && (tmp_pos_j < 7)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &black.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.bishop[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.bishop[1]))
        {
            return true;
        }

        for (int i = 0; i < 7; ++i) {
            if (board[pos_i - 1][pos_j + 1] == &black.pawn[i]) {
                return true;
            }
        }
    }

    if (pos_i != 7 && pos_j != 0) { //left-down
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[++tmp_pos_i][--tmp_pos_j] == empty)
            && (tmp_pos_i < 7)
            && (tmp_pos_j > 0)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &black.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.bishop[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.bishop[1]))
        {
            return true;
        }
    }

    if (pos_i != 7 && pos_j != 7) { //right-down
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[++tmp_pos_i][++tmp_pos_j] == empty)
            && (tmp_pos_i < 7)
            && (tmp_pos_j < 7)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &black.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.bishop[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &black.bishop[1]))
        {
            return true;
        }
    }

    //check knight
    if (pos_i - 1 >= 0 && pos_j - 2 >= 0) { //left-up-1
        if ((board[pos_i - 1][pos_j - 2] == &black.knight[0]) ||
            (board[pos_i - 1][pos_j - 2] == &black.knight[1]))
        {
            return true;
        }
    }

    if (pos_i - 2 >= 0 && pos_j - 1 >= 0) { //left-up-2
        if ((board[pos_i - 2][pos_j - 1] == &black.knight[0]) ||
            (board[pos_i - 2][pos_j - 1] == &black.knight[1]))
        {
            return true;
        }
    }

    if (pos_i - 1 >= 0 && pos_j + 2 <= 7) { //right-up-1
        if ((board[pos_i - 1][pos_j + 2] == &black.knight[0]) ||
            (board[pos_i - 1][pos_j + 2] == &black.knight[1]))
        {
            return true;
        }
    }

    if (pos_i - 2 >= 0 && pos_j + 1 <= 7) { //right-up-2
        if ((board[pos_i - 2][pos_j + 1] == &black.knight[0]) ||
            (board[pos_i - 2][pos_j + 1] == &black.knight[1]))
        {
            return true;
        }
    }

    if (pos_i + 1 <= 7 && pos_j - 2 >= 0) { //left-down-1
        if ((board[pos_i + 1][pos_j - 2] == &black.knight[0]) ||
            (board[pos_i + 1][pos_j - 2] == &black.knight[1]))
        {
            return true;
        }
    }

    if (pos_i + 2 <= 7 && pos_j - 1 >= 0) { //left-down-2
        if ((board[pos_i + 2][pos_j - 1] == &black.knight[0]) ||
            (board[pos_i + 2][pos_j - 1] == &black.knight[1]))
        {
            return true;
        }
    }

    if (pos_i + 1 <= 7 && pos_j + 2 <= 7) { //right-down-1
        if ((board[pos_i + 1][pos_j + 2] == &black.knight[0]) ||
            (board[pos_i + 1][pos_j + 2] == &black.knight[1]))
        {
            return true;
        }
    }

    if (pos_i + 2 <= 7 && pos_j + 1 <= 7) { //right-down-2
        if ((board[pos_i + 2][pos_j + 1] == &black.knight[0]) ||
            (board[pos_i + 2][pos_j + 1] == &black.knight[1]))
        {
            return true;
        }
    }

    return false;
}

bool MainWindow::checkmate_black() {
    int pos_i;
    int pos_j;

    for (int i = 0; i < 8; ++i) { //find location for black king
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == &black.king) {
                pos_i = i;
                pos_j = j;
                break;
            }
        }
    }

    if (pos_i != 0) { //up
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[--tmp_pos_i][tmp_pos_j] == empty) && (tmp_pos_i > 0)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &white.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.rock[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.rock[1]))
        {
            return true;
        }
    }

    if (pos_i != 7) { //down
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[++tmp_pos_i][tmp_pos_j] == empty) && (tmp_pos_i < 7)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &white.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.rock[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.rock[1]))
        {
            return true;
        }
    }

    if (pos_j != 0) { //left
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[tmp_pos_i][--tmp_pos_j] == empty) && (tmp_pos_j > 0)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &white.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.rock[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.rock[1]))
        {
            return true;
        }
    }

    if (pos_j != 7) { //right
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[tmp_pos_i][++tmp_pos_j] == empty) && (tmp_pos_j < 7)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &white.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.rock[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.rock[1]))
        {
            return true;
        }
    }

    if (pos_i != 0 && pos_j != 0) { //left-up
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[--tmp_pos_i][--tmp_pos_j] == empty)
            && (tmp_pos_i > 0)
            && (tmp_pos_j > 0)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &white.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.bishop[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.bishop[1]))
        {
            return true;
        }
    }

    if (pos_i != 0 && pos_j != 7) { //right-up
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[--tmp_pos_i][++tmp_pos_j] == empty)
            && (tmp_pos_i > 0)
            && (tmp_pos_j < 7)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &white.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.bishop[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.bishop[1]))
        {
            return true;
        }
    }

    if (pos_i != 7 && pos_j != 0) { //left-down
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[++tmp_pos_i][--tmp_pos_j] == empty)
            && (tmp_pos_i < 7)
            && (tmp_pos_j > 0)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &white.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.bishop[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.bishop[1]))
        {
            return true;
        }

        for (int i = 0; i < 7; ++i) {
            if (board[pos_i + 1][pos_j - 1] == &white.pawn[i]) {
                return true;
            }
        }
    }

    if (pos_i != 7 && pos_j != 7) { //right-down
        int tmp_pos_i = pos_i;
        int tmp_pos_j = pos_j;

        while ((*board[++tmp_pos_i][++tmp_pos_j] == empty)
            && (tmp_pos_i < 7)
            && (tmp_pos_j < 7)) {}

        if ((board[tmp_pos_i][tmp_pos_j] == &white.queen) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.bishop[0]) ||
            (board[tmp_pos_i][tmp_pos_j] == &white.bishop[1]))
        {
            return true;
        }

        for (int i = 0; i < 7; ++i) {
            if (board[pos_i + 1][pos_j + 1] == &white.pawn[i]) {
                return true;
            }
        }
    }

    //check knight
    if (pos_i - 1 >= 0 && pos_j - 2 >= 0) { //left-up-1
        if ((board[pos_i - 1][pos_j - 2] == &white.knight[0]) ||
            (board[pos_i - 1][pos_j - 2] == &white.knight[1]))
        {
            return true;
        }
    }

    if (pos_i - 2 >= 0 && pos_j - 1 >= 0) { //left-up-2
        if ((board[pos_i - 2][pos_j - 1] == &white.knight[0]) ||
            (board[pos_i - 2][pos_j - 1] == &white.knight[1]))
        {
            return true;
        }
    }

    if (pos_i - 1 >= 0 && pos_j + 2 <= 7) { //right-up-1
        if ((board[pos_i - 1][pos_j + 2] == &white.knight[0]) ||
            (board[pos_i - 1][pos_j + 2] == &white.knight[1]))
        {
            return true;
        }
    }

    if (pos_i - 2 >= 0 && pos_j + 1 <= 7) { //right-up-2
        if ((board[pos_i - 2][pos_j + 1] == &white.knight[0]) ||
            (board[pos_i - 2][pos_j + 1] == &white.knight[1]))
        {
            return true;
        }
    }

    if (pos_i + 1 <= 7 && pos_j - 2 >= 0) { //left-down-1
        if ((board[pos_i + 1][pos_j - 2] == &white.knight[0]) ||
            (board[pos_i + 1][pos_j - 2] == &white.knight[1]))
        {
            return true;
        }
    }

    if (pos_i + 2 <= 7 && pos_j - 1 >= 0) { //left-down-2
        if ((board[pos_i + 2][pos_j - 1] == &white.knight[0]) ||
            (board[pos_i + 2][pos_j - 1] == &white.knight[1]))
        {
            return true;
        }
    }

    if (pos_i + 1 <= 7 && pos_j + 2 <= 7) { //right-down-1
        if ((board[pos_i + 1][pos_j + 2] == &white.knight[0]) ||
            (board[pos_i + 1][pos_j + 2] == &white.knight[1]))
        {
            return true;
        }
    }

    if (pos_i + 2 <= 7 && pos_j + 1 <= 7) { //right-down-2
        if ((board[pos_i + 2][pos_j + 1] == &white.knight[0]) ||
            (board[pos_i + 2][pos_j + 1] == &white.knight[1]))
        {
            return true;
        }
    }

    return false;
}

void MainWindow::move(int get_i, int get_j, int set_i, int set_j) {
    board[set_i][set_j] = board[get_i][get_j];
    board[get_i][get_j] = &dash[get_i][get_j];

    QIcon tmp = button_board[get_i][get_j]->icon();
    button_board[set_i][set_j]->setIcon(tmp);
    button_board[get_i][get_j]->setIcon(empty_icon);

    if (checkmate_white()) {
        ui->current_player_button->setText("Check white");
        ui->current_player_button->setStyleSheet("color: black;\n"
                                                "background-color: none;\n"
                                                "border-style: outset;");
    }
    else if (checkmate_black()) {
        ui->current_player_button->setText("Check black");
        ui->current_player_button->setStyleSheet("color: white;\n"
                                                "background-color: none;\n"
                                                "border-style: outset;");
    }
    else {
        ui->current_player_button->setText("");
    }
}

void MainWindow::on_current_player_button_clicked()
{
    if (ui->current_player_button->text() == "Check white") {
        QMessageBox::information(this, "End Game", "Black Win");

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                button_board[i][j]->disconnect();
            }
        }
    }
    if (ui->current_player_button->text() == "Check black") {
        QMessageBox::information(this, "End Game", "White Win");

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                button_board[i][j]->disconnect();
            }
        }
    }
}
