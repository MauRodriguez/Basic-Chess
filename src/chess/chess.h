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

    int bishopMoves(int x, int y, int type, int finalX, int finalY, int finalType);
    int kingMoves(int x, int y, int type, int finalX, int finalY, int finalType);
    int knightMoves(int x, int y, int type, int finalX, int finalY, int finalType);
    int pawnMoves(int x, int y, int type, int finalX, int finalY, int finalType);
    int queenMoves(int x, int y, int type, int finalX, int finalY, int finalType);
    int rookMoves(int x, int y, int type, int finalX, int finalY, int finalType);

    bool checkDiagonal(int x, int y, int finalX, int finalY);
    bool checkLine(int x, int y, int finalX, int finalY);

    int typeOfSquare(int x, int y);

    bool isInCheck(int x, int y);

    Piece foundPiece(int x, int y);

    bool tryCastling(int x, int y, int incX);

public:
    Chess(int colour);

    ~Chess();

    void setWhiteBoard();
    
    void setBlackBoard();

    void bestMovement();

    bool possibleMove(int initialX, int initialY, int initialType, int finalX, int finalY, int finalType);

    bool tryToMove(int initialX, int initialY, int initialType, int finalX, int finalY, int finalType);

    std::vector<Piece>& getPieces();

    void eliminatePiece(int x, int y);

    void addPiece(int x, int y, int type, bool moved);
};

#endif