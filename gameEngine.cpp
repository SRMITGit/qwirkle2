//
//  GameEngine.cpp
//  Qwirkle
//
//  Created by Philip Beeby on 18/7/21.
//

#include "gameEngine.h"
#include "bag.h"
#include "board.h"
#include "menu.h"
#include "player.h"
#include "tile.h"
#include "userPrompt.h"

GameEngine::GameEngine(Player player1, Player player2) {
  UserPrompt userPrompt;
  this->gameTileBag = new Bag();
  gameTileBag->addTilesToBag(gameTileBag);
  // add tiles to player bags
  // add tiles to each players hand at the start of the game
  // added MAX_TILES_IN_HAND
  addTilesToPlayerHand(MAX_TILES_IN_HAND, player1, gameTileBag);
  addTilesToPlayerHand(MAX_TILES_IN_HAND, player2, gameTileBag);
  // generate a new board
  Board *board = new Board(MAX_BOARD_SIZE, &std::cout);
  board->displayBoard();

  // allow player to select a tile from the bag and place it on the board
  int i = 0;
  while (i < (MAX_BAG_TILES / 2)) {
    // show player 1 hand
    std::cout << player1.getPlayerName() << " ";
    player1.printPlayerHand();

    // ask player which tile they want to select from their hand
    int tileNumber = 0, rowNumber = 0, colNumber = 0;
    std::cout << "Please select a tile from your hand \n> ";
    // ask player where they want to place the tile on the board
    std::cin >> tileNumber;
    Tile *playerTile = new Tile(player1.getPlayerHand()->get(tileNumber));
    std::cout << "Please enter board co-ordinates for the tile" << GREEN_TEXT
              << " ROW" << RESET_COLOUR << " and then " << YELLOW_TEXT
              << "COLUMN " << RESET_COLOUR << "\n>";
    std::cin >> rowNumber;
    std::cin >> colNumber;
    std::cout << "Tile will be placed on board at " << GREEN_TEXT << "ROW "
              << RESET_COLOUR << rowNumber << YELLOW_TEXT << " COLUMN "
              << RESET_COLOUR << colNumber << std::endl;
    board->setTile(rowNumber, colNumber, playerTile);
    board->displayBoard();

    // show player 2 hand
    std::cout << player2.getPlayerName() << " ";
    player2.printPlayerHand();

    // ask player which tile they want to select from their hand
    std::cout << "Please select a tile from your hand \n> ";
    // ask player where they want to place the tile on the board
    std::cin >> tileNumber;
    Tile *playerTile2 = new Tile(player2.getPlayerHand()->get(tileNumber));
    std::cout << "Please enter board co-ordinates for the tile" << GREEN_TEXT
              << " ROW" << RESET_COLOUR << " and then " << YELLOW_TEXT
              << "COLUMN " << RESET_COLOUR << "\n>";
    std::cin >> rowNumber;
    std::cin >> colNumber;
    std::cout << "Tile will be placed on board at " << GREEN_TEXT << "ROW "
              << RESET_COLOUR << rowNumber << YELLOW_TEXT << " COLUMN "
              << RESET_COLOUR << colNumber << std::endl;
    board->setTile(rowNumber, colNumber, playerTile2);
    board->displayBoard();
    // Comment this line in to show saving a game
    // userPrompt.textPrompt();
    --i;
  }
}

// Created by Guy - to add contents of saved to to game bag
void GameEngine::gameBagFromFile(std::string player_1_name,
                                 std::string player_2_name) {
  this->player1 = new Player(player_1_name);
  this->player2 = new Player(player_2_name);
  this->gameTileBag = new Bag();
  gameTileBag->loadGameTileBag(gameTileBag);
}

GameEngine::~GameEngine() { delete gameTileBag; }

void GameEngine::addTilesToPlayerHand(int numTiles, Player player,
                                      Bag *gameBag) {
  int loopCounter = 0;
  try {
    if (gameBag->listSize() != 0) {
      // check size of bag
      while (loopCounter < numTiles) {
        Tile *newFrontBagTile = new Tile(gameBag->get(0));
        player.getPlayerHand()->addBack(newFrontBagTile);
        /* std::cout << "Adding Tile to Players Hand: "
                  << newFrontBagTile->getTileColour()
                  << newFrontBagTile->getTileShape() << std::endl; */
        /* std::printf("Adding Tile to Players Hand: %d %d",
                    newFrontBagTile->getTileColour(),
                    newFrontBagTile->getTileShape()); */
        // remove the tile from the front of the bag
        gameBag->removeFront();
        ++loopCounter;
      }
      player.getPlayerHand()->printNodes();
    }
  } catch (const std::runtime_error &e) {
    std::cerr << "The Bag is Empty - it's the last round! \n"
              << e.what() << "\n";
  }
}