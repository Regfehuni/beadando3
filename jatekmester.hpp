#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

#include <vector>

class JatekMester {
private:
    int _rows, _cols;
    std::vector<std::vector<int>> _board;
    int _current_player;
    int _winner;
    bool _game_over;

    bool check_win(int row, int col, int player) const;
    bool is_draw() const;

public:
    JatekMester(int rows, int cols);
    ~JatekMester();

    bool lepes(int row, int col);
    int get_cell(int row, int col) const;
    int get_current_player() const;
    int get_winner() const;
    bool is_game_over() const;
    void reset();

    int get_rows() const { return _rows; }
    int get_cols() const { return _cols; }
};


#endif // JATEKMESTER_HPP
