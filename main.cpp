
/*
 * File:   main.cpp
 * Author: Shivalik Narad
 *
 * Created on April 27, 2012, 11:52 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <cstring>
#include "Chess.h"

using namespace std;

int main(int argc, const char* argv[])
{

			// profiling test
			cout << "counting" << endl;
			int i = 0;
			int j = 0;
			for (i = 0; i < 1000*1000*1000; i++) {
				j = j + i;
			}
			cout << j << endl;
			// profiling test


            //will display a welcome message.
            cout<<"             __________________________________________________________________________________"<<endl;
            cout<<"            |Welcome to the CHESS application. It is designed to be played by two human beings.|"<<endl;
            cout<<"            |For further information about using the app type in \"help\"                        |"<<endl;
            cout<<"            |__________________________________________________________________________________|"<<endl;

            Chess a;//create an object of the Chess class.
            a.reset();//calling the reset function so that the chess board can get initialized.
            a.printBoard();//after initializing the board printBoard will print the board layout on screen.

            //this loop will keep on continuing the game until the user wins or wishes to quit.
            while(a.exitGame == 0)
                 {
                      while(a.status == 0) { a.getMove (); }

                        //display the winner and ask if the user wants to continue
                        cout << a.currentPlayerColor() << " is the WINNER! Do you wish to start a new game? [y/n]:";
                        string newGame = "y";
                        cin >> newGame;
                        if(newGame == "y")
                        {
                                a.reset();
                                a.printBoard();
                        }
                        else
                        {
                                cout << "OKAY BYE! Come back when you can stay longer..."<<endl;
                                a.exitGame = 1;
                        }
                }

  return 0;
}//end of main
