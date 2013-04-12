/*
 * File:   Chess.cpp
 * Author: Shivalik Narad
 *
 * Created on April 27, 2012, 11:52 PM
 */

#include <iostream>
#include "Chess.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <math.h>

using namespace std;

//initializing the pieces with an ID
const int pawn = 1;
const int rook = 2;
const int knight = 3;
const int bishop = 4;
const int queen = 5;
const int king = 6;

//constructor
Chess::Chess(){}

//resets the chess board
void Chess::reset()
{
   _chessBoard[0][0] = rook ;
   _chessBoard[0][1] = knight;
   _chessBoard[0][2] = bishop;
   _chessBoard[0][3] = queen;
   _chessBoard[0][4] = king;
   _chessBoard[0][5] = bishop;
   _chessBoard[0][6] = knight;
   _chessBoard[0][7] = rook;
   _chessBoard[1][0] = pawn;
   _chessBoard[1][1] = pawn;
   _chessBoard[1][2] = pawn;
   _chessBoard[1][3] = pawn;
   _chessBoard[1][4] = pawn;
   _chessBoard[1][5] = pawn;
   _chessBoard[1][6] = pawn;
   _chessBoard[1][7] = pawn;
   _chessBoard[2][0] = 0;
   _chessBoard[2][1] = 0;
   _chessBoard[2][2] = 0;
   _chessBoard[2][3] = 0;
   _chessBoard[2][4] = 0;
   _chessBoard[2][5] = 0;
   _chessBoard[2][6] = 0;
   _chessBoard[2][7] = 0;
   _chessBoard[3][0] = 0;
   _chessBoard[3][1] = 0;
   _chessBoard[3][2] = 0;
   _chessBoard[3][3] = 0;
   _chessBoard[3][4] = 0;
   _chessBoard[3][5] = 0;
   _chessBoard[3][6] = 0;
   _chessBoard[3][7] = 0;
   _chessBoard[4][0] = 0;
   _chessBoard[4][1] = 0;
   _chessBoard[4][2] = 0;
   _chessBoard[4][3] = 0;
   _chessBoard[4][4] = 0;
   _chessBoard[4][5] = 0;
   _chessBoard[4][6] = 0;
   _chessBoard[4][7] = 0;
   _chessBoard[5][0] = 0;
   _chessBoard[5][1] = 0;
   _chessBoard[5][2] = 0;
   _chessBoard[5][3] = 0;
   _chessBoard[5][4] = 0;
   _chessBoard[5][5] = 0;
   _chessBoard[5][6] = 0;
   _chessBoard[5][7] = 0;
   _chessBoard[6][0] = -pawn;
   _chessBoard[6][1] = -pawn;
   _chessBoard[6][2] = -pawn;
   _chessBoard[6][3] = -pawn;
   _chessBoard[6][4] = -pawn;
   _chessBoard[6][5] = -pawn;
   _chessBoard[6][6] = -pawn;
   _chessBoard[6][7] = -pawn;
   _chessBoard[7][0] = -rook;
   _chessBoard[7][1] = -knight;
   _chessBoard[7][2] = -bishop;
   _chessBoard[7][3] = -queen;
   _chessBoard[7][4] = -king;
   _chessBoard[7][5] = -bishop;
   _chessBoard[7][6] = -knight;
   _chessBoard[7][7] = -rook;

   _currentPlayer = 1;
   _turnCounter = 1;
   _takenPieces = "";
    exitGame = 0;
    status = 0;

}//end of reset


//returns either 1 or 2 to alternate the turns
int Chess::opponentPlayer()
{
  if(_currentPlayer == 1) return 2;
  return 1;
}//end of opponentPlayer


//returns the color of the _currentPlayer
string Chess::currentPlayerColor()
{
  if(_currentPlayer == 1) return "WHITE";
  return "BLACK";
}//end of currentPlayer


//returns the color of the opponent player
string Chess::opponentPlayerColor()
{
  if(_currentPlayer == 1) return "BLACK";
  return "WHITE";
}//end of opponentPlayerColor


