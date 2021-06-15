class chess_board {
public:
    chess_board();
    void start_game();
    void set_new_board();
    void print_board();
    bool check_step(std::string& get, std::string&);
    bool checkmate_white();
    bool checkmate_black();
    void move(int, int, int, int);

private:
    int current_player = 0;

    wchar_t* board[8][8];
    wchar_t dash[8][8];

    const wchar_t up = L'\u2191';
    const wchar_t down = L'\u2193';

    class player {
    public:
        wchar_t pawn[8];
        wchar_t rock[2];
        wchar_t knight[2];
        wchar_t bishop[2];
        wchar_t queen;
        wchar_t king;
    };
    
    player white;
    player black;
};