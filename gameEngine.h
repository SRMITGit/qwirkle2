//
//  GameEngine.h
//  Qwirkle
//
//  Created by Philip Beeby on 18/7/21.
//

#ifndef ASSIGN2_GAMEENGINE_H
#define ASSIGN2_GAMEENGINE_H

#include "bag.h"
#include "player.h"
#include <stdio.h>
#include <string>
#include <iostream>

class GameEngine {
public:
  // default constructor
  GameEngine();
  // constructor
  GameEngine(std::string player_1_name, std::string player_2_name);
  // GameEngine(std::string player_1_name, std::string player_2_name, std::string player_3_name);
  // GameEngine(std::string player_1_name, std::string player_2_name, std::string player_3_name, std::string player_4_name);
  // destructor, std::string player_4_name
  GameEngine(Player player1, Player player2);
  // GameEngine(Player player1, Player player2, Player player3);
  // GameEngine(Player player1, Player player2, Player player3, Player player4);
  // destructor
  ~GameEngine();
  // copy constructor
  GameEngine(GameEngine &other);

  void gameBagFromFile(std::string player_1_name, std::string player_2_name);
  // void gameBagFromFile(std::string player_1_name, std::string player_2_name, std::string player_3_name);
  // void gameBagFromFile(std::string player_1_name, std::string player_2_name, std::string player_3_name, std::string player_4_name);
  void addTilesToPlayerHand(int numTiles, Player player, Bag *gameBag);

private:
  // these have to be pointers so we can create class attributes on the heap
  /* Player *player1;
  Player *player2;
  Player *player3;
  Player *player4; */
  Player *player1, *player2, *player3, *player4;
  Bag *gameTileBag;
};

#endif /* ASSIGN2_GAMEENGINE_H */