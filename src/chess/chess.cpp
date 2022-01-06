#include "chess.h"
#include "piece.h"
#include <cmath>
#include <iostream>

Chess::Chess(int colour) :
    colour(WHITE),
    pieces()
{
    if(colour == WHITE){
        setWhiteBoard();
    } else {
        setBlackBoard();
    }
}

Chess::~Chess(){}

std::vector<Piece>& Chess::getPieces(){
    return pieces;
}

void Chess::setWhiteBoard(){
    //white pieces
    Piece leftWRook(0, 0, WHITE_ROOK);
    pieces.push_back(leftWRook);
    Piece leftWKnight(1, 0, WHITE_KNIGHT);
    pieces.push_back(leftWKnight);
    Piece leftWBishop(2, 0, WHITE_BISHOP);
    pieces.push_back(leftWBishop);
    Piece WQueen(3, 0, WHITE_QUEEN);
    pieces.push_back(WQueen);
    Piece WKing(4, 0, WHITE_KING);
    pieces.push_back(WKing);
    Piece rightWBishop(5, 0, WHITE_BISHOP);
    pieces.push_back(rightWBishop);
    Piece rightWKnight(6, 0, WHITE_KNIGHT);
    pieces.push_back(rightWKnight);
    Piece rightWRook(7, 0, WHITE_ROOK);
    pieces.push_back(rightWRook);
    
    for(int i = 0; i < 8; i++){
        Piece WPawn(i, 1, WHITE_PAWN);
        pieces.push_back(WPawn);
    }

    //black pieces
    Piece leftBRook(0, 7, BLACK_ROOK);
    pieces.push_back(leftBRook);
    Piece leftBKnight(1, 7, BLACK_KNIGHT);
    pieces.push_back(leftBKnight);
    Piece leftBBishop(2, 7, BLACK_BISHOP);
    pieces.push_back(leftBBishop);
    Piece BQueen(3, 7, BLACK_QUEEN);
    pieces.push_back(BQueen);
    Piece BKing(4, 7, BLACK_KING);
    pieces.push_back(BKing);
    Piece rightBBishop(5, 7, BLACK_BISHOP);
    pieces.push_back(rightBBishop);
    Piece rightBKnight(6, 7, BLACK_KNIGHT);
    pieces.push_back(rightBKnight);
    Piece rightBRook(7, 7, BLACK_ROOK);
    pieces.push_back(rightBRook);
    
    for(int i = 0; i < 8; i++){
        Piece BPawn(i, 6, BLACK_PAWN);
        pieces.push_back(BPawn);
    }
}

void Chess::setBlackBoard(){
    //white pieces
    Piece leftWRook(0, 7, WHITE_ROOK);
    pieces.push_back(leftWRook);
    Piece leftWKnight(1, 7, WHITE_KNIGHT);
    pieces.push_back(leftWKnight);
    Piece leftWBishop(2, 7, WHITE_BISHOP);
    pieces.push_back(leftWBishop);
    Piece WQueen(4, 7, WHITE_QUEEN);
    pieces.push_back(WQueen);
    Piece WKing(3, 7, WHITE_KING);
    pieces.push_back(WKing);
    Piece rightWBishop(5, 7, WHITE_BISHOP);
    pieces.push_back(rightWBishop);
    Piece rightWKnight(6, 7, WHITE_KNIGHT);
    pieces.push_back(rightWKnight);
    Piece rightWRook(7, 7, WHITE_ROOK);
    pieces.push_back(rightWRook);

    //black pieces
    Piece leftBRook(0, 0, BLACK_ROOK);
    pieces.push_back(leftBRook);
    Piece leftBKnight(1, 0, BLACK_KNIGHT);
    pieces.push_back(leftBKnight);
    Piece leftBBishop(2, 0, BLACK_BISHOP);
    pieces.push_back(leftBBishop);
    Piece BQueen(4, 0, BLACK_QUEEN);
    pieces.push_back(BQueen);
    Piece BKing(3, 0, BLACK_KING);
    pieces.push_back(BKing);
    Piece rightBBishop(5, 0, BLACK_BISHOP);
    pieces.push_back(rightBBishop);
    Piece rightBKnight(6, 0, BLACK_KNIGHT);
    pieces.push_back(rightBKnight);
    Piece rightBRook(7, 0, BLACK_ROOK);
    pieces.push_back(rightBRook);
    
    for(int i = 0; i < 8; i++){
        Piece BPawn(i, 1, BLACK_PAWN);
        pieces.push_back(BPawn);
    }
}