//returns the pieces to be place on the chess board
string Chess::displayPiece(int piece,int removeSpace = 0)
{
  string str = "";
  if(piece > 0)
  { // WHITE piece
    if(removeSpace==1)
    {
      switch(piece)
      {
        case rook:    str = "\u2656"; break;
        case knight:  str = "\u2658"; break;
        case bishop:  str = "\u2657"; break;
        case queen:   str = "\u2655"; break;
        case king:    str = "\u2654"; break;
        case pawn:    str = "\u2659"; break;
      }
    }
    else
    {
      switch(piece)
      {
        case rook:    str = " \u2656 "; break;
        case knight:  str = " \u2658 "; break;
        case bishop:  str = " \u2657 "; break;
        case queen:   str = " \u2655 "; break;
        case king:    str = " \u2654 "; break;
        case pawn:    str = " \u2659 "; break;
      }
    }
  }
  else
  {
    if(piece < 0)
    {//BLACK pieces
      switch(-piece)
      {
        case rook:    str = " \u265C "; break;
        case knight:  str = " \u265E "; break;
        case bishop:  str = " \u265D "; break;
        case queen:   str = " \u265B "; break;
        case king:    str = " \u265A "; break;
        case pawn:    str = " \u265F "; break;
      }
    }
    else
    {
      if(removeSpace == 1) return "";
      str = "   ";
    }
  }
  return str;
}//end of displayPiece


//help the players to keep track of the pieces taken
string Chess::piecesTaken()
{
  string show = _takenPieces;
  if(show.length()==0)
  {
      show = "NO PIECES TAKEN YET !!!!";
  }
  return show;
}//end of piecesTaken


//prints the chess board
void Chess::printBoard()
{
  cout <<endl<<endl;
  cout << "    a   b   c   d   e   f   g   h"<<endl;
  cout << "  #################################"<<endl;
  for(int i = 7; i >= 0 ; --i)
  {
      switch(i)
      {
          case 0: cout<< "1 "; break;
          case 1: cout<< "2 "; break;
          case 2: cout<< "3 "; break;
          case 3: cout<< "4 "; break;
          case 4: cout<< "5 "; break;
          case 5: cout<< "6 "; break;
          case 6: cout<< "7 "; break;
          case 7: cout<< "8 "; break;
      }
      cout<<"#";
      for(int j = 0; j < 8; ++j)
      {
          cout<< displayPiece(_chessBoard[i][j]);
          if(j<7)cout<<"|";
          if(i == 0 && j == 7 || i == 1 && j == 7)cout<<"# WHITE"<<endl;
          if(i == 6 && j == 7 || i == 7 && j == 7)cout<<"# BLACK"<<endl;
          if(i == 4 && j == 7)cout <<"#         Taken pieces: "<<endl;
          if(i == 3 && j == 7)cout <<"#         "<< piecesTaken() <<endl;
          if(i != 0 && i != 1 && i != 6 && i != 7 && i != 4 && i != 3 && j == 7) cout<<"#"<<endl;
      }
        if(i>0)  cout << "  #===============================#"<<endl;
        if(i==0) cout << "  #################################"<<endl;

  }
}//end of printBoard


