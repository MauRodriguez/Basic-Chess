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

    bool bishopMoves(int x, int y, int type, int finalX, int finalY, int finalType);
    bool kingMoves(int x, int y, int type, int finalX, int finalY, int finalType);
    bool knightMoves(int x, int y, int type, int finalX, int finalY, int finalType);
    bool pawnMoves(int x, int y, int type, int finalX, int finalY, int finalType);
    bool queenMoves(int x, int y, int type, int finalX, int finalY, int finalType);
    bool rookMoves(int x, int y, int type, int finalX, int finalY, int finalType);

    bool checkDiagonal(int x, int y, int finalX, int finalY);
    bool checkLine(int x, int y, int finalX, int finalY);

    bool emptySquare(int x, int y);

public:
    Chess(int colour);

    ~Chess();

    void setWhiteBoard();
    
    void setBlackBoard();

    void bestMovement();

    bool possibleMove(int initialX, int initialY, int initialType, int finalX, int finalY, int finalType);

    std::vector<Piece>& getPieces();

    void eliminatePiece(int x, int y);

    void addPiece(int x, int y, int type);
};

#endif