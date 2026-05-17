#include "amoebaboard.hpp"
#include "graphics.hpp"
#include "jatekapp.hpp"
#include <string>
#include <iostream>

using namespace genv;

AmoebaBoard::AmoebaBoard(int x, int y, int sx, int sy, JatekMester* master, JatekApp* app)
    : widget(x, y, sx, sy), _master(master), _theme(0),_game_started(false),_app(app)
{
    _rows = _master->get_rows();
    _cols = _master->get_cols();
    _cell_size = (_sx < _sy ? _sx / _cols : _sy / _rows);
    if (_cell_size < 2) _cell_size = 2;
}

AmoebaBoard::~AmoebaBoard() {
    delete _master;
}

void AmoebaBoard::rajzol() {

    int r, g, b;
    switch (_theme) {
        case 1: r = 0;   g = 200; b = 200; break;
        case 2: r = 200; g = 80;  b = 0;   break;
        default: r = 220; g = 200; b = 120; break;
    }
    gout<< move_to(_x, _y)
        << color(r, g, b)
        << box(_sx, _sy);
    gout<< color(0, 0, 0);

    for (int i = 0; i <= _rows; i++) {
        int y_line = _y + i * _cell_size;
        gout<< move_to(_x, y_line)
            << line_to(_x + _cols * _cell_size, y_line);
    }
    for (int i = 0; i <= _cols; i++) {
        int x_line = _x + i * _cell_size;
        gout<< move_to(x_line, _y)
            << line_to(x_line, _y + _rows * _cell_size);
    }


    int piece_size = _cell_size * 0.6;
    if (piece_size < 4) piece_size = 4;
    if (piece_size > _cell_size - 2) piece_size = _cell_size - 2;

    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
            int cell = _master->get_cell(i, j);
            if (cell != 0) {
                int draw_x = _x + j * _cell_size + (_cell_size - piece_size) / 2;
                int draw_y = _y + i * _cell_size + (_cell_size - piece_size) / 2;
                if (cell == 1) gout << color(255, 50, 50);
                else gout << color(50, 50, 255);
                gout << move_to(draw_x, draw_y) << box(piece_size, piece_size);
            }
        }
    }
}

void AmoebaBoard::event_kezeles(genv::event ev) {
    if (!_game_started) return;
    if (ev.type == ev_mouse && ev.button == btn_left) {
        int cell_x = (ev.pos_x - _x) / _cell_size;
        int cell_y = (ev.pos_y - _y) / _cell_size;
        if (cell_x >= 0 && cell_x < _cols && cell_y >= 0 && cell_y < _rows) {
            bool siker = _master->lepes(cell_y, cell_x);
            if (siker && _master->is_game_over()) {
                int gy = _master->get_winner();
                std::string uzenet;
                if (gy == 1) uzenet = "Piros nyert!";
                else if (gy == 2) uzenet = "Kek nyert!";
                else if (gy == -1) uzenet = "Dontetlen!";
                if (_app) _app->set_status(uzenet);
            }
        }
    }
}


std::string AmoebaBoard::ertek_kapas() {
    return "AmoebaBoard";
}
