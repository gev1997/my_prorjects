#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>

#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QVector<std::pair<QString, bool>> _data;

    QLabel* current_team_label = nullptr;
    QLabel* current_point_label = nullptr;

    unsigned int points[2] = {0};
    unsigned int point = 0;
    int turn = 0;

    std::array<bool, 5> is_word_clicked;
    std::array<long long, 5> random_render_index;

    QLabel* timer_label = nullptr;
    QTimer* timer_object = nullptr;
    unsigned int timer_point = 45;

    QPushButton* word[5] = {nullptr};
    QPushButton* continue_game = nullptr;

    QLabel* team_labels[2] = {nullptr};
    QLabel* team_points[2] = {nullptr};

    unsigned int end_game_point = 45;
    QPushButton* winner_background_color = nullptr;

    long long index = 0;

private slots:
    void on_startGame_clicked();

    void word_random_render();
    void word_click(int word_number);
    void word_erase();
    void timer_update();

    void on_continue_game_clicked();

    void show_buttons();
    void hide_buttons();
    void reset_buttons();
    void end_game(int player);

    void on_word_0_clicked();
    void on_word_1_clicked();
    void on_word_2_clicked();
    void on_word_3_clicked();
    void on_word_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
