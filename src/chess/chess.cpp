#include "chess.h"
#include "piece.h"
#include <cmath>
#include <iostream>
#define POSSIBLE_MOVE 1
#define POSSIBLE_CASTLING 2 
#define POSSIBLE_CHROWN 3
#define NOT_POSSIBLE 0


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
    Piece leftWRook(0, 0, WHITE_ROOK, false);
    pieces.push_back(leftWRook);
    Piece leftWKnight(1, 0, WHITE_KNIGHT, false);
    pieces.push_back(leftWKnight);
    Piece leftWBishop(2, 0, WHITE_BISHOP, false);
    pieces.push_back(leftWBishop);
    Piece WQueen(3, 0, WHITE_QUEEN, false);
    pieces.push_back(WQueen);
    Piece WKing(4, 0, WHITE_KING, false);
    pieces.push_back(WKing);
    Piece rightWBishop(5, 0, WHITE_BISHOP, false);
    pieces.push_back(rightWBishop);
    Piece rightWKnight(6, 0, WHITE_KNIGHT, false);
    pieces.push_back(rightWKnight);
    Piece rightWRook(7, 0, WHITE_ROOK, false);
    pieces.push_back(rightWRook);
    
    for(int i = 0; i < 8; i++){
        Piece WPawn(i, 1, WHITE_PAWN, false);
        pieces.push_back(WPawn);
    }

    //black pieces
    Piece leftBRook(0, 7, BLACK_ROOK, false);
    pieces.push_back(leftBRook);
    Piece leftBKnight(1, 7, BLACK_KNIGHT, false);
    pieces.push_back(leftBKnight);
    Piece leftBBishop(2, 7, BLACK_BISHOP, false);
    pieces.push_back(leftBBishop);
    Piece BQueen(3, 7, BLACK_QUEEN, false);
    pieces.push_back(BQueen);
    Piece BKing(4, 7, BLACK_KING, false);
    pieces.push_back(BKing);
    Piece rightBBishop(5, 7, BLACK_BISHOP, false);
    pieces.push_back(rightBBishop);
    Piece rightBKnight(6, 7, BLACK_KNIGHT, false);
    pieces.push_back(rightBKnight);
    Piece rightBRook(7, 7, BLACK_ROOK, false);
    pieces.push_back(rightBRook);
    
    for(int i = 0; i < 8; i++){
        Piece BPawn(i, 6, BLACK_PAWN, false);
        pieces.push_back(BPawn);
    }
}

