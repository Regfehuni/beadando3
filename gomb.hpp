#ifndef GOMB_HPP
#define GOMB_HPP

#include "widget.hpp"
#include <string>

class JatekApp;

class Gomb : public widget {
protected:
    std::string _szoveg;
    JatekApp* _app;
public:
    Gomb(int x, int y, int sx, int sy, const std::string& szoveg, JatekApp* app);
    virtual ~Gomb();

    void rajzol() override;
    void event_kezeles(genv::event ev) override;
    std::string ertek_kapas() override { return ""; }
};

#endif // GOMB_HPP