//checks if the move if VALID or INVALID
int Chess::legalMove(int from_X, int from_Y, int to_X, int to_Y)
{
    int source = _chessBoard[from_Y][from_X];
    int destination = _chessBoard[to_Y][to_X];
    switch(abs(source))
    {
        case 1://PAWN
            if(to_X==from_X && abs(to_Y-from_Y)==1 && destination==0) return 1;
            if(abs(to_X-from_X)==1 && abs(to_Y-from_Y)==1 && destination!= 0) return 1;
            if(_currentPlayer == 1 && from_Y==1 && abs(from_Y-to_Y)==2 && destination == 0) return 1;
            if(_currentPlayer == 2 && from_Y==6 && abs(from_Y-to_Y)==2 && destination == 0) return 1;
            break;

        case 2://ROOK
             if(to_X==from_X)
             {
                if(to_Y>from_Y)//Moving vertically
                { // Downards
                        for(size_t row = (unsigned)(from_Y+1); row < (unsigned)to_Y; ++row)
                        {  if(_chessBoard[row][to_X] != 0) return 0;    }
                }
                else
                { // Upwards
                        for(size_t row = (unsigned)(to_Y + 1); row < (unsigned)(from_Y); ++row)
                        {  if(_chessBoard[row][to_X] != 0) return 0;    }
                }
                return 1;
             }
             if(to_Y==from_Y)
             {
                if(to_X>from_X)// Moving horizontally
                { // Rightwards
                        for(size_t column = (unsigned)(from_X+1); column < (unsigned)to_X; ++column)
                        {   if(_chessBoard[to_Y][column] != 0) return 0;    }
                }

                else
                { // Leftwards
                        for(size_t column = (unsigned)(to_X+1); column < (unsigned)(from_X); ++column)
                        {  if(_chessBoard[to_Y][column] != 0) return 0;    }
                }
                return 1;
              }
            return 0;
            break;

        case 3:// KNIGHT
            if((abs(to_Y-from_Y)==2 && abs(to_X-from_X)==1) || (abs(to_X-from_X)==2 && abs(to_Y-from_Y)==1)) return 1;
            return 0;
            break;

        case 4://BISHOP
            if(abs(to_Y-from_Y) == abs(to_X-from_X))
            { // Moving diagonally
                if(to_Y>from_Y)
                { // South
                        int column = min(to_X, from_X)+1;
                        for(size_t row = from_Y+1; row < (unsigned)to_Y; ++row)
                        {
                        if(_chessBoard[row][column] != 0) return 0;
                        column ++;
                        }
                return 1;
                }
                if(to_Y<from_Y || to_X>from_X)
                { // North
                        int column = min(to_X, from_X)+1;
                        for(size_t row = from_Y+1; row < (unsigned)to_Y; ++row)
                        {
                        if(_chessBoard[row][column] != 0) return 0;
                        column ++;
                        }
                return 1;
                }
            }
            return 0;
            break;

        case 5://QUEEN

            if(to_X==from_X)
             {
                if(to_Y>from_Y)//Moving vertically
                { // Downards
                        for(size_t row = (unsigned)(from_Y+1); row < (unsigned)to_Y; ++row)
                        {  if(_chessBoard[row][to_X] != 0) return 0;    }
                }
                else
                { // Upwards
                        for(size_t row = (unsigned)(to_Y + 1); row < (unsigned)(from_Y); ++row)
                        {  if(_chessBoard[row][to_X] != 0) return 0;    }
                }
                return 1;
             }
             if(to_Y==from_Y)
             {
                if(to_X>from_X)// Moving horizontally
                { // Rightwards
                        for(size_t column = (unsigned)(from_X+1); column < (unsigned)to_X; ++column)
                        {   if(_chessBoard[to_Y][column] != 0) return 0;    }
                }

                else
                { // Leftwards
                        for(size_t column = (unsigned)(to_X+1); column < (unsigned)(from_X); ++column)
                        {  if(_chessBoard[to_Y][column] != 0) return 0;    }
                }
                return 1;
              }

            if(abs(to_Y-from_Y) == abs(to_X-from_X))
            { // Moving diagonally
                if(to_Y>from_Y)
                { // South
                        int column = min(to_X, from_X)+1;
                        for(size_t row = from_Y+1; row < (unsigned)to_Y; ++row)
                        {
                        if(_chessBoard[row][column] != 0) return 0;
                        column ++;
                        }
                return 1;
                }
                if(to_Y<from_Y || to_X>from_X)
                { // North
                        int column = min(to_X, from_X)+1;
                        for(size_t row = from_Y+1; row < (unsigned)to_Y; ++row)
                        {
                        if(_chessBoard[row][column] != 0) return 0;
                        column ++;
                        }
                return 1;
                }
            }


            return 0;
            break;

        case 6://KING
            if(abs(to_Y - from_Y) <= 1 && abs(to_X - from_X) <=1) return 1;
            return 0;
            break;
    }
    return 0;
}//end of legalMove


//assigns the taken piece to piecesTaken()
void Chess::checkTakenPiece(int piece)
{
  string storePiece = displayPiece(piece,1);
  if(storePiece.length()>0)
  {
    if(_takenPieces.length()>0) _takenPieces = _takenPieces+",";
     _takenPieces=_takenPieces+displayPiece(piece);
  }
}//end of checkTakenPiece


