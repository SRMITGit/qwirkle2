//
//  GameEngine.cpp
//  Qwirkle
//
//  Created by Philip Beeby on 18/7/21.
//

#include "GameEngine.h"
#include <iostream>
#include <string>
#include "board.h"

void addTilesToPlayerHand(int numTiles, Player player, Bag *gameBag);

GameEngine::GameEngine(Player player1, Player player2) {
  std::cout << "Creating a new GameEngine Object: " << std::endl;
  std::cout << "Using existing Player Object: " << std::endl;
  // this->player1 = player1.;
  // this->player2 = new Player(player_2_name);
  std::cout << "Creating a game bag: " << std::endl;
  this->gameTileBag = new Bag();
  std::cout << "Adding Tiles to the game bag: " << std::endl;
  // Bag * newBag = new Bag();
  gameTileBag->addTilesToBag(gameTileBag);
  // add tiles to player bags
  // add tiles to each players hand at the start of the game
  addTilesToPlayerHand(6, player1, gameTileBag);
  addTilesToPlayerHand(6, player2, gameTileBag);
  // generate a new board
    Board *board = new Board(26, &std::cout);
    // board->display();
    // int *iPtr = &i; 
    // Tile *tilePtr = &player1.getPlayerHand()->get(0);
    
    // Tile *playerTile = new Tile(player1.getPlayerHand()->get(0));
    // std::cout << "The size of the board  before adding tile is : " << board->getSize() << std::endl;
    // board->setTile(0, 0, playerTile);
    // std::cout << "The size of the board after adding tile is : " << board->getSize() << std::endl;
    
    // board->display();
    // board->toString();
    // Tile *boardTile = new Tile(board->getTile(0,0));
    // Tile *boardTile = board->getTile(0,0);
    // std::cout << "Tile Colour" << boardTile->getTileColour() << std::endl;
    // std::cout << "Tile Shape" << boardTile->getTileShape() << std::endl;
    board->displayBoard();

    // bool player1TurnOver = false;
    // bool player2TurnOver = false;

    // allow player to select a tile from the bag and place it on the board

    int i = 0;

    while (i < 36)
    {
      // show player 1 hand
      std::cout << player1.getPlayerName() << " ";    
      player1.printPlayerHand();

      // ask player which tile they want to select from their hand
      int tileNumber =0;
      int rowNumber = 0;
      int colNumber = 0;
      std::cout << "please select a tile from your hand " << std::endl;  
      // ask player where they want to place the tile on the board
      std::cin >> tileNumber;
      Tile *playerTile = new Tile(player1.getPlayerHand()->get(tileNumber));
      std::cout << "please Enter Board Co-Ordinates for the tile Row and then Column" << std::endl; 
      std::cin >> rowNumber;
      std::cin >> colNumber;
      std::cout << "Tile will be placed on board at ROW:" << rowNumber << " COL: " <<colNumber << std::endl;
      board->setTile(rowNumber, colNumber, playerTile);
      board->displayBoard();

          // show player 1 hand
      std::cout << player2.getPlayerName() << " ";    
      player2.printPlayerHand();

      // ask player which tile they want to select from their hand
      tileNumber =0;
      rowNumber = 0;
      colNumber = 0;
      std::cout << "please select a tile from your hand " << std::endl;  
      // ask player where they want to place the tile on the board
      std::cin >> tileNumber;
      Tile *playerTile2 = new Tile(player2.getPlayerHand()->get(tileNumber));
      std::cout << "please Enter Board Co-Ordinates for the tile Row and then Column" << std::endl; 
      std::cin >> rowNumber;
      std::cin >> colNumber;
      std::cout << "Tile will be placed on board at ROW:" << rowNumber << " COL: " <<colNumber << std::endl;
      board->setTile(rowNumber, colNumber, playerTile2);
      board->displayBoard();
      i++;
    }


}

GameEngine::GameEngine(std::string player_1_name, std::string player_2_name) {
  // constructor
  std::cout << "Creating a new GameEngine Object: " << std::endl;
  std::cout << "Creating a new Player Object: " << std::endl;
  this->player1 = new Player(player_1_name);
  this->player2 = new Player(player_2_name);
  std::cout << "Creating a game bag: " << std::endl;
  this->gameTileBag = new Bag();
  std::cout << "Adding Tiles to the game bag: " << std::endl;
  // Bag * newBag = new Bag();
  gameTileBag->addTilesToBag(gameTileBag);
  // add tiles to player bags
}

//Created by Guy - to add contents of saved to to game bag
void GameEngine::gameBagFromFile(std::string player_1_name, std::string player_2_name)
{
  this->player1 = new Player(player_1_name);
  this->player2 = new Player(player_2_name);
  std::cout << "Creating a game bag: " << std::endl;
  this->gameTileBag = new Bag();
  std::cout << "Adding Tiles to the game bag: " << std::endl;
  // Bag * newBag = new Bag();
  gameTileBag->loadGameTileBag(gameTileBag);
  // add tiles to player bags
}

GameEngine::~GameEngine() {
  // destructor
  std::cout << "Deleting GameEngine Object and Attributes: " << std::endl;
  // delete player1;
  // delete player2;
  delete gameTileBag;
}

void addTilesToPlayerHand(int numTiles, Player player, Bag *gameBag) {

  // int numStartingTiles = 6;
  int loopCounter = 0;
  if (gameBag->listSize() != 0) {
    // check size of bag
    while (loopCounter < numTiles) {
      Tile *newFrontBagTile = new Tile(gameBag->get(0));
      player.getPlayerHand()->addBack(newFrontBagTile);
      std::cout << "Adding Tile to Players Hand: "
                << newFrontBagTile->getTileColour()
                << newFrontBagTile->getTileShape() << std::endl;
      // remove the tile from the front of the bag
      gameBag->removeFront();

      ++loopCounter;
    }
    std::cout << "Finished Adding Tiles to Player's Hand: "
              << player.getPlayerName() << std::endl;
    std::cout << "Player: " << player.getPlayerName()
              << " Hand now looks like this: " << std::endl;
    player.getPlayerHand()->printNodes();

  } else {
    std::cout << "The Bag is Empty cannot add tiles to plater hands: "
              << std::endl;
  }
}
// void GameEngine::setName(std::string name){
//     // update the GameEngine name (prolly won't need this)
//     *(this->name) = name;

// }
// void GameEngine::setGameEngineID(std::string GameEngineID){
//     // update the GameEngineID (prolly won't need this)
//     *(this->GameEngineID) = GameEngineID;

// }
// void GameEngine::setEmail(std::string email){
//     // update the GameEngine email (prolly won't need this)
//     *(this->email) = email;

// }
// std::string GameEngine::getName(){
//     return *name;

// }
// std::string GameEngine::getGameEngineID(){
//     return *GameEngineID;

// }
// std::string GameEngine::getEmail(){
//     return *email;

// }

// void GameEngine::printGameEngineDetails(){
//     // print out all of the attributes of a GameEngine
//     std::cout << "Name: " << getName() << std::endl;
//     std::cout << "GameEngine ID: " << getGameEngineID() << std::endl;
//     std::cout << "Email: " << getEmail() << std::endl;

// }