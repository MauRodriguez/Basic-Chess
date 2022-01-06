#include "chess.h"
#include "piece.h"

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

void Chess::bestMovement(){}

void Chess::hasWon(){}