//prints the help message
void Chess::help()
{
  cout <<endl<<endl;
  cout<<"           _______________________________________________________________________________________________"<<endl;
  cout<<"          |__________________________________________HELP MENU____________________________________________|"<<endl;
  cout<<"          |_______________________________________________________________________________________________|"<<endl;
  cout<<"          |   1) To move the pieces use \"from>to\" eg. \"a2>a3\" will move the pawn from \"a2\" to \"a3\".       |"<<endl;
  cout<<"          |_______________________________________________________________________________________________|"<<endl;
  cout<<"          |   2) If you get the warning INVALID MOVE, following are possible                              |"<<endl;
  cout<<"          |           -->that move is not meant for the piece you selected.                               |"<<endl;
  cout<<"          |           -->you might be taking off your own piece with that move.                           |"<<endl;
  cout<<"          |           -->you might be moving your piece out of the chess_board.                           |"<<endl;
  cout<<"          |                                                                                               |"<<endl;
  cout<<"          |      To learn about VALID MOVES go to the following link                                      |"<<endl;
  cout<<"          |           --> http://en.wikipedia.org/wiki/Chess                                              |"<<endl;
  cout<<"          |_______________________________________________________________________________________________|"<<endl;
  cout<<"          |   3) Type \"display\" to display the present condition of the chess_board.                      |"<<endl;
  cout<<"          |_______________________________________________________________________________________________|"<<endl;
  cout<<"          |   4) Type \"reset\" to reset the chess chess_board.                                             |"<<endl;
  cout<<"          |_______________________________________________________________________________________________|"<<endl;
  cout<<"          |   5) Type \"exit\" or \"quit\" to exit out of the game.                                           |"<<endl;
  cout<<"          |_______________________________________________________________________________________________|"<<endl;
}//end of help


//returns a letter (after converting the number to a letter)
string Chess::getLetter(int column)
{
  switch(column)
  {
    case 0: return "a"; break;
    case 1: return "b"; break;
    case 2: return "c"; break;
    case 3: return "d"; break;
    case 4: return "e"; break;
    case 5: return "f"; break;
    case 6: return "g"; break;
  }
  return "N/A";
}//end of getLetter

//returns a number (after converting the letter to a number)
int Chess::getNumber(string letter)
{
  if(letter == "a") return 0;
  if(letter == "b") return 1;
  if(letter == "c") return 2;
  if(letter == "d") return 3;
  if(letter == "e") return 4;
  if(letter == "f") return 5;
  if(letter == "g") return 6;
  if(letter == "h") return 7;
  return 0;
}//end of getNumber


//to take in the user input and check if the input is a VALID or INVALID move or command
int Chess::getMove()
{
    cout<<endl;
    cout<<"Turn "<<_turnCounter<<". "<<currentPlayerColor() <<", make a move:";
    string getMove;
    cin>>getMove;

    if(getMove == "help")
    {
        help();
        printBoard();
        return 0;
    }

    if(getMove == "reset")
    {
        reset();
        return 0;
    }

    if(getMove == "display")
    {
        printBoard();
        return 0;
    }

    if(getMove == "exit" || getMove == "quit")
    {
        cout<<endl;
        cout << "OKAY BYE! Come back when you can stay longer..."<<endl<<endl;
        exit(1);
    }

    int from_X = 0;
    int from_Y = 0;
    int to_X = 0;
    int to_Y = 0;
    string fromX = getMove.substr(0,getMove.find(">")).substr(0,1);
    string fromY = getMove.substr(0,getMove.find(">")).substr(1,1);
    string toX   = getMove.substr(getMove.find(">")+1, getMove.length()).substr(0, 1);
    string toY   = getMove.substr(getMove.find(">")+1, getMove.length()).substr(1, 1);
    from_X = getNumber(fromX);
    from_Y = atoi(fromY.c_str())-1;
    to_X = getNumber(toX);
    to_Y = atoi(toY.c_str())-1;

    int source = _chessBoard[from_Y][from_X];
    int destination = _chessBoard[to_Y][to_X];
    if((_currentPlayer == 1 && (source <= 0 || destination > 0)) || (_currentPlayer == 2 && (source >= 0 || destination < 0)) || !legalMove(from_X, from_Y , to_X, to_Y))
    {
    cout << "INVALID MOVE\n"; return 0;
    }

  // to move the pieces on the board
  _chessBoard[from_Y ][from_X] = 0;
  _chessBoard[to_Y][to_X] = source;
  checkTakenPiece(destination);

  //when the opponent targets the king
  //checks for the winner
  //sets the status to the _currentPlayer
  if(abs(destination) == king)
  {
    status = _currentPlayer;
    return 0;
  }

  _turnCounter ++;
  _currentPlayer = opponentPlayer();//alternates the turn between two players
  printBoard();

  return 0;
}//end of getMove
