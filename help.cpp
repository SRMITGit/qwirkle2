// #include "newGame.h"
#include "help.h"
// #include "Player.h"
// #include "GameEngine.h"
#include <fstream>
#include <iostream>
#include <string>
// #include <vector>

// Help::Help() {}
// Help::~Help() {}


int Help::displayHelp() {
//  int Credits::printCredits() {
  std::string help;
  std::ifstream file("help.md");
  if (file.is_open()) {
    while (std::getline(file, help) && !file.eof()) {
      std::cout << help << std::endl;
    }
    file.close();
  } else
    std::cout << "Cannot open file!" << std::endl;
  return EXIT_SUCCESS;
};

