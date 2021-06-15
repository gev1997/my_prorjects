chess_board::chess_board() {
    start_game();
}

void chess_board::start_game() {
    set_new_board();

    while (true) {
        print_board();

        std::string get_position;
        std::string set_position;

        std::cin >> get_position;

        if (get_position == "mate") {
            if (current_player % 2 == 0) {
                std::wcout << "          " << "\033[1;33m" << "Black Win" << "\033[0m\n\n";
            }
            else {
                std::wcout << "          " << "\033[1;33m" << "White Win" << "\033[0m\n\n";
            }
            break;
        }

        std::cin >> set_position;

        if (check_step(get_position, set_position)) {
            ++current_player;
        }
        else {
            std::wcout << "\a";
        }
    }        
}

void chess_board::set_new_board() {
    //set board with dashes
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = &dash[i - 2][j];
        }
    }

    //initialize pieces
    for (int i = 0; i < 8; ++i) {
        white.pawn[i] = L'\u265F';
        black.pawn[i] = L'\u2659';
    }

    white.queen = L'\u265B';
    white.king = L'\u265A';
    black.queen = L'\u2655';
    black.king = L'\u2654';

    for (int i = 0; i < 2; ++i) {
        white.rock[i] = L'\u265C';
        white.knight[i] = L'\u265E';
        white.bishop[i] = L'\u265D';

        black.rock[i] = L'\u2656';
        black.knight[i] = L'\u2658';
        black.bishop[i] = L'\u2657';
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

void chess_board::print_board() {
    system("clear");

    if (current_player % 2 == 0) {
        for (int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                dash[i][j] = up;
            }
        }
    }
    else {
        for (int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                dash[i][j] = down;
            }
        }
    }

    std::wcout << "   " << L'\u24B6' << " -" << L'\u24B7' << " -" 
                        << L'\u24B8' << " -" << L'\u24B9' << " -"
                        << L'\u24BA' << " -" << L'\u24BB' << " -"
                        << L'\u24BC' << " -" << L'\u24BD' << "  ";
    
    if (current_player % 2 == 0) {
        std::wcout << L'\u231B' << std::endl;
    }
    else {
        std::wcout << L'\u23F3' << std::endl;
    }
    
    std::wcout << " " << L'\u2554';
    for (int i = 0; i < 25; ++i){
        std::wcout << L'\u2500';
    }
    std::wcout << L'\u2557' << std::endl;

    for (int i = 0, x = 8; i < 8; ++i) {
        std::wcout << x << L'\u2502' << " ";

        for (int j = 0; j < 8; ++j) {
            std::wcout << *board[i][j] << "  ";
        }

        std::wcout << L'\u2502' << x-- << std::endl;
    }

    std::wcout << " " << L'\u255A';
    for (int i = 0; i < 25; ++i){
        std::wcout << L'\u2500';
    }
    std::wcout << L'\u255D' << std::endl;

    std::wcout << "   " << L'\u24B6' << " -" << L'\u24B7' << " -" 
                        << L'\u24B8' << " -" << L'\u24B9' << " -"
                        << L'\u24BA' << " -" << L'\u24BB' << " -"
                        << L'\u24BC' << " -" << L'\u24BD' << std::endl;

    if (current_player % 2 == 0) {
        std::wcout << "     Current player White" << std::endl;
    }
    else {
        std::wcout << "     Current player Black" << std::endl;
    }

    if (checkmate_white()) {
        std::wcout << "\033[1;33m" << "Check white" << "\033[0m" << std::endl;
    }
    if (checkmate_black()) {
        std::wcout << "\033[1;33m" << "Check black" << "\033[0m" << std::endl;
    }
}

