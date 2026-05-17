#include "szambeallitoB.hpp"
#include "graphics.hpp"
#include <sstream>
using namespace genv;
using namespace std;

szambeallitoB::szambeallitoB(int x, int y, int sx, int sy ,int mi, int ma)
    :widget(x, y, sx, sy), _min(mi), _max(ma), _aktualis(mi), _huzva(false){}

void szambeallitoB::rajzol()
{

    gout<<move_to(_x, _y)
        << color(150,150,150)
        << box(_sy, _sy);

    gout<< move_to(_x + _sy/2 - 5, _y + _sy/2 - 10)
        << color(255,255,255)
        << text("-");


    gout<< move_to(_x + _sx - _sy, _y)
        << color(150,150,150)
        << box(_sy, _sy);

    gout<< move_to(_x + _sx - _sy/2 - 5, _y + _sy/2 - 10)
        << color(255,255,255)
        << text("+");


    int sin_x = _x + _sy;
    int sin_szelesseg = _sx - 2 * _sy;
    gout<<move_to(sin_x, _y + _sy/2 - 2)
        << color(200,200,200)
        << box(sin_szelesseg, 4);


    int gomb_x = sin_x + (_aktualis - _min) * (sin_szelesseg - 15) / (_max - _min);
    gout<< move_to(gomb_x, _y)
        << color(0,0,255)
        << box(15, _sy);


    stringstream ss; ss << _aktualis;
    gout<< move_to(_x + _sx/2 - 10, _y - 5)
        << color(255,255,255)
        << text(ss.str());


}

void szambeallitoB::event_kezeles(event ev)
{
if (!_enabled) return;

    if (ev.type == ev_mouse)
        {
        if (ev.button == btn_left)
        {

            if (ev.pos_x > _x && ev.pos_x < _x + _sy && ev.pos_y > _y && ev.pos_y < _y + _sy) {
                _huzva = false;
                if (_aktualis > _min) _aktualis--;
            }

            else if (ev.pos_x > _x + _sx - _sy && ev.pos_x < _x + _sx && ev.pos_y > _y && ev.pos_y < _y + _sy) {
                _huzva = false;
                if (_aktualis < _max) _aktualis++;
            }

            else if (ev.pos_x > _x + _sy && ev.pos_x < _x + _sx - _sy && ev.pos_y > _y && ev.pos_y < _y + _sy) {
                _huzva = true;
            }
        }

        if (ev.button == -btn_left)
        {
            _huzva = false;
        }

        if (_huzva)
        {

            int sin_x = _x + _sy;
            int sin_szelesseg = _sx - 2 * _sy;
            float arany = (float)(ev.pos_x - sin_x) / sin_szelesseg;
            _aktualis = _min + arany * (_max - _min);

            if (_aktualis < _min) _aktualis = _min;
            if (_aktualis > _max) _aktualis = _max;
        }
    }
    if (ev.type == ev_key)
        {

        if ((ev.keycode == key_up) && _aktualis < _max)
        {
            _aktualis++;
        }

        if ( ev.keycode == key_pgup && _aktualis < _max)
        {
            if(_aktualis+10>_max)
            {
                _aktualis=_max;
            }
            else
            {
               _aktualis+=10;
            }

        }

        if (ev.keycode == key_down && _aktualis > _min)
        {
            _aktualis--;
        }
        if(ev.keycode == key_pgdn && _aktualis > _min)
        {
            if(_aktualis-10<_min)
            {
                _aktualis=_min;
            }
            else
            {
               _aktualis-=10;
            }
        }
    }
}

std::string szambeallitoB::ertek_kapas()
{
    std::stringstream ss;
    ss << _aktualis;
    return ss.str();
}
szambeallitoB::~szambeallitoB()
{
    //dtor
}
