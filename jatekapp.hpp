#ifndef JATEKAPP_HPP
#define JATEKAPP_HPP

#include <string>
#include <vector>


class widget;
class szambeallitoB;
class kivalasztoA;
class AmoebaBoard;
class StatuszWidget;

class JatekApp {
private:
    int _screen_width, _screen_height;
    std::vector<widget*> _widgetek;
    int _focused;
    bool _game_started;

public:
    JatekApp(int width, int height);
    ~JatekApp();

    void hozzaad(widget* w);
    void futtat();

    void start_game();
    bool is_game_started() const { return _game_started; }

    StatuszWidget* statusz = nullptr;
    void set_status(const std::string& szoveg);

    szambeallitoB* meretBeallo = nullptr;
    kivalasztoA* temaValaszto = nullptr;
    AmoebaBoard* board = nullptr;
};

#endif //JATEKAPP_HPP
