#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_BOARD_SIZE 26

class Board {
public:
  std::vector<std::vector<Tile *>> board;

  Board();
  Board(int size, std::ostream *outputStream);
  ~Board();

  void display();
  void displayBoard();

  int getSize();
  int getDisplayBoard();

  void setTile(int row, int col, Tile *tile);
  void reSize();

  std::string toString();
  std::ostream *outputStream = &std::cout;

  Tile *getTile(int row, int col);
};
#endif // BOARD_H