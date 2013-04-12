//readme.txt
//Shivalik Narad
//HW3 Project Chess

Name    : Shivalik Narad
Vesrsion: Command-line

//NOTE: i am using unicode characters to presents the chess pieces on the chess board.
	it might be possible that they show small blocks instead of a actual piece on a 
	different terminal, however if it runs fine then the output will match the sample run 
	provided below.

REQUIREMENTS:
======================================================================================================
1) g++ compiler 
2) recommended run the program using the "linux terminal" or "mac terminal" or the CodeBlocks IDE "terminal"
3) do NOT use the netbeans IDE terminal as it will not produce the symbols on the chess board. only use 
	one of the above mentioned inorder to make the chess piece symbols visible on screen.

PLAYING INSTRUCTIONS:
======================================================================================================

"$" -- command prompt. Might differ depending on the platform you use.

1) open the terminal and go to the directory where you have all the files saved i.e.
	[ Chess.cpp Chess.h main.cpp ]

2) compile all the files alltogether using the command 
	[ $ g++ Chess.cpp Chess.h main.cpp ]

3) step 2 will make a "a.out" file. you can check it using the [ $ ls ] command.

4) now to start the game type 
	[ $ ./a.out play ]  
	
	IMPORTANT NOTE: in the above command argv[0] is "./a.out" and argv[1] is "play".
	argv[1] should always be "play" 
	
5) if you have executed all the above steps properly then you will be able to see a welcome message on the screen 
   and below that there will be a printed chess board (sample run is provided below).
  
6) while in the game type "help" for more information about playing the game.


SAMPLE RUN USING A LINUX TERMINAL
======================================================================================================
shivalik@shivalik-Inspiron-N4010 ~/NetBeansProjects/CHESS $ 

shivalik@shivalik-Inspiron-N4010 ~/NetBeansProjects/CHESS $ ls
a3  build  Chess.cpp  Chess.h  Chess.h.gch  dist  main.cpp  Makefile  nbproject

shivalik@shivalik-Inspiron-N4010 ~/NetBeansProjects/CHESS $ g++ main.cpp Chess.cpp Chess.h

shivalik@shivalik-Inspiron-N4010 ~/NetBeansProjects/CHESS $ ls
a3  a.out  build  Chess.cpp  Chess.h  Chess.h.gch  dist  main.cpp  Makefile  nbproject

shivalik@shivalik-Inspiron-N4010 ~/NetBeansProjects/CHESS $ ./a.out play
             __________________________________________________________________________________
            |Welcome to the CHESS application. It is designed to be played by two human beings.|
            |For further information about using the app type in "help"                        |
            |__________________________________________________________________________________|


    a   b   c   d   e   f   g   h
  #################################
8 # ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ # BLACK
  #===============================#
7 # ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ # BLACK
  #===============================#
6 #   |   |   |   |   |   |   |   #
  #===============================#
5 #   |   |   |   |   |   |   |   #         Taken pieces: 
  #===============================#
4 #   |   |   |   |   |   |   |   #         NO PIECES TAKEN YET !!!!
  #===============================#
3 #   |   |   |   |   |   |   |   #
  #===============================#
2 # ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ # WHITE
  #===============================#
1 # ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ # WHITE
  #################################

Turn 1. WHITE, make a move:a2>a4


    a   b   c   d   e   f   g   h
  #################################
8 # ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ # BLACK
  #===============================#
7 # ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ # BLACK
  #===============================#
6 #   |   |   |   |   |   |   |   #
  #===============================#
5 #   |   |   |   |   |   |   |   #         Taken pieces: 
  #===============================#
4 # ♙ |   |   |   |   |   |   |   #         NO PIECES TAKEN YET !!!!
  #===============================#
3 #   |   |   |   |   |   |   |   #
  #===============================#
2 #   | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ # WHITE
  #===============================#
1 # ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ # WHITE
  #################################

Turn 2. BLACK, make a move:b7>b5


    a   b   c   d   e   f   g   h
  #################################
