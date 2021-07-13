#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _data.push_back(std::make_pair("bool", false));
    _data.push_back(std::make_pair("int", false));
    _data.push_back(std::make_pair("long", false));
    _data.push_back(std::make_pair("char", false));
    _data.push_back(std::make_pair("float", false));
    _data.push_back(std::make_pair("void", false));

    _data.push_back(std::make_pair("vector", false));
    _data.push_back(std::make_pair("string", false));
    _data.push_back(std::make_pair("forward_list", false));
    _data.push_back(std::make_pair("list", false));
    _data.push_back(std::make_pair("map", false));
    _data.push_back(std::make_pair("set", false));
    _data.push_back(std::make_pair("deque", false));
    _data.push_back(std::make_pair("priority queue", false));
    _data.push_back(std::make_pair("bitset", false));
    _data.push_back(std::make_pair("stack(container)", false));
    _data.push_back(std::make_pair("algorithm", false));
    _data.push_back(std::make_pair("iterator", false));
    _data.push_back(std::make_pair("STL", false));
    _data.push_back(std::make_pair("allocator", false));

    _data.push_back(std::make_pair("accumulate()", false));
    _data.push_back(std::make_pair("islower()", false));
    _data.push_back(std::make_pair("isdigit()", false));
    _data.push_back(std::make_pair("stoi()", false));
    _data.push_back(std::make_pair("malloc()", false));
    _data.push_back(std::make_pair("free()", false));
    _data.push_back(std::make_pair("seekg()", false));

    _data.push_back(std::make_pair("initializer_list", false));
    _data.push_back(std::make_pair("optional", false));
    _data.push_back(std::make_pair("auto_ptr", false));
    _data.push_back(std::make_pair("unique_ptr", false));
    _data.push_back(std::make_pair("shared_ptr", false));
    _data.push_back(std::make_pair("mutex", false));
    _data.push_back(std::make_pair("thread", false));
    _data.push_back(std::make_pair("atomic", false));
    _data.push_back(std::make_pair("exception", false));
    _data.push_back(std::make_pair("tuple", false));
    _data.push_back(std::make_pair("pair", false));
    _data.push_back(std::make_pair("lambda", false));
    _data.push_back(std::make_pair("cout", false));

    _data.push_back(std::make_pair("class", false));
    _data.push_back(std::make_pair("struct", false));
    _data.push_back(std::make_pair("union", false));
    _data.push_back(std::make_pair("enum class", false));
    _data.push_back(std::make_pair("enum", false));
    _data.push_back(std::make_pair("for", false));
    _data.push_back(std::make_pair("while", false));
    _data.push_back(std::make_pair("template", false));
    _data.push_back(std::make_pair("typedef", false));
    _data.push_back(std::make_pair("typename", false));
    _data.push_back(std::make_pair("using", false));
    _data.push_back(std::make_pair("auto", false));
    _data.push_back(std::make_pair("decltype", false));
    _data.push_back(std::make_pair("volatile", false));
    _data.push_back(std::make_pair("static", false));
    _data.push_back(std::make_pair("mutable", false));
    _data.push_back(std::make_pair("virtual", false));
    _data.push_back(std::make_pair("override", false));
    _data.push_back(std::make_pair("final", false));
    _data.push_back(std::make_pair("define", false));
    _data.push_back(std::make_pair("namespace", false));
    _data.push_back(std::make_pair("std", false));
    _data.push_back(std::make_pair("operator", false));
    _data.push_back(std::make_pair("operator new", false));
    _data.push_back(std::make_pair("operator ->", false));
    _data.push_back(std::make_pair("operator *", false));
    _data.push_back(std::make_pair("main", false));
    _data.push_back(std::make_pair("continue", false));
    _data.push_back(std::make_pair("break", false));
    _data.push_back(std::make_pair("if", false));
    _data.push_back(std::make_pair("else", false));
    _data.push_back(std::make_pair("explicit", false));
    _data.push_back(std::make_pair("friend", false));
    _data.push_back(std::make_pair("goto", false));
    _data.push_back(std::make_pair("inline", false));
    _data.push_back(std::make_pair("noexcept", false));
    _data.push_back(std::make_pair("nullptr", false));
    _data.push_back(std::make_pair("private", false));
    _data.push_back(std::make_pair("public", false));
    _data.push_back(std::make_pair("protected", false));
    _data.push_back(std::make_pair("return", false));
    _data.push_back(std::make_pair("switch", false));
    _data.push_back(std::make_pair("case", false));
    _data.push_back(std::make_pair("signed", false));
    _data.push_back(std::make_pair("unsigned", false));
    _data.push_back(std::make_pair("throw", false));
    _data.push_back(std::make_pair("[[nodiscard]]", false));
    _data.push_back(std::make_pair("[[maybe_unused]]", false));
    _data.push_back(std::make_pair("static_assert", false));
    _data.push_back(std::make_pair("NRVO", false));
    _data.push_back(std::make_pair("[[maybe_unused]]", false));

    _data.push_back(std::make_pair("header", false));
    _data.push_back(std::make_pair("iostream", false));
    _data.push_back(std::make_pair("cmath", false));
    _data.push_back(std::make_pair("memory", false));
    _data.push_back(std::make_pair("ratio", false));
    _data.push_back(std::make_pair("type_traits", false));
    _data.push_back(std::make_pair("cstdlib", false));
    _data.push_back(std::make_pair("fstream", false));

    _data.push_back(std::make_pair("bad_alloc", false));
    _data.push_back(std::make_pair("bad_variant_access", false));
    _data.push_back(std::make_pair("bad_any_cast", false));

    _data.push_back(std::make_pair("cast", false));
    _data.push_back(std::make_pair("const_cast", false));
    _data.push_back(std::make_pair("static_cast", false));
    _data.push_back(std::make_pair("any_cast", false));
    _data.push_back(std::make_pair("dynamic_cast", false));
    _data.push_back(std::make_pair("reinterpret_cast", false));


    _data.push_back(std::make_pair("ASCII", false));
    _data.push_back(std::make_pair("C++", false));
    _data.push_back(std::make_pair("compile", false));
    _data.push_back(std::make_pair(".cpp", false));
    _data.push_back(std::make_pair("interpreter", false));
    _data.push_back(std::make_pair("ALU", false));
    _data.push_back(std::make_pair("Mayers", false));
    _data.push_back(std::make_pair("CPU", false));
    _data.push_back(std::make_pair("vptr", false));
    _data.push_back(std::make_pair("execute", false));
    _data.push_back(std::make_pair("function", false));
    _data.push_back(std::make_pair("JS", false));
    _data.push_back(std::make_pair("C#", false));
    _data.push_back(std::make_pair("transistor", false));
    _data.push_back(std::make_pair("heap", false));
    _data.push_back(std::make_pair("process ID", false));
    _data.push_back(std::make_pair("EAX", false));
    _data.push_back(std::make_pair("address bus", false));
    _data.push_back(std::make_pair("data bus", false));
    _data.push_back(std::make_pair("Josuttis", false));
    _data.push_back(std::make_pair("RAM", false));
    _data.push_back(std::make_pair("HDD", false));
    _data.push_back(std::make_pair("low level", false));
    _data.push_back(std::make_pair("boost", false));
    _data.push_back(std::make_pair("TR1", false));
    _data.push_back(std::make_pair("dynamic library", false));
    _data.push_back(std::make_pair("double free", false));
    _data.push_back(std::make_pair("person", false));
    _data.push_back(std::make_pair("realloc", false));
    _data.push_back(std::make_pair("register", false));
    _data.push_back(std::make_pair("stream", false));
    _data.push_back(std::make_pair("move_ctor", false));
    _data.push_back(std::make_pair("this", false));
    _data.push_back(std::make_pair("BIOS", false));
    _data.push_back(std::make_pair("erase(remove)", false));
    _data.push_back(std::make_pair("copy(swap)", false));
    _data.push_back(std::make_pair("Grid algorithm", false));
    _data.push_back(std::make_pair("copy_ctor", false));
    _data.push_back(std::make_pair("pointer", false));
    _data.push_back(std::make_pair("decrement", false));
    _data.push_back(std::make_pair("increment", false));
    _data.push_back(std::make_pair("abstract class", false));
    _data.push_back(std::make_pair("interface class", false));
    _data.push_back(std::make_pair("polymorphism", false));
    _data.push_back(std::make_pair("optimization", false));
    _data.push_back(std::make_pair("Linux", false));
    _data.push_back(std::make_pair("Gnome", false));
    _data.push_back(std::make_pair("Windows", false));
    _data.push_back(std::make_pair("Vim", false));
    _data.push_back(std::make_pair("Keyboard", false));
    _data.push_back(std::make_pair("BST", false));
    _data.push_back(std::make_pair("c++17", false));
    _data.push_back(std::make_pair("undefined", false));

    //bool flags for buttons (is clicked)
    is_word_clicked.fill(false);
}