void Chess::setBlackBoard(){
    //white pieces
    Piece leftWRook(0, 7, WHITE_ROOK, false);
    pieces.push_back(leftWRook);
    Piece leftWKnight(1, 7, WHITE_KNIGHT, false);
    pieces.push_back(leftWKnight);
    Piece leftWBishop(2, 7, WHITE_BISHOP, false);
    pieces.push_back(leftWBishop);
    Piece WQueen(4, 7, WHITE_QUEEN, false);
    pieces.push_back(WQueen);
    Piece WKing(3, 7, WHITE_KING, false);
    pieces.push_back(WKing);
    Piece rightWBishop(5, 7, WHITE_BISHOP, false);
    pieces.push_back(rightWBishop);
    Piece rightWKnight(6, 7, WHITE_KNIGHT, false);
    pieces.push_back(rightWKnight);
    Piece rightWRook(7, 7, WHITE_ROOK, false);
    pieces.push_back(rightWRook);

    //black pieces
    Piece leftBRook(0, 0, BLACK_ROOK, false);
    pieces.push_back(leftBRook);
    Piece leftBKnight(1, 0, BLACK_KNIGHT, false);
    pieces.push_back(leftBKnight);
    Piece leftBBishop(2, 0, BLACK_BISHOP, false);
    pieces.push_back(leftBBishop);
    Piece BQueen(4, 0, BLACK_QUEEN, false);
    pieces.push_back(BQueen);
    Piece BKing(3, 0, BLACK_KING, false);
    pieces.push_back(BKing);
    Piece rightBBishop(5, 0, BLACK_BISHOP, false);
    pieces.push_back(rightBBishop);
    Piece rightBKnight(6, 0, BLACK_KNIGHT, false);
    pieces.push_back(rightBKnight);
    Piece rightBRook(7, 0, BLACK_ROOK, false);
    pieces.push_back(rightBRook);
    
    for(int i = 0; i < 8; i++){
        Piece BPawn(i, 1, BLACK_PAWN, false);
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

bool Chess::tryToMove(int initialX, int initialY, int initialType, int finalX, int finalY, int finalType){
    int result;
    switch(abs(initialType)){
        case WHITE_BISHOP:
            if(bishopMoves(initialX, initialY, initialType, finalX, finalY, finalType) == POSSIBLE_MOVE){
                eliminatePiece(finalX, finalY);
                eliminatePiece(initialX, initialY);
                addPiece(finalX,finalY, initialType, true);
                return true;
            }
            return false;
        case WHITE_KING:
            result  = kingMoves(initialX, initialY, initialType, finalX, finalY, finalType);
            if(result == POSSIBLE_MOVE){
                eliminatePiece(finalX, finalY);
                eliminatePiece(initialX, initialY);
                addPiece(finalX,finalY, initialType, true);
                return true;
            } else if (result == POSSIBLE_CASTLING){
                eliminatePiece(initialX, initialY);
                addPiece(finalX,finalY, initialType, true);
                int stepX = finalX - initialX;
                int incX = stepX/abs(stepX);

                if(incX > 0 && initialY == 0){
                    eliminatePiece(7, 0);
                    addPiece(5,0, WHITE_ROOK, true);
                } else
                if(incX > 0 && initialY == 7){
                    eliminatePiece(7, 7);
                    addPiece(5,7, BLACK_ROOK, true);
                } else 
                if(incX < 0 && initialY == 0){
                    eliminatePiece(0, 0);
                    addPiece(3,0, WHITE_ROOK, true);
                } else
                if(incX < 0 && initialY == 7){
                    eliminatePiece(0, 7);
                    addPiece(3,7, BLACK_ROOK, true);
                }
            }
            return false;
        case WHITE_KNIGHT:
            if(knightMoves(initialX, initialY, initialType, finalX, finalY, finalType) == POSSIBLE_MOVE){
                eliminatePiece(finalX, finalY);
                eliminatePiece(initialX, initialY);
                addPiece(finalX,finalY, initialType, true);
                return true;
            }
            return false;
        case WHITE_PAWN:
            result = pawnMoves(initialX, initialY, initialType, finalX, finalY, finalType);
            if(result == POSSIBLE_MOVE){
                eliminatePiece(finalX, finalY);
                eliminatePiece(initialX, initialY);
                addPiece(finalX,finalY, initialType, true);
                return true;
            } else if(result == POSSIBLE_CHROWN){
                eliminatePiece(initialX, initialY);
                if(finalY == 7){                    
                    addPiece(finalX,finalY, WHITE_QUEEN, true);
                } else {
                    addPiece(finalX,finalY, BLACK_QUEEN, true);
                }
            }
            return false;
        case WHITE_QUEEN:
            if(queenMoves(initialX, initialY, initialType, finalX, finalY, finalType) == POSSIBLE_MOVE){
                eliminatePiece(finalX, finalY);
                eliminatePiece(initialX, initialY);
                addPiece(finalX,finalY, initialType, true);
                return true;
            }
            return false;
        case WHITE_ROOK:
            if(rookMoves(initialX, initialY, initialType, finalX, finalY, finalType) == POSSIBLE_MOVE){
                eliminatePiece(finalX, finalY);
                eliminatePiece(initialX, initialY);
                addPiece(finalX,finalY, initialType, true);
                return true;
            } 
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

void Chess::addPiece(int x, int y, int type, bool moved){
    Piece newPiece(x, y, type, moved);
    pieces.push_back(newPiece);
}

int Chess::bishopMoves(int x, int y, int type, int finalX, int finalY, int finalType){
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return NOT_POSSIBLE;
    }
    if (abs(finalType) == 2){
        return NOT_POSSIBLE;
    }

    int stepX = finalX - x;
    int stepY = finalY - y;

    if(abs(stepX) != abs(stepY)){
        return NOT_POSSIBLE;
    }

    if(!checkDiagonal(x, y, finalX, finalY)){
        return NOT_POSSIBLE;
    }
    return POSSIBLE_MOVE;

}

int Chess::kingMoves(int x, int y, int type, int finalX, int finalY, int finalType){
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return NOT_POSSIBLE;
    }
    if (abs(finalType) == 2){
        return NOT_POSSIBLE;
    }
    int stepX = finalX - x;
    int stepY = finalY - y;
    
    if (abs(stepX) == 2) {
        if(tryCastling(x, y, stepX/abs(stepX))){
            return POSSIBLE_CASTLING;
        }
    } else if(abs(stepX) == abs(stepY)){
        if(abs(stepX) > 1){
            return NOT_POSSIBLE;
        }
        return POSSIBLE_MOVE;
    } else if(stepX == 0 || stepY == 0){
        if(abs(stepX) > 1 || abs(stepY) > 1){
            return NOT_POSSIBLE;
        }
        return POSSIBLE_MOVE;
    }

    return NOT_POSSIBLE;
    
}

int Chess::knightMoves(int x, int y, int type,int finalX, int finalY, int finalType){
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return NOT_POSSIBLE;
    }
    if (abs(finalType) == 2){
        return NOT_POSSIBLE;
    }

    int stepX = finalX - x;
    int stepY = finalY - y;

    if(stepX == -1 && stepY == 2){
        return POSSIBLE_MOVE;  
    } else if (stepX == -1 && stepY == -2){
        return POSSIBLE_MOVE;  
    } else if (stepX == 1 && stepY == 2){
        return POSSIBLE_MOVE;  
    } else if (stepX == 1 && stepY == -2){
        return POSSIBLE_MOVE;  
    } else if (stepX == 2 && stepY == 1){
        return POSSIBLE_MOVE;  
    } else if (stepX == 2 && stepY == -1){
        return POSSIBLE_MOVE;  
    } else if (stepX == -2 && stepY == 1){
        return POSSIBLE_MOVE;  
    } else if (stepX == -2 && stepY == -1){
        return POSSIBLE_MOVE;  
    } else {
        return NOT_POSSIBLE;
    }     

}

int Chess::pawnMoves(int x, int y, int type, int finalX, int finalY, int finalType){
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return NOT_POSSIBLE;
    }    
    
    if (abs(finalType) == 2){
        return NOT_POSSIBLE;
    }
    int stepX = finalX - x;
    int stepY = finalY - y;

    if(stepY > 0 && type < 0){
        return NOT_POSSIBLE;
    }
    if(stepY < 0 && type > 0){
        return NOT_POSSIBLE;
    }

    if((y == 1 || y == 6) && typeOfSquare(finalX, finalY) == 0 && abs(stepY) == 2){
        return POSSIBLE_MOVE;
    }
    if(abs(stepY) == 1 && typeOfSquare(finalX, finalY) == 0){ 
        if(finalY == 0 || finalY == 7){
            return POSSIBLE_CHROWN;
        }  
        return POSSIBLE_MOVE;
    }
    if((abs(stepX) == abs(stepY)) && abs(stepY) == 1){ 
        return POSSIBLE_MOVE;
    }
    return NOT_POSSIBLE;
}