8 # ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ # BLACK
  #===============================#
7 # ♟ |   | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ # BLACK
  #===============================#
6 #   |   |   |   |   |   |   |   #
  #===============================#
5 #   | ♟ |   |   |   |   |   |   #         Taken pieces: 
  #===============================#
4 # ♙ |   |   |   |   |   |   |   #         NO PIECES TAKEN YET !!!!
  #===============================#
3 #   |   |   |   |   |   |   |   #
  #===============================#
2 #   | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ # WHITE
  #===============================#
1 # ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ # WHITE
  #################################

Turn 3. WHITE, make a move:a4>b5


    a   b   c   d   e   f   g   h
  #################################
8 # ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ # BLACK
  #===============================#
7 # ♟ |   | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ # BLACK
  #===============================#
6 #   |   |   |   |   |   |   |   #
  #===============================#
5 #   | ♙ |   |   |   |   |   |   #         Taken pieces: 
  #===============================#
4 #   |   |   |   |   |   |   |   #          ♟ 
  #===============================#
3 #   |   |   |   |   |   |   |   #
  #===============================#
2 #   | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ # WHITE
  #===============================#
1 # ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ # WHITE
  #################################

Turn 4. BLACK, make a move:a7>a6


    a   b   c   d   e   f   g   h
  #################################
8 # ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ # BLACK
  #===============================#
7 #   |   | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ # BLACK
  #===============================#
6 # ♟ |   |   |   |   |   |   |   #
  #===============================#
5 #   | ♙ |   |   |   |   |   |   #         Taken pieces: 
  #===============================#
4 #   |   |   |   |   |   |   |   #          ♟ 
  #===============================#
3 #   |   |   |   |   |   |   |   #
  #===============================#
2 #   | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ # WHITE
  #===============================#
1 # ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ # WHITE
  #################################

Turn 5. WHITE, make a move:a1>a6


    a   b   c   d   e   f   g   h
  #################################
8 # ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ # BLACK
  #===============================#
7 #   |   | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ # BLACK
  #===============================#
6 # ♖ |   |   |   |   |   |   |   #
  #===============================#
5 #   | ♙ |   |   |   |   |   |   #         Taken pieces: 
  #===============================#
4 #   |   |   |   |   |   |   |   #          ♟ , ♟ 
  #===============================#
3 #   |   |   |   |   |   |   |   #
  #===============================#
2 #   | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ # WHITE
  #===============================#
1 #   | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ # WHITE
  #################################

Turn 6. BLACK, make a move:a8>a6


    a   b   c   d   e   f   g   h
  #################################
8 #   | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ # BLACK
  #===============================#
7 #   |   | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ # BLACK
  #===============================#
6 # ♜ |   |   |   |   |   |   |   #
  #===============================#
5 #   | ♙ |   |   |   |   |   |   #         Taken pieces: 
  #===============================#
4 #   |   |   |   |   |   |   |   #          ♟ , ♟ , ♖ 
  #===============================#
3 #   |   |   |   |   |   |   |   #
  #===============================#
2 #   | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ # WHITE
  #===============================#
1 #   | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ # WHITE
  #################################

Turn 7. WHITE, make a move:b5>a6


    a   b   c   d   e   f   g   h
  #################################
8 #   | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ # BLACK
  #===============================#
7 #   |   | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ # BLACK
  #===============================#
6 # ♙ |   |   |   |   |   |   |   #
  #===============================#
5 #   |   |   |   |   |   |   |   #         Taken pieces: 
  #===============================#
4 #   |   |   |   |   |   |   |   #          ♟ , ♟ , ♖ , ♜ 
  #===============================#
3 #   |   |   |   |   |   |   |   #
  #===============================#
2 #   | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ # WHITE
  #===============================#
1 #   | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ # WHITE
  #################################

Turn 8. BLACK, make a move:exit

OKAY BYE! Come back when you can stay longer...

shivalik@shivalik-Inspiron-N4010 ~/NetBeansProjects/CHESS $ 

=======================================================================================================
