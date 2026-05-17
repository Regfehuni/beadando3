#include "kivalasztoA.hpp"
#include "graphics.hpp"

using namespace genv;

kivalasztoA::kivalasztoA(int x, int y, int sx, int sy, std::vector<std::string> opciok)
    : widget(x, y, sx, sy), _opciok(opciok), _kijelolt(0), _elso_lathato(0)
{
    _sor_magassag = 30;
}

void kivalasztoA::rajzol()
{

    gout<< move_to(_x, _y)
        << color(50, 50, 50)
        << box(_sx, _sy);


    int lathato_db = _sy / _sor_magassag;

    for (int i = 0; i < lathato_db && (i + _elso_lathato) < _opciok.size(); i++)
    {
        int akt_index = i + _elso_lathato;
        int sor_y = _y + i * _sor_magassag;


        if (akt_index == _kijelolt)
        {
            gout<< move_to(_x + 2, sor_y + 2)
                << color(0, 0, 255)
                << box(_sx - 4, _sor_magassag - 4);
        }


        gout<< move_to(_x + 10, sor_y + _sor_magassag/2 + 5)
            << color(255, 255, 255)
            << text(_opciok[akt_index]);
    }
}

void kivalasztoA::event_kezeles(event ev)
{
    if (!_enabled) return;
    int lathato_db = _sy / _sor_magassag;

    if (ev.type == ev_mouse && ev.button == btn_left)
        {
        for (int i = 0; i < lathato_db; i++)
        {
            int sor_y = _y + i * _sor_magassag;
            if (ev.pos_x > _x && ev.pos_x < _x + _sx && ev.pos_y > sor_y && ev.pos_y < sor_y + _sor_magassag)
            {
                if (i + _elso_lathato < _opciok.size())
                {
                    _kijelolt = i + _elso_lathato;
                }
            }
        }
    }


    if (ev.type == ev_mouse && ev.button == btn_wheelup && _elso_lathato > 0)
    {
        _elso_lathato--;
    }
    if (ev.type == ev_mouse && ev.button == btn_wheeldown && (_elso_lathato + lathato_db) < _opciok.size())
    {
        _elso_lathato++;
    }
}

std::string kivalasztoA::ertek_kapas()
{
    return _opciok[_kijelolt];
}


