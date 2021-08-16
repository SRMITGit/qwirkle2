#ifndef Board_h
#define Board_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Tile.h"

#define MAX_BOARD_SIZE 26;

class Board
{
public:
    std::vector<std::vector<Tile *>> board;

    Board(int size, std::ostream *outputStream);

    ~Board();

    // Board();

    void display();

    void displayBoard();

    int getSize();

    Tile *getTile(int row, int col);

    void setTile(int row, int col, Tile *tile);

    std::string toString();

    void reSize();

    std::ostream *outputStream = &std::cout;
};
#endif /* Board_h */