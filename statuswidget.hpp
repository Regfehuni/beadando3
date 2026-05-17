#ifndef STATUSWIDGET_HPP
#define STATUSWIDGET_HPP

#include "widget.hpp"
#include <string>

class StatuszWidget : public widget {
protected:
    std::string _szoveg;
public:
    StatuszWidget(int x, int y, int sx, int sy);
    virtual ~StatuszWidget();

    void set_szoveg(const std::string& szoveg) { _szoveg = szoveg; }
    void rajzol() override;
    void event_kezeles(genv::event ev) override {}
    std::string ertek_kapas() override { return _szoveg; }
};

#endif // STATUSWIDGET_HPP
