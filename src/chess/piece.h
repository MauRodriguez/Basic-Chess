#ifndef PIECE_H
#define PIECE_H

#define BLACK_BISHOP -1
#define BLACK_KING -2
#define BLACK_KNIGHT -3
#define BLACK_PAWN -4
#define BLACK_QUEEN -5
#define BLACK_ROOK -6

#define WHITE_BISHOP 1
#define WHITE_KING 2
#define WHITE_KNIGHT 3
#define WHITE_PAWN 4
#define WHITE_QUEEN 5
#define WHITE_ROOK 6


class Piece {
private:
    int coordinateX;
    int coordinateY;
    int type;
public:
    Piece(int coordinateX, int coordinateY, int type);

    ~Piece();

    bool possibleMove();

    int getCoordinateX();

    int getCoordinateY();

    int getType();

    void move(int x, int y);
};

#endif