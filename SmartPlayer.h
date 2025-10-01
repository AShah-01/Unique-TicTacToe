#pragma once
#include "Player.h"

// Keep it simple: look for immediate wins or blocks.
// 1) If placing my mark makes me win (checkWin(k, mark)) -> do it.
// 2) Else if placing my mark stops opponent’s immediate win -> do it.
// 3) Else prefer extending my longest line (heuristic score).
// NOTE: You need Board::checkWin implemented, plus a tiny scoring function.
class SmartPlayer : public Player {
    int k;         // needed for k-in-a-row check
    char opp;      // 'O' or 'X'
public:
    SmartPlayer(char m, int kk) : Player(m), k(kk), opp(m=='O'?'X':'O') {}
    Move getMove(const Board& b) override {
        // TODO: loop all empty cells:
        //  - Temporarily place mark, test checkWin(k, mark), undo. If win -> return that.
        //  - Temporarily place opp, test checkWin(k, opp), undo. If opp would win -> block that.
        //  - Otherwise keep the move with best "line-extension" score.
        return Move{0,0}; // placeholder
    }
};
