#pragma once
#include "Player.h"
#include <cstdlib>  // rand
#include <ctime>

class RandomPlayer : public Player {
public:
    explicit RandomPlayer(char m) : Player(m) {}

    Move getMove(const Board& b) override {
        // Improved approach: scan the board and pick a random empty cell
        while (true) {
            // Randomly pick a row and column
            int r = std::rand() % b.getRows();  // Random row (within the board size)
            int c = std::rand() % b.getCols();  // Random column (within the board size)

            // If the cell is empty, return the move
            if (b.at(r, c) == ' ') {
                return Move{r, c};
            }
        }
    }
};