MainWindow::~MainWindow() {
    delete ui;

    delete current_team_label;
    delete current_point_label;

    delete timer_label;
    delete timer_object;

    for (int i = 0; i < 5; ++i) {
        delete word[i];
    }

    delete continue_game;

    for (int i = 0; i < 2; ++i) {
        delete team_labels[i];
        delete team_points[i];
    }

    delete winner_background_color;
}

void MainWindow::on_startGame_clicked() {
    delete ui->startGame;
    delete ui->gameTitle;

    timer_object = new QTimer(this);
    connect(timer_object, SIGNAL(timeout()), this, SLOT(timer_update()));
    timer_object->start(1000);

    current_team_label = new QLabel(this);
    current_team_label->setObjectName(QString::fromUtf8("point_label"));
    current_team_label->setGeometry(QRect(65, 20, 110, 40));
    current_team_label->setStyleSheet("font-size: 30px; color: rgb(237, 212, 0);");
    current_team_label->setText("Team 1");

    current_point_label = new QLabel(this);
    current_point_label->setObjectName(QString::fromUtf8("point_label"));
    current_point_label->setGeometry(QRect(125, 350, 50, 40));
    current_point_label->setStyleSheet("font-size: 40px; color: rgb(237, 212, 0);");
    current_point_label->setAlignment(Qt::AlignCenter);
    current_point_label->setText("0");

    timer_label = new QLabel(this);
    timer_label->setObjectName(QString::fromUtf8("timer_label"));
    timer_label->setGeometry(QRect(175, 10, 60, 50));
    timer_label->setStyleSheet("font-size: 50px; color: rgb(237, 212, 0);");
    timer_label->setAlignment(Qt::AlignRight);
    timer_label->setText(QString::number(timer_point));

    for (int i = 0; i < 5; ++i) {
        word[i] = new QPushButton(this);
        word[i]->setObjectName(QString::fromUtf8("word_" + std::to_string(i)));
        word[i]->setStyleSheet("background-color: rgb(237, 212, 0); font-size: 20px;");
    }
    word[0]->setGeometry(QRect(35, 80, 230, 50));
    word[1]->setGeometry(QRect(35, 130, 230, 50));
    word[2]->setGeometry(QRect(35, 180, 230, 50));
    word[3]->setGeometry(QRect(35, 230, 230, 50));
    word[4]->setGeometry(QRect(35, 280, 230, 50));

    connect(word[0], SIGNAL(clicked()), this, SLOT(on_word_0_clicked()));
    connect(word[1], SIGNAL(clicked()), this, SLOT(on_word_1_clicked()));
    connect(word[2], SIGNAL(clicked()), this, SLOT(on_word_2_clicked()));
    connect(word[3], SIGNAL(clicked()), this, SLOT(on_word_3_clicked()));
    connect(word[4], SIGNAL(clicked()), this, SLOT(on_word_4_clicked()));

    word_random_render();

    continue_game = new QPushButton(this);
    continue_game->setObjectName(QString::fromUtf8("continue_game"));
    continue_game->setGeometry(QRect(35, 350, 230, 50));
    continue_game->setStyleSheet("background-color: rgb(237, 212, 0); color: rgb(52, 42, 58); font-size: 30px; border-radius: 20px;");
    continue_game->setText("Continue");
    connect(continue_game, SIGNAL(clicked()), this, SLOT(on_continue_game_clicked()));

    team_labels[0] = new QLabel(this);
    team_labels[0]->setObjectName(QString::fromUtf8("team_labels_1"));
    team_labels[0]->setGeometry(QRect(30, 40, 100, 50));
    team_labels[0]->setStyleSheet("background:transparent; color: rgb(237, 212, 0); font-size: 30px;");
    team_labels[0]->setText("Team 1");

    team_labels[1] = new QLabel(this);
    team_labels[1]->setObjectName(QString::fromUtf8("team_labels_2"));
    team_labels[1]->setGeometry(QRect(30, 90, 100, 50));
    team_labels[1]->setStyleSheet("background:transparent; color: rgb(237, 212, 0); font-size: 30px;");
    team_labels[1]->setText("Team 2");


    team_points[0] = new QLabel(this);
    team_points[0]->setObjectName(QString::fromUtf8("team_points_1"));
    team_points[0]->setGeometry(QRect(220, 50, 50, 40));
    team_points[0]->setStyleSheet("background:transparent; color: rgb(237, 212, 0); font-size: 30px;");
    team_points[0]->setAlignment(Qt::AlignRight);
    team_points[0]->setText("0");

    team_points[1] = new QLabel(this);
    team_points[1]->setObjectName(QString::fromUtf8("team_points_2"));
    team_points[1]->setGeometry(QRect(220, 100, 50, 40));
    team_points[1]->setStyleSheet("background:transparent; color: rgb(237, 212, 0); font-size: 30px;");
    team_points[1]->setAlignment(Qt::AlignRight);
    team_points[1]->setText("0");

    winner_background_color = new QPushButton(this);
    winner_background_color->setObjectName(QString::fromUtf8("winner_background_color"));
    winner_background_color->setStyleSheet("background-color: green; border-radius: 20px;");

    show_buttons();
}

