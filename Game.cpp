#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

void KTicTacToeGame::run() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    char current = p1->symbol();  // Start with Player 1 (O)
    int turn = 1;  // Counter for alternating turns

    while (true) {
        board.print();
        Player* currentPlayer = (turn % 2 == 1) ? p1 : p2;
        cout << "Player " << currentPlayer->symbol() << "'s turn:" << endl;

        Move m = currentPlayer->getMove(board);

        if (!board.inBounds(m.r, m.c)) {
            cout << "Invalid move. Position out of bounds. Try again." << endl;
            continue;
        }
        if (!board.place(m.r, m.c, currentPlayer->symbol())) {
            cout << "Invalid move. Cell already occupied. Try again." << endl;
            continue;
        }

        if (board.checkWin(k, currentPlayer->symbol())) {
            board.print();
            cout << "Player " << currentPlayer->symbol() << " wins!" << endl;
            break;
        }

        if (board.full()) {
            board.print();
            cout << "The game is a tie!" << endl;
            break;
        }

        turn++;
    }
}
