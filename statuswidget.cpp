#include "statuswidget.hpp"
#include "graphics.hpp"

using namespace genv;

StatuszWidget::StatuszWidget(int x, int y, int sx, int sy)
    : widget(x, y, sx, sy), _szoveg("") {}

StatuszWidget::~StatuszWidget() {}

void StatuszWidget::rajzol() {
    gout<< move_to(_x, _y)
        << color(255, 255, 255)
        << box(_sx, _sy);

    gout << color(0, 0, 0);

    int tw = _szoveg.length() * 8;
    gout<< move_to(_x + _sx/2 - tw/2, _y + _sy/2 + 5)
        << text(_szoveg);
}
