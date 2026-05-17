#include "jatekapp.hpp"
#include "szambeallitoB.hpp"
#include "kivalasztoA.hpp"
#include "amoebaboard.hpp"
#include "jatekmester.hpp"
#include "gomb.hpp"
#include "statuswidget.hpp"

///az r gomb lenyomasara uj jatekot kezd

int main() {
    JatekApp app(1200, 800);

    szambeallitoB* meretBeallo = new szambeallitoB(20, 20, 200, 30, 15, 30);
    app.hozzaad(meretBeallo);
    app.meretBeallo = meretBeallo;

    std::vector<std::string> temak = {"alap", "tenger", "tuz"};
    kivalasztoA* temaValaszto = new kivalasztoA(240, 20, 150, 90, temak);
    app.hozzaad(temaValaszto);
    app.temaValaszto = temaValaszto;

    Gomb* inditoGomb = new Gomb(850, 20, 150, 50, "Jatek indito", &app);
    app.hozzaad(inditoGomb);

    StatuszWidget* statusz = new StatuszWidget(850, 100, 250, 50);
    app.hozzaad(statusz);
    app.statusz = statusz;

    JatekMester* mester = new JatekMester(15, 15);
    AmoebaBoard* board = new AmoebaBoard(100, 120, 600, 600, mester, &app);
    app.hozzaad(board);
    app.board = board;

    board->set_game_started(false);

    app.futtat();

    return 0;
}