void MainWindow::word_random_render() {
    word_erase();

    for (int i = 0; i < 5; ++i) {
        auto index = QRandomGenerator::global()->bounded(_data.size());

        if (_data[index].second == true) {
            --i;
        }
        else if (_data[index].second == false) {
            _data[index].second = true;
            random_render_index[i] = index;
            word[i]->setText(_data[index].first);
        }
    }
}

void MainWindow::word_erase() {
    for (int i = 0; i < 5; ++i) {
        if (is_word_clicked[i] == true) {
            _data[random_render_index[i]].second = true;
        }
    }
}

void MainWindow::word_click(int word_number) {
    if (is_word_clicked[word_number] == false) {
        word[word_number]->setStyleSheet("background-color: green; font-size: 20px;");
        ++point;
    }
    else {
        word[word_number]->setStyleSheet("background-color: rgb(237, 212, 0); font-size: 20px;");
        --point;
    }

    current_point_label->setText(QString::number(point));

    is_word_clicked[word_number] = !is_word_clicked[word_number];
    _data[random_render_index[word_number]].second = !_data[random_render_index[word_number]].second;

    auto is_all_word_clicked = [&]()->bool {
        for (int i = 0; i < 5; ++i) {
            if (is_word_clicked[i] == false) {
                return false;
            }
        }

        return true;
    };

    if (is_all_word_clicked()) {
        word_random_render();

        for (int i = 0; i < 5; ++i) {
            is_word_clicked[i] = false;
            word[i]->setStyleSheet("background-color: rgb(237, 212, 0); font-size: 20px;");
        }        
    }
}

