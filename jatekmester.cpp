#include "jatekmester.hpp"


JatekMester::JatekMester(int rows, int cols)
    : _rows(rows), _cols(cols), _current_player(1), _winner(0), _game_over(false)
{
    reset();
}

void JatekMester::reset() {
    _board.assign(_rows, std::vector<int>(_cols, 0));
    _current_player = 1;
    _winner = 0;
    _game_over = false;
}

int JatekMester::get_cell(int row, int col) const {
    if (row >= 0 && row < _rows && col >= 0 && col < _cols)
        return _board[row][col];
    return -1;
}

int JatekMester::get_current_player() const { return _current_player; }
int JatekMester::get_winner() const { return _winner; }
bool JatekMester::is_game_over() const { return _game_over; }

bool JatekMester::check_win(int row, int col, int player) const {
    auto countDirection = [&](int dx, int dy) -> int {
        int cnt = 1;
        for (int i = 1; i <= 4; ++i) {
            int r = row + i * dx, c = col + i * dy;
            if (r < 0 || r >= _rows || c < 0 || c >= _cols) break;
            if (_board[r][c] == player) cnt++;
            else break;
        }
        for (int i = 1; i <= 4; ++i) {
            int r = row - i * dx, c = col - i * dy;
            if (r < 0 || r >= _rows || c < 0 || c >= _cols) break;
            if (_board[r][c] == player) cnt++;
            else break;
        }
        return cnt;
    };

    if (countDirection(1, 0) >= 5) return true;
    if (countDirection(0, 1) >= 5) return true;
    if (countDirection(1, 1) >= 5) return true;
    if (countDirection(1, -1) >= 5) return true;

    return false;
}

bool JatekMester::is_draw() const {
    for (int i = 0; i < _rows; ++i)
        for (int j = 0; j < _cols; ++j)
            if (_board[i][j] == 0) return false;
    return true;
}

bool JatekMester::lepes(int row, int col) {
    if (_game_over) return false;
    if (row < 0 || row >= _rows || col < 0 || col >= _cols) return false;
    if (_board[row][col] != 0) return false;

    _board[row][col] = _current_player;

    if (check_win(row, col, _current_player)) {
        _winner = _current_player;
        _game_over = true;
        return true;
    }

    if (is_draw()) {
        _winner = -1;
        _game_over = true;
        return true;
    }

    _current_player = (_current_player == 1) ? 2 : 1;
    return true;
}

JatekMester::~JatekMester()
{
    //dtor
}
