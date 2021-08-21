#include "newGame.h"
#include "board.h"
#include "gameEngine.h"

newGame::newGame() {}
newGame::~newGame() {}

Player p1("");
Player p2("");
// Player p3("");
// Player p4("");

void newGame::addPlayers() {
  std::string player1;
  std::string player2;
  // std::string player3;
  // std::string player4;
  std::string name;
  std::vector<std::string> gameList;
  gameList.emplace_back("Starting a New Game");
  gameList.emplace_back("Enter a name for player 1");
  gameList.emplace_back("Enter a name for player 2");
  // gameList.emplace_back("Enter a name for player 3");
  // gameList.emplace_back("Enter a name for player 4");

  // Print Strings stored in Vector
  std::cout << " " << std::endl;
  std::cout << gameList[1] << std::endl;
  // When using std::getLine, we need to use std::ws to ensure the leading
  // whitespace is removed from an input stream.
  if (std::getline(std::cin >> std::ws, player1)) {
    for (int i = 0; i < (int)player1.size(); ++i) {
      player1[i] = toupper(player1[i]);
    }
  }
  std::cout << " " << std::endl;
  std::cout << gameList[2] << std::endl;
  if (std::getline(std::cin >> std::ws, player2)) {
    for (int i = 0; i < (int)player2.size(); ++i) {
      player2[i] = toupper(player2[i]);
    }
  }
  // std::cout << " " << std::endl;
  // std::cout << gameList[3] << std::endl;
  // if (std::getline(std::cin >> std::ws, player3)) {
  //   for (int i = 0; i < (int)player3.size(); ++i) {
  //     player3[i] = toupper(player3[i]);
  //   }
  // }
  // std::cout << " " << std::endl;
  // std::cout << gameList[4] << std::endl;
  // if (std::getline(std::cin >> std::ws, player4)) {
  //   for (int i = 0; i < (int)player4.size(); ++i) {
  //     player4[i] = toupper(player4[i]);
  //   }
  // }
  playerNames[0] = player1;
  playerNames[1] = player2;
  // playerNames[2] = player3;
  // playerNames[3] = player4;

  currentPlayer = playerNames[0];
  play = 0;
}

std::string newGame::getCurrentPlayer() { return currentPlayer; }
// call function switch player two switch between current player
void newGame::switchPlayer() {
  if (play == 0) {
    std::cout << "if";
    play = 1;
  } else {
    std::cout << "else";
    play = 0;
  }
  currentPlayer = playerNames[play];
}

void newGame::startGameMsg() {
  std::cout << "Lets Play!" << std::endl << std::endl;
}

void newGame::gamePlay() {
  // adding new linked list for player hands
  LinkedList *p1Hand = new LinkedList();
  LinkedList *p2Hand = new LinkedList();
  // LinkedList *p3Hand = new LinkedList();
  // LinkedList *p4Hand = new LinkedList();
  Player p1(playerNames[0], p1Hand); // create new player with a hand
  Player p2(playerNames[1], p2Hand); // create a new player with a hand
  // Player p3(playerNames[2], p3Hand);
  // Player p4(playerNames[3], p4Hand);
  // setting sores to 0
  p1.setPlayerScore(0);
  p2.setPlayerScore(0);
  // p3.setPlayerScore(0);
  // p4.setPlayerScore(0);

  std::cout << currentPlayer << ", it's your turn" << std::endl;
  std::cout << "Score for " << playerNames[0] << ":" << p1.getPlayerScore()
            << std::endl; // input score here
  std::cout << "Score for " << playerNames[1] << ":" << p2.getPlayerScore()
            << std::endl; // input score here
  // std::cout << "Score for " << playerNames[2] << ":" << p3.getPlayerScore()
  //           << std::endl;
  // std::cout << "Score for " << playerNames[3] << ":" << p4.getPlayerScore()
  //           << std::endl;

  // From Phil
  // GameEngine =

  GameEngine *newGameEngine = new GameEngine(p1, p2); // , p3, p4
  delete newGameEngine;
  // can call GameEngine here
  // fetch board here
  // Check to see who current player is and display current player hand
  try {
    if (playerNames[0] == getCurrentPlayer()) {
      std::cout << getCurrentPlayer() << "s hand: " << p1.getPlayerHand()
                << std::endl;
    } else if (playerNames[1] == getCurrentPlayer()) {
      std::cout << getCurrentPlayer() << "s hand: " << p2.getPlayerHand()
                << std::endl;
      // } else if (playerNames[2] == getCurrentPlayer()) {
      //   std::cout << getCurrentPlayer() << "s hand: " << p3.getPlayerHand()
      //             << std::endl;
      // } else if (playerNames[3] == getCurrentPlayer()) {
      //   std::cout << getCurrentPlayer() << "s hand: " << p4.getPlayerHand()
      //             << std::endl;
    }
  } catch (const std::runtime_error &e) {
    std::cerr << "We have a problem with names!! \n" << e.what() << "\n";
  }
}

void newGame::runGame() {
  addPlayers();
  startGameMsg();
  // loop and check if game should continue
  gamePlay();
  // update game stats

  // saveGame();
}

void newGame::saveGame() {
  std::string save = ".save";

  std::string fileName = "";
  std::cout << "Enter name you wish to give to save game file" << std::endl;
  std::cout << ">";
  std::cin >> fileName;
  fileName = "Saved Games/" + fileName;

  // check if file name has a .save at the back, if none add it
  if (fileName.find(save) != std::string::npos) {
  } else {
    fileName = fileName + save;
  }
  // open new file
  std::ofstream MyWriteFile(fileName);
  // write to file
  MyWriteFile << playerNames[0] << "\n";
  MyWriteFile << p1.getPlayerScore() << "\n";
  MyWriteFile << p1.getPlayerHand() << "\n";
  MyWriteFile << "Player 1 Game Bag"
              << "\n";
  MyWriteFile << p1.getGameTileBag() << "\n";

  MyWriteFile << playerNames[1] << "\n";
  MyWriteFile << p2.getPlayerScore() << "\n";
  MyWriteFile << p2.getPlayerHand() << "\n";
  MyWriteFile << "Player 2 Game Bag"
              << "\n";
  MyWriteFile << p2.getGameTileBag() << "\n";
  MyWriteFile << getCurrentPlayer() << "\n";
  // close file
  MyWriteFile.close();

  std::cout << "Game Successfully Saved" << std::endl;
}
