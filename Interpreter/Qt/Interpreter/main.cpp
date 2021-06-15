#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QString>
#include <QVector>

void variable(QString&);
void print(QString&);
void loop(QString&, int);
void compare(QString&, QString&, int&,  QWidget*);
void initialize(QString&, QString&, QWidget*);

QString instruction[] = { "variable", "print", "loop", "compare" }; //Instructions
QVector<QString> text_lines; //All the file text
QVector<QString> var_names; //Declarated variables names
QVector<int> var_values; //Declarated variables values

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(520, 450);
    w.setStyleSheet("background-color: #e5e9ff");

    w.show();

    return a.exec();
}

void MainWindow::on_pushButton_clicked() {
    ui->plainTextEdit_2->clear();

    QString tmp_all_text = ui->plainTextEdit->toPlainText();
    tmp_all_text += "\n";

    int text_lines_count = 0; //Lines count
    for(int i = 0; i < tmp_all_text.size(); ++i) {
        if(tmp_all_text[i] == '\n') { ++text_lines_count; }
    }

    for(int i = 0; i < text_lines_count; ++i) {
        QString tmp_text_lines;

        int j = 0;
        while(tmp_all_text[j] != '\n'){
            tmp_text_lines += tmp_all_text[j];
            ++j;
        }
        tmp_all_text.remove(0, j + 1);

        text_lines.push_back(tmp_text_lines);
    }

    //Start
    for(int i = 0; i < text_lines_count; ++i) {
        if (text_lines[i] == "") { continue; }

        QString tmp_text_lines = text_lines[i];
        QString tmp_text_word;

        int letter_count = 0;
        for (int j = 0; tmp_text_lines[j] != ' '; ++j) {
            tmp_text_word += tmp_text_lines[j];
            ++letter_count;
        }
        tmp_text_lines.remove(0, letter_count + 1);

        //check if variable
        if (tmp_text_word == instruction[0]) {
            variable(tmp_text_lines);
        }

        //check if print
        else if (tmp_text_word == instruction[1]) {
            print(tmp_text_lines);
        }

        //check if loop
        else if (tmp_text_word == instruction[2]) {

            tmp_text_word.remove(0, tmp_text_word.size()); //erase tmp_text_word
            int s_to_int = tmp_text_lines.toInt();

            ++i;
            tmp_text_lines = text_lines[i];

            int letter_count = 0;
            for (int j = 0; tmp_text_lines[j] != ' ' && tmp_text_lines[j] != '\n'; ++j) {
                tmp_text_word += tmp_text_lines[j];
                ++letter_count;
            }
            tmp_text_lines.remove(0, letter_count); //es masum problema taris, menak PRINT mutq aneluc
            if(!tmp_text_lines.isEmpty()) {
                tmp_text_lines.remove(0, 1);
            }
            else {
                tmp_text_lines = "";
            }

            if (tmp_text_word == "print") {
                loop(tmp_text_lines, s_to_int);
            } else {
                QMessageBox::information(this, "Compile error", "Not a print function after loop! ");
            }
        }

        //check if compare
        else if (tmp_text_word == instruction[3]) {
            compare(tmp_text_lines, tmp_text_word, i, this);
        }

        //initialize
        else {
            initialize(tmp_text_lines, tmp_text_word, this);
        }
    }

    text_lines.clear();
    var_names.clear();
    var_values.clear();
}

void MainWindow::variable(QString& tmp_text_lines) {
    QString tmp_text_var_name;
    QString tmp_text_var_value;

    //save variables
    int letter_count = 0;
    for (int j = 0; tmp_text_lines[j] != ' '; ++j) {
        tmp_text_var_name += tmp_text_lines[j];
        ++letter_count;
    }
    var_names.push_back(tmp_text_var_name);
    tmp_text_lines.remove(0, letter_count + 1);

    //save values
    int s_to_int = tmp_text_lines.toInt();
    var_values.push_back(s_to_int);
}

void MainWindow::print(QString& tmp_text_lines) {
    bool if_not_have_variables = true;
    for (int j = 0; j < var_names.size(); ++j) {
        if (tmp_text_lines == var_names[j]) {
            ui->plainTextEdit_2->insertPlainText(QString::number(var_values[j]));
            ui->plainTextEdit_2->insertPlainText("\n");
            if_not_have_variables = false;
        }
    }

    if (if_not_have_variables) {
        ui->plainTextEdit_2->insertPlainText("''");
        ui->plainTextEdit_2->insertPlainText(tmp_text_lines);
        ui->plainTextEdit_2->insertPlainText("''");
        ui->plainTextEdit_2->insertPlainText("\n");
    }
}

void MainWindow::loop(QString& tmp_text_lines, int s_to_int) {
    for (int j = 0; j < s_to_int; ++j) {
        print(tmp_text_lines);
    }
}

