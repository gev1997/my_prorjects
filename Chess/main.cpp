#include <iostream>
#include <locale>
#include <string>
#include <cstdlib>

#include "chess_class.h"
#include "chess_implement.h"

int main() {
    std::locale::global(std::locale("en_US.utf8"));
    std::wcout.imbue(std::locale());

	chess_board chess;

	return 0;
}