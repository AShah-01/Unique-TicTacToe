# Unique-TicTacToe

This project implements a customizable Tic-Tac-Toe game in C++. You can set the board size and the win condition (k-in-a-row). The game supports different player types, including human and random AI.

## How it works

- When you run the program, you will be prompted to enter the number of rows, columns, and the win length (k).
- You can choose the game mode (human vs random AI, or other modes if implemented).
- Players take turns entering their moves until one wins or the board is full.

## How to run

Open a terminal in the project directory and compile the code with:
"g++ -std=c++17 -g Board.cpp Game.cpp Main.cpp -o KTicTacToe"

Then run the game with:
"./KTicTacToe"