void MainWindow::compare(QString& tmp_text_lines, QString& tmp_text_word, int& i, QWidget*) {
    QString operand_1, operand_2;
    int operand_1_value = 0;
    int operand_2_value = 0;
    QChar Operator;

    int count = 0;
    for (int k = 0; tmp_text_lines[k] != ' '; ++k) { //operand_1
        operand_1 += tmp_text_lines[k];
        ++count;
    }
    tmp_text_lines.remove(0, count + 1); //erase operand_1 and space

    Operator = tmp_text_lines[0]; //operator = < or >

    tmp_text_lines.remove(0, 2); //erase operator and space

    operand_2 += tmp_text_lines; //operand_2

    bool s1 = true;
    bool s2 = true;

    for (int k = 0; k < var_names.size(); ++k) {
        if (operand_1 == var_names[k]) {
            operand_1_value = var_values[k];
                s1 = false;
        }

        if (operand_2 == var_names[k]) {
            operand_2_value = var_values[k];
            s2 = false;
        }
    }

    if (s1) { operand_1_value = operand_1.toInt(); }
    if (s2) { operand_2_value = operand_2.toInt(); }

    bool compare = false;
    if(Operator == '='){
        if (operand_1_value == operand_2_value) {
            compare = true;
        }
    }
    else if(Operator == '<'){
        if (operand_1_value < operand_2_value) {
            compare = true;
        }
    }
    else if(Operator == '>'){
        if (operand_1_value > operand_2_value) {
            compare = true;
        }
    }
    else{
        QMessageBox::information(this, "Compile error", "Operand isn't correct!");
    }

    tmp_text_word.remove(0, tmp_text_word.size()); //erase tmp_text_word
    ++i;

    tmp_text_lines = text_lines[i];

    if (compare) {
        int letter_count = 0;
        for (int j = 0; tmp_text_lines[j] != ' '; ++j) {
            tmp_text_word += tmp_text_lines[j];
            ++letter_count;
        }
        tmp_text_lines.remove(0, letter_count + 1);

        if (tmp_text_word == "print") {
            print(tmp_text_lines);
        }
        else {
            QMessageBox::information(this, "Compile error", "Not a print function after compare!");
        }
    }
}

void MainWindow::initialize(QString& tmp_text_lines, QString& tmp_text_word, QWidget*) {
    QString operand_1, operand_2, single_operand;
    int operand_1_value = 0;
    int operand_2_value = 0;
    int single_operand_value = 0;
    QChar Operator;

    for (int j = 0; j < var_names.size(); ++j) {
        if (tmp_text_word == var_names[j]) {
            tmp_text_lines.remove(0, 2); //erase =

            bool if_single_operand = true; //Check if operand one or two
            for (int k = 0; k < tmp_text_lines.size(); ++k) {
                if (tmp_text_lines[k] == ' ') {
                    if_single_operand = false;
                }
            }

            if (if_single_operand) { //if operand single
                for (int k = 0; k < tmp_text_lines.size(); ++k) { //operand_1
                    single_operand += tmp_text_lines[k];
                }
                single_operand_value = single_operand.toInt();
                var_values[j] = single_operand_value;
            }
            else { //if operand duble
                int count = 0;
                for (int k = 0; tmp_text_lines[k] != ' '; ++k) { //operand_1
                    operand_1 += tmp_text_lines[k];
                    ++count;
                }
                tmp_text_lines.remove(0, count + 1); //erase operand_1 and space

                Operator = tmp_text_lines[0]; //operator + - * or /

                tmp_text_lines.remove(0, 2); //erase operator and space

                operand_2 += tmp_text_lines; //operand_2

                bool s1 = true;
                bool s2 = true;

                for (int k = 0; k < var_names.size(); ++k) {
                    if (operand_1 == var_names[k]) {
                        operand_1_value = var_values[k];
                        s1 = false;
                    }

                    if (operand_2 == var_names[k]) {
                        operand_2_value = var_values[k];
                        s2 = false;
                    }
                }

                if (s1) { operand_1_value = operand_1.toInt(); }
                if (s2) { operand_2_value = operand_2.toInt(); }

                if(Operator == '+') {
                    var_values[j] = operand_1_value + operand_2_value;
                }
                else if(Operator == '-') {
                    var_values[j] = operand_1_value - operand_2_value;
                }
                else if(Operator == '*') {
                    var_values[j] = operand_1_value * operand_2_value;
                }
                else if(Operator == '/') {
                    var_values[j] = operand_1_value / operand_2_value;
                }
                else {
                    QMessageBox::information(this, "Compile error", "Operand isn't correct!");
                }
            }
        }
    }
}