void Chess::bestMovement(){} //heres where the IA goes

bool Chess::possibleMove(int initialX, int initialY, int initialType, int finalX, int finalY, int finalType){
    switch(abs(initialType)){
        case WHITE_BISHOP:
            return bishopMoves(initialX, initialY, initialType, finalX, finalY, finalType);
        case WHITE_KING:
            return kingMoves(initialX, initialY, initialType, finalX, finalY, finalType);
        case WHITE_KNIGHT:
            return knightMoves(initialX, initialY, initialType, finalX, finalY, finalType);
        case WHITE_PAWN:
            return pawnMoves(initialX, initialY, initialType, finalX, finalY, finalType);
        case WHITE_QUEEN:
            return queenMoves(initialX, initialY, initialType, finalX, finalY, finalType);
        case WHITE_ROOK:
            return rookMoves(initialX, initialY, initialType, finalX, finalY, finalType);

        default:
            return false;
    }

}

void Chess::eliminatePiece(int x, int y){
    for(int i = 0; i < pieces.size(); i++){
        if(pieces[i].getCoordinateX() == x && pieces[i].getCoordinateY() == y){
            pieces.erase(pieces.begin() + i);
            break;
        }
    }
}

void Chess::addPiece(int x, int y, int type){
    Piece newPiece(x, y, type);
    pieces.push_back(newPiece);
}

bool Chess::bishopMoves(int x, int y, int type, int finalX, int finalY, int finalType){
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return false;
    }

    int stepX = finalX - x;
    int stepY = finalY - y;

    std::cout<<"step X:" << stepX << " stepY: " << stepY <<"\n";

    if(abs(stepX) != abs(stepY)){
        return false;
    }

    if(!checkDiagonal(x, y, finalX, finalY)){
        return false;
    }
    eliminatePiece(finalX, finalY);
    return true;

}

bool Chess::kingMoves(int x, int y, int type, int finalX, int finalY, int finalType){
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return false;
    }
    int stepX = finalX - x;
    int stepY = finalY - y;

    std::cout<<"step X:" << stepX << " stepY: " << stepY <<"\n";
    
    if(stepX == 0 || stepY == 0){
        if(abs(stepX) > 1 || abs(stepY) > 1){
            return false;
        }
        eliminatePiece(finalX, finalY);
        return true;
    } else if(abs(stepX) == abs(stepY)){
        if(abs(stepX) > 1){
            return false;
        }
        eliminatePiece(finalX, finalY);
        return true;
    }
    return false;
    
}

bool Chess::knightMoves(int x, int y, int type,int finalX, int finalY, int finalType){
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return false;
    }

    int stepX = finalX - x;
    int stepY = finalY - y;

    std::cout<<"step X:" << stepX << " stepY: " << stepY <<"\n";

    if(stepX == -1 && stepY == 2){
        eliminatePiece(finalX, finalY);
    } else if (stepX == -1 && stepY == -2){
        eliminatePiece(finalX, finalY);
    } else if (stepX == 1 && stepY == 2){
        eliminatePiece(finalX, finalY);
    } else if (stepX == 1 && stepY == -2){
        eliminatePiece(finalX, finalY);
    } else if (stepX == 2 && stepY == 1){
        eliminatePiece(finalX, finalY);
    } else if (stepX == 2 && stepY == -1){
        eliminatePiece(finalX, finalY);
    } else if (stepX == -2 && stepY == 1){
        eliminatePiece(finalX, finalY);
    } else if (stepX == -2 && stepY == -1){
        eliminatePiece(finalX, finalY);
    } else {
        return false;
    }

    return true;   

}

