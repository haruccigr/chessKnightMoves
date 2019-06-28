How to run the program

Option 1 using cmake:

    Go the folder, by terminal, where the files are stored

    - For Linux/Mac users:

        $ mkdir build
        $ cd build
        $ cmake ..
        $ make
        $ ./chessKnightMoves

    - For Windows users:
    
        Use the CMAKE graphical interface and follow the instructions. It will
        create a visual studio project.

Option 2 using gcc compiler (for Linux/Mac users only):

    Go the folder, by terminal, where the files are stored

    $ gcc -Wall -g chessKnightMoves.c -o chessKnightMoves
    $ ./chessKnightMoves