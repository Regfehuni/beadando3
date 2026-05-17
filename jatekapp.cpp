#include "jatekapp.hpp"
#include "graphics.hpp"
#include "widget.hpp"
#include "jatekmester.hpp"
#include "amoebaboard.hpp"
#include "kivalasztoA.hpp"
#include "szambeallitoB.hpp"
#include "gomb.hpp"
#include "statuswidget.hpp"

using namespace genv;

JatekApp::JatekApp(int width, int height)
    : _screen_width(width), _screen_height(height), _focused(-1), _game_started(false)
{
    gout.open(width, height);
}

JatekApp::~JatekApp() {
    for (widget* w : _widgetek) delete w;
}

void JatekApp::hozzaad(widget* w) {
    _widgetek.push_back(w);
}

void JatekApp::start_game() {
    if (_game_started) return;
    _game_started = true;
    if (meretBeallo) meretBeallo->set_enabled(false);
    if (temaValaszto) temaValaszto->set_enabled(false);
     if (board) board->set_game_started(true);

    for (widget* w : _widgetek) {
        Gomb* g = dynamic_cast<Gomb*>(w);
        if (g) { g->set_enabled(false); break; }
    }
}

void JatekApp::set_status(const std::string& szoveg) {
    if (statusz) statusz->set_szoveg(szoveg);
}

void JatekApp::futtat() {
    event ev;
    int last_size = (meretBeallo ? meretBeallo->get_ertek() : 15);
    int last_theme = (temaValaszto ? temaValaszto->get_kijelolt_index() : 0);


    while (gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_key && ev.keycode == 'r') {
            if (board) {
                board->resetGame();
                board->set_game_started(false);
                set_status("");
                _game_started = false;
                if (meretBeallo) meretBeallo->set_enabled(true);
                if (temaValaszto) temaValaszto->set_enabled(true);
                for (widget* w : _widgetek) {
                    Gomb* g = dynamic_cast<Gomb*>(w);
                    if (g) { g->set_enabled(true); break; }
                }
            }
        }


        if (ev.type == ev_mouse) {
            int eger_alatt = -1;
            for (size_t i = 0; i < _widgetek.size(); ++i) {
                if (_widgetek[i]->kivalasztva(ev.pos_x, ev.pos_y)) {
                    eger_alatt = i;
                    break;
                }
            }

            if (ev.button == btn_left && eger_alatt != -1) {
                _focused = eger_alatt;
            }

            if (eger_alatt != -1) {
                _widgetek[eger_alatt]->event_kezeles(ev);
            } else if (_focused != -1 && (ev.button == 0 || ev.button == -btn_left)) {
                _widgetek[_focused]->event_kezeles(ev);
            }
        } else if (ev.type == ev_key && _focused != -1) {
            _widgetek[_focused]->event_kezeles(ev);
        }

        if (meretBeallo) {
            int current_size = meretBeallo->get_ertek();
            if (current_size != last_size) {
                last_size = current_size;

                JatekMester* ujMester = new JatekMester(last_size, last_size);
                int boardX = 100;
                int boardY = 120;
                int boardW = 600;
                int boardH = 600;
                AmoebaBoard* ujBoard = new AmoebaBoard(boardX, boardY, boardW, boardH, ujMester,this);
                ujBoard->set_theme(last_theme);
                ujBoard->set_game_started(_game_started);

                for (size_t i = 0; i < _widgetek.size(); ++i) {
                    if (_widgetek[i] == board) {
                        if (_focused == (int)i) _focused = -1;
                        delete board;
                        _widgetek[i] = ujBoard;
                        board = ujBoard;
                        set_status("");
                        break;
                    }
                }
            }
        }

        if (temaValaszto && board) {
            int current_theme = temaValaszto->get_kijelolt_index();
            if (current_theme != last_theme) {
                last_theme = current_theme;
                board->set_theme(current_theme);
            }
        }
        gout<< move_to(0, 0)
            << color(0, 0, 0)
            << box(_screen_width, _screen_height);
        for (widget* w : _widgetek) {
            w->rajzol();
        }
        gout << refresh;
    }
}
