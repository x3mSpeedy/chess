
/*
 * File:   Chess.h
 * Author: Shivalik Narad
 *
 * Created on April 28, 2012, 12:00 AM
 */

#ifndef CHESS_H
#define	CHESS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Chess
{
public:
    int exitGame;
    int status ;

    Chess();//class constructor

    void help();
    void printBoard();
    void reset();
    void checkTakenPiece(int piece);

    int opponentPlayer();
    int getMove();
    int getNumber(string letter);
    int legalMove(int from_X, int from_Y, int to_X, int to_Y);

    string piecesTaken();
    string getLetter(int column);
    string currentPlayerColor();
    string opponentPlayerColor();
    string displayPiece(int piece,int suppressblank);

private:
    int _chessBoard [8][8];//2D array for the chess board
    int _currentPlayer;//determine the current player.
    int _turnCounter;//to count the number of moves that have been made by the player.
    string _takenPieces;//display the pieces taken.
};

#endif	/* CHESS_H */

