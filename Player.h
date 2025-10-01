#pragma once
#include "Board.h"

struct Move { int r; int c; };  // Move coordinates

class Player {
protected:
    char mark;  // 'O' or 'X'

public:
    explicit Player(char m) : mark(m) {}
    virtual ~Player() {}

    char symbol() const { return mark; }
    virtual Move getMove(const Board& b) = 0;  // Virtual function to get a player's move
};
