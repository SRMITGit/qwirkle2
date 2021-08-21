// s3831786 Gordon Richard - RMIT

#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "linkedList.h"
#include <string>
#include <ostream>

#define MAX_TILES_IN_HAND 6

class Player {
public:
  std::string name;
  int score;
  int length = 0;
  LinkedList *hand;

  Player(std::string name);
  Player(std::string name, LinkedList *hand);
  ~Player();

  int size();

  // to return name stored in string type
  std::string getPlayerName();
  // to return memory address of string name
  std::string *getPlayerNamePtr();
  bool setName(std::string &playerName);

  void setPlayerScore(int score);
  void addPlayerScore(int score);

  void setPlayerHand(LinkedList *hand);
  void printPlayerHand();

  LinkedList *getPlayerHand();

  // to return player score stored in int type
  int getPlayerScore();

  // to return memory address of player score
  int *getPlayerScorePtr();
};

#endif // ASSIGN2_PLAYER_H