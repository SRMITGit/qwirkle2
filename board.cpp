#include "board.h"
#include "Tile.h"
#include <iostream>
// #include <ostream>
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

Board::~Board() {
  // destructor
  std::cout
      << "Calling Board Destructor - Deleting Board Object and Attributes: "
      << std::endl;
}

// expanding the board
void Board::reSize() {
  int bsize = getSize();
  if (bsize < 26) {
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

// printing the grid to the display
void Board::display() {
  int n = (int)board.size();
  *outputStream << "   ";

  for (int k = 0; k < n; k++)
    if (k < 10) {
      *outputStream << k << "  ";
    } else
      *outputStream << k << " ";
  *outputStream << "\n  ";
  for (int t = 0; t < n; t++)
    *outputStream << "---";
  *outputStream << std::endl;

  // loops to print the vector of vectors
  for (int i = 0; i < n; i++) {
    *outputStream << (char)('A' + i) << " |";
    for (int j = 0; j < n; j++) {
      if (board[i][j] != nullptr) {
        // std::cout << "First if Statement: " << std::endl;
        if (this->outputStream != &std::cout) {

          *outputStream << this->getTile(i, j)->getTileColour()
                        << this->getTile(i, j)->getTileShape();
          // std::cout << "Second if Statement: " << std::endl;
        }
        // printTile ins't doing anything yet
        /* else
        {
            this->getTile(i, j)->printTile();
        } */
        *outputStream << "|";
      } else
        *outputStream << "  |";
      // std::cout << "First ELSE Statement: " << std::endl;
    }
    *outputStream << std::endl;
  }
}

// void Board::displayBoard() {
//   int outLoopCounter = 0;
//   int innLoopCounter = 0;

//   while (outLoopCounter < board.size()) {

//     if (board[outLoopCounter][innLoopCounter] == nullptr) {
//       std::cout << "|A|";
//       outLoopCounter +=1;

//     } else {
//       std::cout << "|" << board[outLoopCounter][innLoopCounter] << "|";
//       outLoopCounter +=1;
//     }

//     while (innLoopCounter < board.size()) {

//       if (board[outLoopCounter][innLoopCounter] == nullptr) {
//         //  std::cout << "Printing OuterLoop: " <<
//         //  board[outLoopCounter][innLoopCounter] << std::endl;
//         std::cout << "|B|";
//         innLoopCounter +=1;
   

//       } else {
//         std::cout << "| " << board[outLoopCounter][innLoopCounter] << " |";
//         innLoopCounter +=1;
//       }

      
//         // std::cout << std::endl;


//     }

//       outLoopCounter +=1;
//     // std::cout << std::endl;
//     // std::cout << "Counter Outside" << outLoopCounter << std::endl;
//     // std::cout << "Counter Inside" << innLoopCounter << std::endl;
//   }
//     std::cout << "Counter Outside" << outLoopCounter << std::endl;
//     std::cout << "Counter Inside" << innLoopCounter << std::endl;
//     std::cout << std::endl;

// }

void Board::displayBoard()
{
    // Helper function takes an Env type (2D Char Array) and prints it out to the console
    // rows first then columns

    std::cout << "Printing Updated Board " << std::endl;
    int row_counter = 0;
    int head_row_counter = 1;
    // print out the header row
    std::cout << " ";
    while(head_row_counter < (int)board.size()){
      if (head_row_counter < 11){
            std::cout  << " |" << head_row_counter;
            head_row_counter = head_row_counter + 1;
      }
      else{
            std::cout  << "|" << head_row_counter;
            head_row_counter = head_row_counter + 1;

      }
 
    }
    std::cout << std::endl;
    char row_char = 'A';

    while (row_counter < (int)board.size())
    {
        // reset colum counter before each run
        int col_counter = 0;
        std::cout << row_char << " ";
        row_char = row_char +1;

        while (col_counter < (int)board.size())
        {   
            if (board[row_counter][col_counter] == nullptr){

           
            std::cout << "|  ";
            col_counter = col_counter + 1;
            }
            
            else{
            std::cout << "|" << board[row_counter][col_counter]->getTileColour() << board[row_counter][col_counter]->getTileShape() ;
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
int Board::getSize() { 
  
  return board.size(); }

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
    std::cout << "Calling Set Tile Method: " << tile->getTileColour()
              << tile->getTileShape() << std::endl;
    // tile->getTileColour;
  }
}
