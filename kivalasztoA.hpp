#ifndef KIVALASZTOA_HPP
#define KIVALASZTOA_HPP

#include "widget.hpp"
#include <vector>
#include <string>

class kivalasztoA : public widget {
protected:
    std::vector<std::string> _opciok;
    int _kijelolt;
    int _elso_lathato;
    int _sor_magassag;

public:

    kivalasztoA(int x, int y, int sx, int sy, std::vector<std::string> opciok);

    virtual void rajzol() override;
    virtual void event_kezeles(genv::event ev) override;
    virtual std::string ertek_kapas() override;
    int get_kijelolt_index() const { return _kijelolt; }
};

#endif //KIVALASZTOA_HPP
