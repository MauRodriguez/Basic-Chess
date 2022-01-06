#ifndef CHESS_H
#define CHESS_H
#include <vector>
#include "piece.h"
#define WHITE 1
#define BLACK 0

class Chess {
private:
    int colour;
    std::vector<Piece> pieces;

public:
    Chess(int colour);

    ~Chess();

    void setWhiteBoard();
    
    void setBlackBoard();

    void bestMovement();

    void hasWon();
};

#endif