int Chess::queenMoves(int x, int y, int type, int finalX, int finalY, int finalType){
    
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return NOT_POSSIBLE;
    }
    if (abs(finalType) == 2){
        return NOT_POSSIBLE;
    }
    int stepX = finalX - x;
    int stepY = finalY - y;

    if(stepX == 0 || stepY == 0){
        if(!checkLine(x, y, finalX, finalY)){
            return NOT_POSSIBLE;
        }
        return POSSIBLE_MOVE;
    } else if(abs(stepX) == abs(stepY)){
        if(!checkDiagonal(x, y, finalX, finalY)){
            return NOT_POSSIBLE;
        }
        return POSSIBLE_MOVE;
    }
    return NOT_POSSIBLE;

}

int Chess::rookMoves(int x, int y, int type, int finalX, int finalY, int finalType){
    if((type > 0 && finalType > 0) || (type < 0 && finalType < 0)){
        return NOT_POSSIBLE;    
    }
    if (abs(finalType) == 2){
        return NOT_POSSIBLE;
    }

    int stepX = finalX - x;
    int stepY = finalY - y;

    if(stepX != 0 && stepY != 0){
        return NOT_POSSIBLE;
    }
    
    if(!checkLine(x, y, finalX, finalY)){
        return NOT_POSSIBLE;
    }    
    return POSSIBLE_MOVE;
}

