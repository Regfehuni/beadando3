#include "gomb.hpp"
#include "graphics.hpp"
#include "jatekapp.hpp"

using namespace genv;

Gomb::Gomb(int x, int y, int sx, int sy, const std::string& szoveg, JatekApp* app)
    : widget(x, y, sx, sy), _szoveg(szoveg), _app(app) {}

Gomb::~Gomb() {}

void Gomb::rajzol() {
    if (_enabled) {
        gout<< move_to(_x, _y)
            << color(100, 100, 250)
            << box(_sx, _sy);
        gout<< color(255, 255, 255);
    } else {
        gout<< move_to(_x, _y)
            << color(80, 80, 80)
            << box(_sx, _sy);
        gout<< color(200, 200, 200);
    }

    int tw = _szoveg.length() * 8;
    gout<< move_to(_x + _sx/2 - tw/2, _y + _sy/2 + 5)
        << text(_szoveg);
}

void Gomb::event_kezeles(genv::event ev) {
    if (!_enabled) return;
    if (ev.type == ev_mouse && ev.button == btn_left) {
        if (kivalasztva(ev.pos_x, ev.pos_y)) {
            if (_app) _app->start_game();
        }
    }
}