void MainWindow::timer_update() {
    timer_label->setText(QString::number(timer_point));

    if (timer_point == 0) {
        timer_object->stop();

        if (turn % 2 == 0) {
            points[0] += point;
        }
        else {
            points[1] += point;
        }

        hide_buttons();

        team_labels[0]->show();
        team_labels[1]->show();

        team_points[0]->setText(QString::number(points[0]));
        team_points[1]->setText(QString::number(points[1]));

        team_points[0]->show();
        team_points[1]->show();

        if (points[0] >= end_game_point) {
            end_game(0);
        }
        else if (points[1] >= end_game_point) {
            end_game(1);
        }
        else {
            continue_game->show();
        }

        word_erase();
    }

    --timer_point;
}

void MainWindow::on_continue_game_clicked() {
    timer_point = 45;
    ++turn;

    word_random_render();

    reset_buttons();
    show_buttons();

    timer_object->start(1000);

    continue_game->hide();
    team_labels[0]->hide();
    team_labels[1]->hide();
    team_points[0]->hide();
    team_points[1]->hide();
}

void MainWindow::show_buttons() {
    if (turn % 2 == 0) {
        current_team_label->setText("Team 1");
    }
    else {
        current_team_label->setText("Team 2");
    }

    current_team_label->show();
    current_point_label->show();
    timer_label->show();

    for (int i = 0; i < 5; ++i) {
        word[i]->show();
    }
}

