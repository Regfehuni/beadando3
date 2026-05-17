#ifndef AMOEBABOARD_HPP
#define AMOEBABOARD_HPP

#include "widget.hpp"
#include "jatekmester.hpp"

class JatekApp;

class AmoebaBoard : public widget {
protected:
    int _rows, _cols;
    int _cell_size;
    JatekMester* _master;
    int _theme;
    bool _game_started;
    JatekApp* _app;
public:
    AmoebaBoard(int x, int y, int sx, int sy, JatekMester* master,JatekApp* app);
    virtual ~AmoebaBoard();

    void rajzol() override;
    void event_kezeles(genv::event ev) override;
    std::string ertek_kapas() override;

    void set_game_started(bool started) { _game_started = started; }

    void set_theme(int theme) { _theme = theme; }
    void resetGame() { if (_master) _master->reset(); }
};

#endif // AMOEBABOARD_HPP