bool Chess::checkDiagonal(int x, int y, int finalX, int finalY){
    int stepX = finalX - x;
    int stepY = finalY - y;
    int xInc = stepX/abs(stepX);
    int yInc = stepY/abs(stepY);

    int i = xInc;
    int j = yInc;
    while(abs(i) < abs(stepX) && abs(j) < abs(stepY)){
        if(typeOfSquare(x+i, y+j) != 0){
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
            if(typeOfSquare(x+i,y) != 0){
                return false;
            }
        }
    } else {
        int yInc = stepY/abs(stepY);
        for(int i = yInc; abs(i)<abs(stepY) ; i+=yInc){
            if(typeOfSquare(x,y+i) != 0){
                return false;
            }
        }
    }
    return true;

}

int Chess::typeOfSquare(int x, int y){
    for(int i = 0; i < pieces.size(); i++){
        if(pieces[i].getCoordinateX() == x && pieces[i].getCoordinateY() == y){
            return pieces[i].getType();
        }
    }
    return 0;
}


//Return a list with the pieces that can take that square
bool Chess::isInCheck(int x, int y){
    std::vector<int> result;

    int finalType = typeOfSquare(x, y);

    for(int i = 0; i < pieces.size(); i++){
        if(abs(pieces[i].getType()) == WHITE_KING){
            continue;
        }
        if(possibleMove(pieces[i].getCoordinateX(), pieces[i].getCoordinateY(), pieces[i].getType(), x, y, finalType)){
            result.push_back(pieces[i].getType());
        }
    }
    std::cout << "la lista de piezas que pueden jaquear: ";
    for(int i = 0; i < result.size();i++){
        std::cout << result[i];
    }

    if(result.size() == 0){
        return false;
    }

    if(finalType == 0){//empty square checking castling
        if(y == 0){
            for(int i = 0; i < result.size(); i++){
                if (result[i] < 0){
                    return true;
                }
            }
            return false;
        } else if (y == 7){
            for(int i = 0; i < result.size(); i++){
                if (result[i] > 0){
                    return true;
                }
            }
            return false;
        } 
    } else if (finalType > 0){
        for(int i = 0; i < result.size(); i++){
                if (result[i] < 0){
                    return true;
                }
        }
        return false;
    } else {
        for(int i = 0; i < result.size(); i++){
            if (result[i] > 0){
                return true;
            }
        }
        return false;
    }    

}

Piece Chess::foundPiece(int x, int y){
    for(int i = 0; i < pieces.size(); i++){
        if(pieces[i].getCoordinateX() == x && pieces[i].getCoordinateY() == y){
            return pieces[i];
        }
    }
}

bool Chess::tryCastling(int x, int y, int incX){
    Piece king = foundPiece(x, y);
    if(king.hasMoved()){
        return false;
    }

    if(incX > 0 && y == 0){
        if(typeOfSquare(7,0) != 6){
            return false;
        }
        Piece rook = foundPiece(7, 0);
        if(rook.hasMoved()){
            return false;
        }
        if(isInCheck(7,0)){
            return false;
        }

    } else
    if(incX > 0 && y == 7){
        if(typeOfSquare(7,7) != -6){
            return false;
        }
        Piece rook = foundPiece(7, 7);
        if(rook.hasMoved()){
            return false;
        }
        if(isInCheck(7,7)){
            return false;
        }
    } else 
    if(incX < 0 && y == 0){
        if(typeOfSquare(0,0) != 6){
            return false;
        }
        Piece rook = foundPiece(0, 0);
        if(rook.hasMoved()){
            return false;
        }
        if(isInCheck(0,0)){
            return false;
        }
    } else
    if(incX < 0 && y == 7){
        if(typeOfSquare(0,7) != -6){
            return false;
        }
        Piece rook = foundPiece(0, 7);
        if(rook.hasMoved()){
            return false;
        }
        if(isInCheck(0,7)){
            return false;
        }
    }


    for(int i = x + incX; i != 0 && i != 7; i += incX){
        std::cout << "i: " << i << "\n";
        if(typeOfSquare(i, y) != 0){
            std::cout << "el casillero:  " << i << " " << y << " está lleno\n";
            return false;            
        }
        if(isInCheck(i, y)){
            std::cout << "el casillero:  " << i << " " << y << " está en jaque\n";
            return false;
        }
    }
    return true;
}
