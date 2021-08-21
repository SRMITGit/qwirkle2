#include "board.h"
#include "tile.h"

// creates grid and initialises with nullpointers.

Board::Board(int size, std::ostream *outputStream) {
  this->outputStream = outputStream;
  for (int i = 0; i < size; i++) {
    std::vector<Tile *> row;
    for (int j = 0; j < size; j++) {
      row.push_back(nullptr);
    }
    board.push_back(row);
  }
}

Board::~Board() {}

// expanding the board
void Board::reSize() {
  int bsize = getSize();
  // changes to MAX_BOARD_SIZE
  if (bsize < MAX_BOARD_SIZE) {
    for (int i = 0; i < getSize(); i++) {
      board[i].push_back(nullptr);
    }
    std::vector<Tile *> row;
    for (int j = 0; j <= getSize(); j++) {
      row.push_back(nullptr);
    }
    board.push_back(row);
  }
}

void Board::displayBoard() {
  // Helper function takes an Env type (2D Char Array) and prints it out to the
  // console rows first then columns

  std::cout << "Printing Updated Board " << std::endl;
  int row_counter = 0;
  int head_row_counter = 1;
  // print out the header row
  std::cout << " ";
  while (head_row_counter < (int)board.size()) {
    if (head_row_counter < 11) {
      std::cout << " |" << head_row_counter;
      head_row_counter = head_row_counter + 1;
    } else {
      std::cout << "|" << head_row_counter;
      head_row_counter = head_row_counter + 1;
    }
  }
  std::cout << std::endl;
  char row_char = 'A';

  while (row_counter < (int)board.size()) {
    // reset colum counter before each run
    int col_counter = 0;
    std::cout << row_char << " ";
    row_char = row_char + 1;

    while (col_counter < (int)board.size()) {
      if (board[row_counter][col_counter] == nullptr) {

        std::cout << "|  ";
        col_counter = col_counter + 1;
      } else {
        std::cout << "|" << board[row_counter][col_counter]->getTileColour()
                  << board[row_counter][col_counter]->getTileShape();
        col_counter = col_counter + 1;
      }
    }
    // add a carriage return after printing out the row
    std::cout << std::endl;
    row_counter = row_counter + 1;
  }
}

std::string Board::toString() {
  std::string output = "";
  int n = (int)board.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] != nullptr) {
        std::string colour(1, this->getTile(i, j)->getTileColour());
        output.append(colour);
        output.append(std::to_string(this->getTile(i, j)->getTileShape()));
        output.append("|");
      } else {
        output.append("  |");
      }
    }
    output.append("\n");
  }
  return output;
}

int Board::getSize() { return board.size(); }

Tile *Board::getTile(int row, int col) {
  Tile *tile = nullptr;
  if (row < getSize() && col < getSize()) {
    tile = board[row][col];
  }
  return tile;
}
void Board::setTile(int row, int col, Tile *tile) {
  if (row < getSize() && col < getSize()) {
    board[row][col] = tile;
  }
}
