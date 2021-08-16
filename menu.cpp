#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "GameEngine.h"
#include "credits.h"
#include "loadGame.h"
#include "menu.h"
#include "newGame.h"

int length = 0;

Menu::Menu() {}
Menu::~Menu() { clear(); }
Credits::Credits() {}

// Returns the current size of the Menu
int Menu::size() { return length; }

// Removes all menu items from the Menu
void Menu::clear() {
  for (int i = 0; i != length; ++i) {
    delete menuList[i];
    menuList[i] = nullptr;
  }
}

// Quits the entire program
void Menu::quit() {
  std::string quit = "Goodbye!";
  std::cout << quit << std::endl;
  exit(1);
}

int Menu::mainMenu() {
  // Reference:
  // https://stackoverflow.com/questions/60616203/how-can-i-make-a-function-that-prints-out-a-menu
  // Declaring Vector of String type
  // Strings can be added at any time with emplace_back
  std::vector<std::string> menuList;
  menuList.reserve(4);
  menuList.emplace_back(std::move("1. New Game"));
  menuList.emplace_back(std::move("2. Load Game"));
  menuList.emplace_back(std::move("3. Credits"));
  menuList.emplace_back(std::move("4. Quit"));

  // Print Strings stored in Vector
  std::cout << "Menu" << std::endl;
  std::cout << "----" << std::endl;
  for (std::string &value : menuList) {
    std::cout << value << std::endl;
  }
  std::cout << SIGN << SPACE;

  int selected = 0;
  std::string input;
  std::cin >> input;
  if (std::stringstream(input) >> selected) {
    return selected;
  } else {
    return EXIT_SUCCESS;
  }
};

void Menu::selectionMenu() {
  Credits printCredits;
  newGame runGame;
  loadGame loadGame;
  int selected = -1;

  while ((selected = Menu::mainMenu()) <= 4 && !std::cin.eof()) {
    if (selected == 1) {
      std::cout << "Starting a New Game" << std::endl;
      std::cout << "-------------------" << std::endl;
      runGame.runGame();
    } else if (selected == 2) {
      loadGame.readFile();
    } else if (selected == 3) {
      std::cout << "The Team!" << std::endl;
      std::cout << printCredits.printCredits() << std::endl;
    } else if (selected == 4) {
      std::cout << " " << std::endl;
      Menu::quit();
    } else {
      std::cout << " " << std::endl;
      std::cout << "Invalid Input" << std::endl;
    }
  }
};