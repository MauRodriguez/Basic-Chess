#include "piece.h"

Piece::Piece(int coordinateX, int coordinateY, int type, bool moved) :
    coordinateX(coordinateX),
    coordinateY(coordinateY),
    type(type),
    moved(moved)
{}

Piece::~Piece(){}

int Piece::getCoordinateX(){
    return coordinateX;
}

int Piece::getCoordinateY(){
    return coordinateY;
}

int Piece::getType(){
    return type;
}

bool Piece::hasMoved(){
    return moved;
}

void Piece::move(int x, int y){
    coordinateX = x;
    coordinateY = y;
}