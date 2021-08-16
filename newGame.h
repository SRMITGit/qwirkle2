#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class newGame {
public:
  newGame();
  void addPlayers();
  std::string getCurrentPlayer();
  void switchPlayer();
  void startGameMsg();
  void runGame();
  void gamePlay();
  void saveGame();

  ~newGame();

private:
  std::string currentPlayer;
  std::string playerNames[2];
  int play;
};