void MainWindow::hide_buttons() {
    current_team_label->hide();
    current_point_label->hide();
    timer_label->hide();

    for (int i = 0; i < 5; ++i) {
        word[i]->hide();
    }
}

void MainWindow::reset_buttons() {
    for (int i = 0; i < 5; ++i) {
        is_word_clicked[i] = false;
        word[i]->setStyleSheet("background-color: rgb(237, 212, 0); font-size: 20px;");
    }

    point = 0;
    current_point_label->setText("0");
}

void MainWindow::end_game(int player) {
    team_labels[0]->setGeometry(QRect(30, 120, 100, 50));
    team_labels[1]->setGeometry(QRect(30, 170, 100, 50));
    team_points[0]->setGeometry(QRect(220, 130, 50, 40));
    team_points[1]->setGeometry(QRect(220, 180, 50, 40));

    team_labels[0]->raise();
    team_labels[1]->raise();
    team_points[0]->raise();
    team_points[1]->raise();

    winner_background_color->show();

    if (player == 0) {
        winner_background_color->setGeometry(QRect(20, 120, 260, 50));

        team_labels[0]->setGeometry(QRect(60, 120, 110, 50));
        team_points[0]->setGeometry(QRect(190, 125, 50, 40));

        team_labels[0]->setStyleSheet("background:transparent; color: rgb(237, 212, 0); font-size: 35px;");
        team_points[0]->setStyleSheet("background:transparent; color: rgb(237, 212, 0); font-size: 35px;");
    }
    else if (player == 1) {
        winner_background_color->setGeometry(QRect(20, 170, 260, 50));

        team_labels[1]->setGeometry(QRect(60, 170, 110, 50));
        team_points[1]->setGeometry(QRect(190, 175, 50, 40));

        team_labels[1]->setStyleSheet("background:transparent; color: rgb(237, 212, 0); font-size: 35px;");
        team_points[1]->setStyleSheet("background:transparent; color: rgb(237, 212, 0); font-size: 35px;");
    }
}

void MainWindow::on_word_0_clicked() { word_click(0); }
void MainWindow::on_word_1_clicked() { word_click(1); }
void MainWindow::on_word_2_clicked() { word_click(2); }
void MainWindow::on_word_3_clicked() { word_click(3); }
void MainWindow::on_word_4_clicked() { word_click(4); }
