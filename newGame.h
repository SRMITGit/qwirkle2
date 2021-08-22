#ifndef ASSIGN2_NEWGAME_H
#define ASSIGN2_NEWGAME_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "player.h"

#define MAX_NUM_PLAYERS 4

class newGame {
public:
  newGame();
  ~newGame();

  std::string getCurrentPlayer();

  void addPlayers();
  void switchPlayer();
  void startGameMsg();
  void runGame();
  void gamePlay();
  void saveGame();

private:
  std::string currentPlayer;
  std::string playerNames[MAX_NUM_PLAYERS];
  int play;
};

#endif // ASSIGN2_NEWGAME_H