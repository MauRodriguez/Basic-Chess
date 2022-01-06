#ifndef GAME_H
#define GAME_H
#include "../drawer/drawer.h"
#include "../chess/chess.h"


class Game {
private:
    Chess chess;
    Drawer drawer;    
public:
    Game();

    ~Game();

    void run();
};

#endif