bool Chess::pawnMoves(int x, int y, int type, int finalX, int finalY, int finalType){
    std::cout<< "im a pawn";
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return false;
    }
    int stepX = finalX - x;
    int stepY = finalY - y;
    std::cout<<"step X:" << stepX << " stepY: " << stepY <<"\n";

    if(stepY > 0 && type < 0){
        return false;
    }
    if(stepY < 0 && type > 0){
        return false;
    }
    std::cout << "y" << y;
    if((y == 1 || y == 6) && emptySquare(finalX, finalY) && abs(stepY) == 2){
        return true;
    }

    if(abs(stepY) == 1 && emptySquare(finalX, finalY)){        
        return true;
    }
    if((abs(stepX) == abs(stepY)) && abs(stepY) == 1){
        eliminatePiece(finalX, finalY);        
        return true;
    }
    return false;
}

bool Chess::queenMoves(int x, int y, int type, int finalX, int finalY, int finalType){
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return false;
    }
    int stepX = finalX - x;
    int stepY = finalY - y;

    std::cout<<"step X:" << stepX << " stepY: " << stepY <<"\n";

    if(stepX == 0 || stepY == 0){
        if(!checkLine(x, y, finalX, finalY)){
            return false;
        }
        eliminatePiece(finalX, finalY);        
        return true;
    } else if(abs(stepX) == abs(stepY)){
        if(!checkDiagonal(x, y, finalX, finalY)){
            return false;
        }
        eliminatePiece(finalX, finalY);
        return true;
    }
    return false;

}

bool Chess::rookMoves(int x, int y, int type, int finalX, int finalY, int finalType){
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return false;    
    }

    int stepX = finalX - x;
    int stepY = finalY - y;

    std::cout<<"step X:" << stepX << " stepY: " << stepY <<"\n";

    if(stepX != 0 && stepY != 0){
        return false;
    }
    
    if(!checkLine(x, y, finalX, finalY)){
        return false;
    }
    eliminatePiece(finalX, finalY);
    return true;
}

bool Chess::checkDiagonal(int x, int y, int finalX, int finalY){
    int stepX = finalX - x;
    int stepY = finalY - y;
    int xInc = stepX/abs(stepX);
    int yInc = stepY/abs(stepY);

    std::cout<<"xInc: " << xInc << " yInc: " << yInc <<"\n";
    std::cout<<"stepX: " << stepX << " stepY: " << stepY <<"\n";

    int i = xInc;
    int j = yInc;
    while(abs(i) < abs(stepX) && abs(j) < abs(stepY)){
        std::cout<<"x + i:" << x+i << " y + j: " << y + j <<"\n";
        if(!emptySquare(x+i, y+j)){
            return false;
        }
        i += xInc;
        j += yInc;
    }
    
    return true;

}

bool Chess::checkLine(int x, int y, int finalX, int finalY){
    int stepX = finalX - x;
    int stepY = finalY - y;
    
    if(stepY == 0){
        int xInc = stepX/abs(stepX);
        for(int i = xInc; abs(i)<abs(stepX) ; i+=xInc){
            std::cout<<"x + i:" << x+i << " y: " << y <<"\n";
            if(!emptySquare(x+i,y)){
                return false;
            }
        }
    } else {
        int yInc = stepY/abs(stepY);
        for(int i = yInc; abs(i)<abs(stepY) ; i+=yInc){
            std::cout<<"x:" << x << " y + i: " << y + i <<"\n";
            if(!emptySquare(x,y+i)){
                return false;
            }
        }
    }
    return true;

}

bool Chess::emptySquare(int x, int y){
    for(int i = 0; i < pieces.size(); i++){
        if(pieces[i].getCoordinateX() == x && pieces[i].getCoordinateY() == y){
            return false;
        }
    }
    return true;
}


