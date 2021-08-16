#include "newGame.h"
// #include "Player.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "GameEngine.h"

newGame::newGame() {}
newGame::~newGame() {}

Player p1("");
Player p2("");

void newGame::addPlayers() {
  std::string player1;
  std::string player2;
  std::vector<std::string> gameList;
  gameList.emplace_back("Starting a New Game");
  gameList.emplace_back("Enter a name for player 1");
  gameList.emplace_back("Enter a name for player 2");

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
  playerNames[0] = player1;
  playerNames[1] = player2;

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
  // assigning player names to p1 and p2
  Player p1(playerNames[0]);
  Player p2(playerNames[1]);
  // seeting sores to 0 for p1 and p2
  p1.setPlayerScore(0);
  p2.setPlayerScore(0);

  std::cout << currentPlayer << ", it's your turn" << std::endl;
  std::cout << "Score for " << playerNames[0] << ":" << p1.getPlayerScore()
            << std::endl; // input score here
  std::cout << "Score for " << playerNames[1] << ":" << p2.getPlayerScore()
            << std::endl; // input score here

  // From Phil 
  // GameEngine = 

  GameEngine * newGameEngine = new GameEngine(p1, p2);
  delete newGameEngine;
  // can call GameEngine here 


  // fetch board here
  // display current player hand here
}

void newGame::runGame() {
  addPlayers();
  startGameMsg();
  // loop and check if game should continue
  gamePlay();
  // update game stats

  saveGame();
}

void newGame::saveGame() {

  std::string fileName = "";
  std::cout << "Enter name you wish to give to save game file" << std::endl;
  std::cout << ">";
  std::cin >> fileName;

  std::ofstream MyWriteFile(fileName);
  MyWriteFile << playerNames[0] << "\n";
  MyWriteFile << p1.getPlayerScore() << "\n";
  MyWriteFile << "Player 1 Hand goes here"
              << "\n";
  MyWriteFile << playerNames[1] << "\n";
  MyWriteFile << p2.getPlayerScore() << "\n";
  MyWriteFile << "Player 2 hand goes here"
              << "\n";
  MyWriteFile << "current board state goes here"
              << "\n";
  MyWriteFile << "Tile bag content goes here"
              << "\n";
  MyWriteFile << getCurrentPlayer() << "\n";
  MyWriteFile.close();
}
