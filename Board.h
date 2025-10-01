#pragma once
#include <iostream>
#include <vector>

class Board {
private:
    int rows, cols;  // Number of rows and columns in the board
    char** grid;     // 2D array to store the game grid (char type for marks 'O', 'X', and ' ')

public:
    // Constructor: Initializes the board with the given number of rows and columns
    Board(int r, int c);

    // Destructor: Deallocates dynamically allocated memory for the grid
    ~Board();

    // Method to print the board in a human-readable format
    void print() const;

    // Method to check if the given coordinates are within the board's bounds
    bool inBounds(int r, int c) const;

    // Method to place a player's mark on the board at the specified position
    bool place(int r, int c, char mark);

    // Method to check if the board is full (i.e., no empty cells left)
    bool full() const;

    // Method to return the character at a specific position on the board
    char at(int r, int c) const;

    // Method to check if a player has won by placing k consecutive marks
    bool checkWin(int k, char mark) const;

    // Getter for rows
    int getRows() const;

    // Getter for columns
    int getCols() const;
};
