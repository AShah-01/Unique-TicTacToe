#include "Board.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

// Constructor: Dynamically allocate a 2D array for the board
Board::Board(int r, int c) : rows(r), cols(c) {
    grid = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new char[cols];
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = ' '; // Initialize the board with empty spaces
        }
    }
}

// Destructor: Deallocates the dynamically allocated memory
Board::~Board() {
    for (int i = 0; i < rows; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

// Check if the coordinates are within bounds
bool Board::inBounds(int r, int c) const {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

// Place a player's mark on the board if the position is valid and empty
bool Board::place(int r, int c, char mark) {
    if (!inBounds(r, c)) return false;        // Check if coordinates are within bounds
    if (grid[r][c] != ' ') return false;      // Check if the cell is already occupied
    grid[r][c] = mark;                       // Place the mark
    return true;                             // Successful placement
}

// Check if the board is full (tie case)
bool Board::full() const {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (grid[i][j] == ' ') return false; // Return false if any cell is empty
    return true; // Return true if no empty cells
}

// Return the mark at a given position
char Board::at(int r, int c) const {
    if (!inBounds(r, c)) return ' ';  // If out of bounds, return empty character
    return grid[r][c];                // Return the mark ('O', 'X', or ' ')
}

// Print the board in a human-readable format with borders (only using '-')
void Board::print() const {
    // Print the top border using only dashes
    cout << "   ";
    for (int c = 1; c <= cols; ++c) {
        cout << "----";  // Draw the top horizontal border (4 dashes per column)
    }
    cout << endl;

    // Print each row of the board
    for (int r = 0; r < rows; ++r) {
        // Print the left border for the row
        cout << std::setw(2) << (r + 1) << " |";  // Row number and vertical divider

        // Print each column in the row with a space between the cells
        for (int c = 0; c < cols; ++c) {
            cout << " " << grid[r][c] << " |";  // Each cell with vertical dividers
        }
        cout << endl;

        // Print the row separator using only dashes
        cout << "   ";
        for (int c = 1; c <= cols; ++c) {
            cout << "----";  // Draw the horizontal separator for each row (4 dashes per column)
        }
        cout << endl;
    }
}

// Check if the player has won by placing k consecutive marks (horizontal, vertical, and diagonals)
bool Board::checkWin(int k, char mark) const {
    // Check horizontal lines for a win
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c <= cols - k; ++c) {
            bool win = true;
            for (int i = 0; i < k; ++i) {
                if (grid[r][c + i] != mark) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check vertical lines for a win
    for (int c = 0; c < cols; ++c) {
        for (int r = 0; r <= rows - k; ++r) {
            bool win = true;
            for (int i = 0; i < k; ++i) {
                if (grid[r + i][c] != mark) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check diagonal (↘) lines for a win
    for (int r = 0; r <= rows - k; ++r) {
        for (int c = 0; c <= cols - k; ++c) {
            bool win = true;
            for (int i = 0; i < k; ++i) {
                if (grid[r + i][c + i] != mark) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check diagonal (↗) lines for a win
    for (int r = k - 1; r < rows; ++r) {
        for (int c = 0; c <= cols - k; ++c) {
            bool win = true;
            for (int i = 0; i < k; ++i) {
                if (grid[r - i][c + i] != mark) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    return false;
}

// Getter for rows
int Board::getRows() const {
    return rows;
}

// Getter for columns
int Board::getCols() const {
    return cols;
}
