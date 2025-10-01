#pragma once
#include "Board.h"
#include "Player.h"

class KTicTacToeGame {
private:
    Board board;
    int k;               // How many in a row to win
    Player* p1;          // Player 1
    Player* p2;          // Player 2

public:
    KTicTacToeGame(int rows, int cols, int kk, Player* a, Player* b)
        : board(rows, cols), k(kk), p1(a), p2(b) {}

    void run();  // Main game loop
};
