#include "piece.h"

Piece::Piece(int coordinateX, int coordinateY, int type) :
    coordinateX(coordinateX),
    coordinateY(coordinateY),
    type(type)
{}

Piece::~Piece(){}

bool Piece::possibleMove(){}

int Piece::getCoordinateX(){
    return coordinateX;
}

int Piece::getCoordinateY(){
    return coordinateY;
}

int Piece::getType(){
    return type;
}

void Piece::move(int x, int y){
    coordinateX = x;
    coordinateY = y;
}