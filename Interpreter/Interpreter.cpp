#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void variable(string&);
void print(string&);
void loop(string&, int);
void compare(string&, string&, int&);
void initialize(string&, string&);

string instruction[] = { "variable", "print", "loop", "compare" }; //Instructions
vector<string> var_names; //Declarated variables names
vector<int> var_values; //Declarated variables values
vector<string> text_lines; //All the file text
std::ifstream source_file;

int main() {
    source_file.open("source.txt");
    if (!source_file.is_open()) {
        cout << "Check your file";
    }

    while (!source_file.eof()) {
        string tmp_text_lines;
        std::getline(source_file, tmp_text_lines);
        text_lines.push_back(tmp_text_lines);
    }

    //start
    for (int i = 0; i < text_lines.size(); ++i) {
        if (text_lines[i] == "") { continue; }
        string tmp_text_lines = text_lines[i];
        string tmp_text_word;
        
        int letter_count = 0;
        for (int j = 0; tmp_text_lines[j] != ' '; ++j) {
            tmp_text_word += tmp_text_lines[j];
            ++letter_count;
        }
        tmp_text_lines.erase(0, letter_count + 1);
        
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
            tmp_text_word.erase(tmp_text_word.begin(), tmp_text_word.end()); //erase tmp_text_word
            ++i;
            int s_to_int = std::stoi(tmp_text_lines);
            tmp_text_lines = text_lines[i];

            int letter_count = 0;
            for (int j = 0; tmp_text_lines[j] != ' '; ++j) {
                tmp_text_word += tmp_text_lines[j];
                ++letter_count;
            }
            tmp_text_lines.erase(0, letter_count + 1);

            if (tmp_text_word == "print") {
                loop(tmp_text_lines, s_to_int);
            } 
            else {
                cout << "Compile error, not a print function after loop! " << endl;
            } 
        }

        //check if compare
        else if (tmp_text_word == instruction[3]) {
            compare(tmp_text_lines, tmp_text_word, i);
        }

        //initialize
        else {
            initialize(tmp_text_lines, tmp_text_word);
        }
    }

    cin.get();

    source_file.close();  
    return 0;
}

void variable(string& tmp_text_lines) {
    string tmp_text_var_name;
    string tmp_text_var_value;

    //save variables
    int letter_count = 0;
    for (int j = 0; tmp_text_lines[j] != ' '; ++j) {
        tmp_text_var_name += tmp_text_lines[j];
        ++letter_count;
    }
    var_names.push_back(tmp_text_var_name);
    tmp_text_lines.erase(0, letter_count + 1);

    //save values
    int s_to_int = std::stoi(tmp_text_lines);
    var_values.push_back(s_to_int);
}

void print(string& tmp_text_lines) {
    bool if_not_have_variables = true;
    for (int j = 0; j < var_names.size(); ++j) {
        if (tmp_text_lines == var_names[j]) {
            cout << var_values[j] << endl;
            if_not_have_variables = false;
        }
    }

    if (if_not_have_variables) {
        cout << '"' << tmp_text_lines << '"' << endl;
    }
}

void loop(string& tmp_text_lines, int s_to_int) {
    for (int j = 0; j < s_to_int; ++j) {
        print(tmp_text_lines);
    }
}

void compare(string& tmp_text_lines, string& tmp_text_word, int& i) {
    string operand_1, operand_2;
    int operand_1_value = 0;
    int operand_2_value = 0;
    char Operator;

    int count = 0;
    for (int k = 0; tmp_text_lines[k] != ' '; ++k) { //operand_1
        operand_1 += tmp_text_lines[k];
        ++count;
    }
    tmp_text_lines.erase(0, count + 1); //erase operand_1 and space

    Operator = tmp_text_lines[0]; //operator = < or >

    tmp_text_lines.erase(0, 2); //erase operator and space

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
    if (s1) { operand_1_value = std::stoi(operand_1); }
    if (s2) { operand_2_value = std::stoi(operand_2); }
                
    bool compare = false;
    switch (Operator) {
        case '=':
            if (operand_1_value == operand_2_value) {
                compare = true;
            }       
            break;

        case '<':
            if (operand_1_value < operand_2_value) {
                compare = true;
            }
            break;

        case '>':
            if (operand_1_value > operand_2_value) {
                compare = true;
            }
            break;
        
        default:
            cout << "Operand isn't correct!\n";
            break;
    }        

    tmp_text_word.erase(tmp_text_word.begin(), tmp_text_word.end()); //erase tmp_text_word
    ++i;
    
    tmp_text_lines = text_lines[i];

    if (compare) {
        int letter_count = 0;
        for (int j = 0; tmp_text_lines[j] != ' '; ++j) {
            tmp_text_word += tmp_text_lines[j];
            ++letter_count;
        }
        tmp_text_lines.erase(0, letter_count + 1);

        if (tmp_text_word == "print") {
            print(tmp_text_lines);
        }
        else {
            cout << "Compile error, not a print function after loop! " << endl;
        }
    }  
}

void initialize(string& tmp_text_lines, string& tmp_text_word) {
    string operand_1, operand_2, single_operand;
    int operand_1_value = 0;
    int operand_2_value = 0;
    int single_operand_value = 0;
    char Operator;
    
    for (int j = 0; j < var_names.size(); ++j) {
        if (tmp_text_word == var_names[j]) {
            tmp_text_lines.erase(0, 2); //erase =
            
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
                single_operand_value = std::stoi(single_operand);
                var_values[j] = single_operand_value;
            }
            else { //if operand duble
                int count = 0;
                for (int k = 0; tmp_text_lines[k] != ' '; ++k) { //operand_1
                    operand_1 += tmp_text_lines[k];
                    ++count;
                }
                tmp_text_lines.erase(0, count + 1); //erase operand_1 and space

                Operator = tmp_text_lines[0]; //operator + - * or /

                tmp_text_lines.erase(0, 2); //erase operator and space

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
                if (s1) { operand_1_value = std::stoi(operand_1); }
                if (s2) { operand_2_value = std::stoi(operand_2); }

                switch (Operator) {
                case '+':
                    var_values[j] = operand_1_value + operand_2_value;
                    break;
                case '-':
                    var_values[j] = operand_1_value - operand_2_value;
                    break;
                case '*':
                    var_values[j] = operand_1_value * operand_2_value;
                    break;
                case '/':
                    var_values[j] = operand_1_value / operand_2_value;
                    break;
                default:
                    cout << "Operand isn't correct!\n";
                }
                break;
            }
        }
    }
}
