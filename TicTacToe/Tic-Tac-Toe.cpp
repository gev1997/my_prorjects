#include <iostream>

#define RC   "\033[0m"			/*Reset*/
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */

void new_game(int);
bool set_X_O(int, const char);
void set_O_single();
void new_board(const char T);
void end_game(int, int);

char board[3][3] = { {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'} };
const char x = 'X';
const char o = 'O';
int count_x = 0;
int count_o = 0;

int main() {
    int single_or_multi;
    std::cout << GREEN "-----------New Game---------\n" RC;
    std::cout << YELLOW "Single - 1, Multiplayer - 2: " RC;
    std::cin >> single_or_multi;

    if (single_or_multi == 1) {
        system("CLS");
        new_game(1);
    }
    else if (single_or_multi == 2) {
        system("CLS");
        new_game(2);
    }
    
    return 0;
}

void new_game(int single_or_multi) {
    int position;
    std::cout << YELLOW "Enter position of X, 1...9." RC << std::endl;
    std::cout << GREEN "\tX - " YELLOW << count_x
        << GREEN "  O - " YELLOW << count_o << RC << std::endl;

    while (true) {
        new_board(x);

        std::cin >> position;
        if (position == 0) { std::cout << YELLOW "Good bye!" RC; break; }
        else if (position < 0 || position > 9) { std::cout << RED "Enter position again\n" RC; continue; }

        //Write X in inputted position
        if (set_X_O(position, x)) { continue; }

        //Checking lines of X
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == x) && (board[i][1] == x) && (board[i][2] == x)) { end_game(1, single_or_multi); return; }
            else if ((board[0][i] == x) && (board[1][i] == x) && (board[2][i] == x)) { end_game(1, single_or_multi); return; }
        }

        if ((board[0][0] == x) && (board[1][1] == x) && (board[2][2] == x)) { end_game(1, single_or_multi); return; }
        else if ((board[2][0] == x) && (board[1][1] == x) && (board[0][2] == x)) { end_game(1, single_or_multi); return; }

        //Check if no-one win.
        else if (board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' && board[1][0] != '-' && board[1][1] != '-' && board[1][2] != '-' && board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-') {
            end_game(0, single_or_multi); return;
        }
        
        //Single or multiplayer
        if (single_or_multi == 1) {
            set_O_single(); //single
        } else {
            new_board(o);
            std::cin >> position;
            if (set_X_O(position, o)) { continue; } //multiplayer
        }        

        //Checking lines of O
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == o) && (board[i][1] == o) && (board[i][2] == o)) { end_game(2, single_or_multi); return; }
            else if ((board[0][i] == o) && (board[1][i] == o) && (board[2][i] == o)) { end_game(2, single_or_multi); return; }
        }

        if ((board[0][0] == o) && (board[1][1] == o) && (board[2][2] == o)) { end_game(2, single_or_multi); return; }
        else if ((board[2][0] == o) && (board[1][1] == o) && (board[0][2] == o)) { end_game(2, single_or_multi); return; }
    }
}

bool set_X_O(int position, const char T) {
    switch (position) {
    case 1:
        if (board[0][0] == x || board[0][0] == o) { std::cout << RED "Enter another position\n" RC; return true; }
        else { board[0][0] = T; }
        break;

    case 2:
        if (board[0][1] == x || board[0][1] == o) { std::cout << RED "Enter another position\n" RC; return true; }
        else { board[0][1] = T; }
        break;

    case 3:
        if (board[0][2] == x || board[0][2] == o) { std::cout << RED "Enter another position\n" RC; return true; }
        else { board[0][2] = T; }
        break;

    case 4:
        if (board[1][0] == x || board[1][0] == o) { std::cout << RED "Enter another position\n" RC; return true; }
        else { board[1][0] = T; }
        break;

    case 5:
        if (board[1][1] == x || board[1][1] == o) { std::cout << RED "Enter another position\n" RC; return true; }
        else { board[1][1] = T; }
        break;

    case 6:
        if (board[1][2] == x || board[1][2] == o) { std::cout << RED "Enter another position\n" RC; return true; }
        else { board[1][2] = T; }
        break;

    case 7:
        if (board[2][0] == x || board[2][0] == o) { std::cout << RED "Enter another position\n" RC; return true; }
        else { board[2][0] = T; }
        break;

    case 8:
        if (board[2][1] == x || board[2][1] == o) { std::cout << RED "Enter another position\n" RC; return true; }
        else { board[2][1] = T; }
        break;

    case 9:
        if (board[2][2] == x || board[2][2] == o) { std::cout << RED "Enter another position\n" RC; return true; }
        else { board[2][2] = T; }
        break;
    }

    return false;
}

void set_O_single() {
    int column = rand() % 3;
    int row = rand() % 3;
    while (board[column][row] == x || board[column][row] == o) {
        column = rand() % 3;
        row = rand() % 3;
    }
    board[column][row] = o;
}

void new_board(const char T) {
    system("CLS");
    std::cout << YELLOW "Enter position of " << T <<", 1...9." RC << std::endl;
    std::cout << GREEN "\tX - " YELLOW << count_x
        << GREEN "  O - " YELLOW << count_o << RC
        << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << YELLOW "\t   |" RC;
        for (int j = 0; j < 3; j++) {
            switch (board[i][j]) {
            case x:
                std::cout << GREEN << board[i][j] << YELLOW "|" RC;
                break;

            case o:
                std::cout << YELLOW << board[i][j] << "|" RC;
                break;

            default:
                std::cout << YELLOW << board[i][j] << "|" RC;
                break;
            }
        }
        std::cout << std::endl;
    }
    return;
}

void end_game(int n, int single_or_multi) {
    new_board(x);

    switch (n) {
    case 0:
        std::cout << "\nNo one Wins!!! Do you want to start a new game? y/n";
        break;

    case 1:
        std::cout << GREEN "\nX Win!!! Do you want to start a new game? y/n " RC;
        ++count_x;
        break;

    case 2:
        std::cout << YELLOW "\nO Win!!! Do you want to start a new game? y/n " RC;
        ++count_o;
        break;
    }

    char new_game_char;

    //LABEL
new_game_statement:;
    std::cin >> new_game_char;
    switch (new_game_char) {
    case 'y':
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = '-';
            }
        }
        system("CLS");
        new_game(single_or_multi);
        break;

    case 'n':
        std::cout << YELLOW "Good bye!" RC;
        break;

    default:
        std::cout << RED "Enter 'y' or 'n' " RC; goto new_game_statement;
        break;
    }

    return;
}
