#ifndef SZAMBEALLITOB_HPP
#define SZAMBEALLITOB_HPP

#include "widget.hpp"


class szambeallitoB : public widget
{
    protected: int _min, _max, _aktualis;
               bool _huzva;
    public:
        szambeallitoB(int x, int y, int sx, int sy,int mi, int ma);
        virtual ~szambeallitoB();
        void rajzol()override;
        void event_kezeles(genv::event) override;
        std::string ertek_kapas() override;
        int get_ertek() const { return _aktualis; }


    private:
};

#endif // SZAMBEALLITOB_HPP
