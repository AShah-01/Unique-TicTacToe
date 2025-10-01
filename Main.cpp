#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"  // For AI functionality

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int m, n, k;
    std::cout << "Board rows (Highly suggested >=3, <=15): ";
    std::cin >> m;
    std::cout << "Board cols (Highly suggested >=3, <=15): ";
    std::cin >> n;
    std::cout << "Win length k (>=3, <=min(m,n)): ";
    std::cin >> k;

    std::cout << "Mode: 1) human vs random  2) adjacent vs random  -> ";
    int mode = 1;
    std::cin >> mode;

    Player* A = nullptr;
    Player* B = nullptr;

    if (mode == 1) {
        A = new HumanPlayer('O');
        B = new RandomPlayer('X');
    } else {
        A = new HumanPlayer('O');
        B = new RandomPlayer('X');
    }

    KTicTacToeGame game(m, n, k, A, B);
    game.run();

    delete A;
    delete B;
    return 0;
}