bool chess_board::check_step(std::string& get_position, std::string& set_position) {
    int get_i = 8 - (get_position[1] - 48);
    int get_j = get_position[0] - 65;

    int set_i = 8 - (set_position[1] - 48);
    int set_j = set_position[0] - 65;

    if (get_i < 0 || get_i > 7 || get_j < 0 || get_j > 7 || 
        set_i < 0 || set_i > 7 || set_j < 0 || set_j > 7) 
    {
        return false;
    }
    
    bool step = false;

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
                    if (get_j == set_j && *board[set_i][set_j] == up) {
                        if ((get_i - set_i == 2 || get_i - set_i == 1) && get_i == 6) {
                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto WHITE_CHECK_END;
                        }
                        if (get_i - set_i == 1) {
                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto WHITE_CHECK_END;
                        }
                    }
                    else if (*board[set_i][set_j] != up && ((get_i - set_i == 1) && (set_j - get_j == 1 || get_j - set_j == 1))) {
                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
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
                            if (*board[tmp_get_i][set_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    }
                    else if (set_i > get_i) { //step down
                        while (tmp_set_i > tmp_get_i + 1) {
                            --tmp_set_i;
                            if (*board[tmp_set_i][set_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    }
                }//endif step vertical

                else if (get_i == set_i) { //if step horizontal
                    int tmp_get_j = get_j;
                    int tmp_set_j = set_j;

                    if (get_j < set_j) { //step right
                        while (tmp_get_j < tmp_set_j - 1) {
                            --tmp_set_j;
                            if (*board[set_i][tmp_set_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    }
                    else if (get_j > set_j) { //step left
                        while (tmp_set_j < tmp_get_j - 1) {
                            --tmp_get_j;
                            if (*board[set_i][tmp_get_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    }
                }//endif step horizontal
            }

            //check step range for knight
            if (board[get_i][get_j] == &white.knight[0] || board[get_i][get_j] == &white.knight[1]) {
                if ( (abs(get_i - set_i) == 2 && abs(get_j - set_j) == 1) ||
                        (abs(get_i - set_i) == 1 && abs(get_j - set_j) == 2) )
                {
                    move(get_i, get_j, set_i, set_j);
                    step = true;
                    goto WHITE_CHECK_END;
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
                            if (*board[--tmp_get_i][--tmp_get_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    }
                    else if ((get_i > set_i) && (get_j < set_j)) { //right-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j < tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][++tmp_get_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    }
                    else if ((get_i < set_i) && (get_j > set_j)) { //left-down
                        while ((tmp_get_i < tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[++tmp_get_i][--tmp_get_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    }
                    else if (((get_i < set_i) && (get_j < set_j))) { //rignt-down
                        while ((tmp_get_i + 1 < tmp_set_i) && (tmp_get_j + 1 < tmp_set_j)) {
                            if (*board[++tmp_get_i][++tmp_get_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
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
                                if (*board[tmp_get_i][set_j] != up) {
                                    step = false;
                                    goto WHITE_CHECK_END;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto WHITE_CHECK_END;
                        }
                        else if (set_i > get_i) { //step down
                            while (tmp_set_i > tmp_get_i + 1) {
                                --tmp_set_i;
                                if (*board[tmp_set_i][set_j] != up) {
                                    step = false;
                                    goto WHITE_CHECK_END;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto WHITE_CHECK_END;
                        }
                    } //endif step vertical

                    else if (get_i == set_i) { //if step horizontal
                        if (get_j < set_j) { //step right
                            while (tmp_get_j < tmp_set_j - 1) {
                                --tmp_set_j;
                                if (*board[set_i][tmp_set_j] != up) {
                                    step = false;
                                    goto WHITE_CHECK_END;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto WHITE_CHECK_END;
                        }
                        else if (get_j > set_j) { //step left
                            while (tmp_set_j < tmp_get_j - 1) {
                                --tmp_get_j;
                                if (*board[set_i][tmp_get_j] != up) {
                                    step = false;
                                    goto WHITE_CHECK_END;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto WHITE_CHECK_END;
                        }
                    } //endif step horizontal

                } //end check vertical-or-horizontal

                if (abs(get_i - set_i) == abs(get_j - set_j)) { //check cross step
                    if ((get_i > set_i) && (get_j > set_j)) { //left-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][--tmp_get_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    } //end left-up

                    else if ((get_i > set_i) && (get_j < set_j)) { //right-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j < tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][++tmp_get_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    } //end right-up

                    else if ((get_i < set_i) && (get_j > set_j)) { //left-down
                        while ((tmp_get_i < tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[++tmp_get_i][--tmp_get_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    } //end left-down

                    else if (((get_i < set_i) && (get_j < set_j))) { //rignt-down
                        while ((tmp_get_i + 1 < tmp_set_i) && (tmp_get_j + 1 < tmp_set_j)) {
                            if (*board[++tmp_get_i][++tmp_get_j] != up) {
                                step = false;
                                goto WHITE_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto WHITE_CHECK_END;
                    } //end right-down

                } //endif cross step   
            }

            //check step range for king
            if (board[get_i][get_j] == &white.king) {
                if ( (abs(get_i - set_i) == 1 && get_j == set_j) || (abs(get_j - set_j) == 1 && get_i == set_i) ||
                        (abs(get_i - set_i) == 1 && abs(get_j - set_j) == 1) )
                {
                    move(get_i, get_j, set_i, set_j);
                    step = true;
                    goto WHITE_CHECK_END;
                }
            }
        }

        WHITE_CHECK_END:
        if (checkmate_white()) {
            move(set_i, set_j, get_i, get_j);
            return false;
        }

        goto RETURN;
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
                    if (get_j == set_j && *board[set_i][set_j] == down) {
                        if ((set_i - get_i == 2 || set_i - get_i == 1) && get_i == 1) {
                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto BLACK_CHECK_END;
                        }
                        if (set_i - get_i == 1) {
                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto BLACK_CHECK_END;
                        }
                    }
                    else if (*board[set_i][set_j] != down && ((set_i - get_i == 1) && (set_j - get_j == 1 || get_j - set_j == 1))) {
                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
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
                            if (*board[tmp_get_i][set_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    }
                    else if (set_i > get_i) { //step down
                        while (tmp_set_i > tmp_get_i + 1) {
                            --tmp_set_i;
                            if (*board[tmp_set_i][set_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    }
                } //endif step vertical

                else if (get_i == set_i) { //if step horizontal
                    int tmp_get_j = get_j;
                    int tmp_set_j = set_j;

                    if (get_j < set_j) { //step right
                        while (tmp_get_j < tmp_set_j - 1) {
                            --tmp_set_j;
                            if (*board[set_i][tmp_set_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    }
                    else if (get_j > set_j) { //step left
                        while (tmp_set_j < tmp_get_j - 1) {
                            --tmp_get_j;
                            if (*board[set_i][tmp_get_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    }
                } //endif step horizontal
            }

            //check step range for knight
            if (board[get_i][get_j] == &black.knight[0] || board[get_i][get_j] == &black.knight[1]) {
                if ( (abs(get_i - set_i) == 2 && abs(get_j - set_j) == 1) ||
                        (abs(get_i - set_i) == 1 && abs(get_j - set_j) == 2) )
                {
                    move(get_i, get_j, set_i, set_j);
                    step = true;
                    goto BLACK_CHECK_END;
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
                            if (*board[--tmp_get_i][--tmp_get_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    }
                    else if ((get_i > set_i) && (get_j < set_j)) { //right-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j < tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][++tmp_get_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    }
                    else if ((get_i < set_i) && (get_j > set_j)) { //left-down
                        while ((tmp_get_i < tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[++tmp_get_i][--tmp_get_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    }
                    else if (((get_i < set_i) && (get_j < set_j))) { //rignt-down
                        while ((tmp_get_i + 1 < tmp_set_i) && (tmp_get_j + 1 < tmp_set_j)) {
                            if (*board[++tmp_get_i][++tmp_get_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
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
                                if (*board[tmp_get_i][set_j] != down) {
                                    step = false;
                                    goto BLACK_CHECK_END;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto BLACK_CHECK_END;
                        }
                        else if (set_i > get_i) { //step down
                            while (tmp_set_i > tmp_get_i + 1) {
                                --tmp_set_i;
                                if (*board[tmp_set_i][set_j] != down) {
                                    step = false;
                                    goto BLACK_CHECK_END;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto BLACK_CHECK_END;
                        }
                    } //endif step vertical

                    else if (get_i == set_i) { //if step horizontal
                        if (get_j < set_j) { //step right
                            while (tmp_get_j < tmp_set_j - 1) {
                                --tmp_set_j;
                                if (*board[set_i][tmp_set_j] != down) {
                                    step = false;
                                    goto BLACK_CHECK_END;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto BLACK_CHECK_END;
                        }
                        else if (get_j > set_j) { //step left
                            while (tmp_set_j < tmp_get_j - 1) {
                                --tmp_get_j;
                                if (*board[set_i][tmp_get_j] != down) {
                                    step = false;
                                    goto BLACK_CHECK_END;
                                }
                            }

                            move(get_i, get_j, set_i, set_j);
                            step = true;
                            goto BLACK_CHECK_END;
                        }
                    } //endif step horizontal
                    
                } //end check vertical-or-horizontal

                if (abs(get_i - set_i) == abs(get_j - set_j)) { //check cross step
                    if ((get_i > set_i) && (get_j > set_j)) { //left-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][--tmp_get_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    } //end left-up

                    else if ((get_i > set_i) && (get_j < set_j)) { //right-up
                        while ((tmp_get_i > tmp_set_i + 1) && (tmp_get_j < tmp_set_j + 1)) {
                            if (*board[--tmp_get_i][++tmp_get_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    } //end right-up

                    else if ((get_i < set_i) && (get_j > set_j)) { //left-down
                        while ((tmp_get_i < tmp_set_i + 1) && (tmp_get_j > tmp_set_j + 1)) {
                            if (*board[++tmp_get_i][--tmp_get_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    } //end left-down

                    else if (((get_i < set_i) && (get_j < set_j))) { //rignt-down
                        while ((tmp_get_i + 1 < tmp_set_i) && (tmp_get_j + 1 < tmp_set_j)) {
                            if (*board[++tmp_get_i][++tmp_get_j] != down) {
                                step = false;
                                goto BLACK_CHECK_END;
                            }
                        }

                        move(get_i, get_j, set_i, set_j);
                        step = true;
                        goto BLACK_CHECK_END;
                    } //end right-down

                } //endif cross step   
            }

            //check step range for king
            if (board[get_i][get_j] == &black.king) {
                if ( (abs(get_i - set_i) == 1 && get_j == set_j) || (abs(get_j - set_j) == 1 && get_i == set_i) ||
                        (abs(get_i - set_i) == 1 && abs(get_j - set_j) == 1) )
                {
                    move(get_i, get_j, set_i, set_j);
                    step = true;
                    goto BLACK_CHECK_END;
                }
            }
        }

        BLACK_CHECK_END:
        if (checkmate_black()) {
            move(set_i, set_j, get_i, get_j);
            return false;
        }

        goto RETURN;
    }
            
    RETURN:
    return step;
}

bool chess_board::checkmate_white() {
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
        
        while ((*board[--tmp_pos_i][tmp_pos_j] == up) && (tmp_pos_i > 0)) {}

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

        while ((*board[++tmp_pos_i][tmp_pos_j] == up) && (tmp_pos_i < 7)) {}

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

        while ((*board[tmp_pos_i][--tmp_pos_j] == up) && (tmp_pos_j > 0)) {}

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

        while ((*board[tmp_pos_i][++tmp_pos_j] == up) && (tmp_pos_j < 7)) {}

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

        while ((*board[--tmp_pos_i][--tmp_pos_j] == up) 
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

        while ((*board[--tmp_pos_i][++tmp_pos_j] == up)
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

        while ((*board[++tmp_pos_i][--tmp_pos_j] == up) 
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

        while ((*board[++tmp_pos_i][++tmp_pos_j] == up) 
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

bool chess_board::checkmate_black() {
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
        
        while ((*board[--tmp_pos_i][tmp_pos_j] == up) && (tmp_pos_i > 0)) {}

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

        while ((*board[++tmp_pos_i][tmp_pos_j] == up) && (tmp_pos_i < 7)) {}

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

        while ((*board[tmp_pos_i][--tmp_pos_j] == up) && (tmp_pos_j > 0)) {}

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

        while ((*board[tmp_pos_i][++tmp_pos_j] == up) && (tmp_pos_j < 7)) {}

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

        while ((*board[--tmp_pos_i][--tmp_pos_j] == up) 
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

        while ((*board[--tmp_pos_i][++tmp_pos_j] == up)
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

        while ((*board[++tmp_pos_i][--tmp_pos_j] == up) 
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

        while ((*board[++tmp_pos_i][++tmp_pos_j] == up) 
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

void chess_board::move(int get_i, int get_j, int set_i, int set_j) {
    board[set_i][set_j] = board[get_i][get_j];
    board[get_i][get_j] = &dash[get_i][get_j];
}
