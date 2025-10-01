#pragma once
#include "Player.h"
#include <vector>

// Class to represent a computer player that prefers placing its move adjacent
// to its own marks in previous turns. It follows a straight-line strategy.
class AdjacentPlayer : public Player {
public:
    explicit AdjacentPlayer(char m) : Player(m) {}

    Move getMove(const Board& b) override {
        std::vector<Move> adjacentMoves;

        // Scan the board for adjacent moves to the player's existing marks
        for (int r = 0; r < b.getRows(); ++r) {
            for (int c = 0; c < b.getCols(); ++c) {
                if (b.at(r, c) == this->symbol()) {
                    checkAdjacent(b, r - 1, c, adjacentMoves); // Check up
                    checkAdjacent(b, r + 1, c, adjacentMoves); // Check down
                    checkAdjacent(b, r, c - 1, adjacentMoves); // Check left
                    checkAdjacent(b, r, c + 1, adjacentMoves); // Check right
                }
            }
        }

        if (!adjacentMoves.empty()) {
            return adjacentMoves[rand() % adjacentMoves.size()]; // Choose randomly from valid adjacent moves
        }

        return getRandomMove(b);  // Fallback to random move
    }

private:
    void checkAdjacent(const Board& b, int r, int c, std::vector<Move>& adjacentMoves) {
        if (b.inBounds(r, c) && b.at(r, c) == ' ') {
            adjacentMoves.push_back(Move{r, c});
        }
    }

    Move getRandomMove(const Board& b) {
        while (true) {
            int r = rand() % b.getRows();
            int c = rand() % b.getCols();
            if (b.at(r, c) == ' ') {
                return Move{r, c};
            }
        }
    }
};
