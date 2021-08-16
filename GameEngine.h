//
//  GameEngine.h
//  Qwirkle
//
//  Created by Philip Beeby on 18/7/21.
//

#ifndef GameEngine_h
#define GameEngine_h

#include <stdio.h>
#include <string>
#include "Player.h"
#include "Bag.h"

class GameEngine
{
public:
    //default constructor
    GameEngine();
    //constructor
    GameEngine(std::string player_1_name, std::string player_2_name);
    //destructor
    GameEngine(Player player1, Player player2);
    //destructor
    ~GameEngine();
    //copy constructor
    GameEngine(GameEngine& other);
    // setters
    // void setName(std::string name);
 
    // // getters
    // std::string getName();
    // std::string getGameEngineID();
    // std::string getEmail();
    // //other
    // void addTilesToPlayerHand(unsigned int numTiles, Player player, Bag * gameGame);
    void gameBagFromFile(std::string player_1_name, std::string player_2_name);

private:
    // these have to be pointers so we can create class attributes on the heap
    Player* player1;
    Player* player2;
    Bag * gameTileBag; 
};

#endif /* GameEngine_h */