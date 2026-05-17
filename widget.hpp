#ifndef WIDGET_HPP
#define WIDGET_HPP
#include "graphics.hpp"

class widget
{
    protected:
    int _x,_y,_sx,_sy;
    bool _focus;
    bool _enabled;

    public:
        widget(int x,int y,int sx, int sy);
        virtual ~widget();

        virtual void rajzol() = 0;

        virtual void event_kezeles(genv::event) = 0;

        virtual std::string ertek_kapas()=0;

        virtual bool kivalasztva(int mx, int my);

        virtual void set_focus(bool focus){ _focus = focus; }

        virtual bool get_focus() const{ return _focus; }

        virtual void set_enabled(bool enabled) { _enabled = enabled; }

        virtual bool is_enabled() const { return _enabled; }
};

#endif // WIDGET_HPP
