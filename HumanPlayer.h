#pragma once
#include "Player.h"
#include <iostream>

class HumanPlayer : public Player {
public:
    explicit HumanPlayer(char m) : Player(m) {}

    Move getMove(const Board& b) override {
        int rr, cc;
        std::cout << "Player " << mark << " move ('row' + *space* + 'column'): ";
        std::cin >> cc >> rr;
        return Move{ cc - 1, rr - 1 };
    }
};
