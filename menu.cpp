// Sources to make Terminal Colours
// https://stackoverflow.com/questions/9158150/colored-output-in-c
// https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
// https://www.codegrepper.com/code-examples/actionscript/ansi+colors+orange
// https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/
// https://www.geeksforgeeks.org/array-strings-c-3-different-ways-create/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "credits.h"
#include "menu.h"
#include "GameEngine.h"
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
//-------------------------------------------------------------------------------------
// MOVED TO NEWGAME.CPP
// void Menu::newGame() { 

//   // These are only initialised for testing purposes
//   // They should come from the Player files
//   std::string player1 = "";
//   std::string player2 = "";
//   std::vector<std::string> gameList;
//   gameList.emplace_back(std::move("Starting a New Game"));
//   gameList.emplace_back(
//       std::move("Enter a name for player 1 (uppercase characters only)"));
//   gameList.emplace_back(
//       std::move("Enter a name for player 2 (uppercase characters only)"));
//   gameList.emplace_back(std::move("Let's Play!"));

//   // Print Strings stored in Vector
//   std::cout << " " << std::endl;
//   std::cout << gameList[1] << std::endl;
//   std::cin >> player1;
//   // this will convert the user input to uppercase
//   // I'm not sure about casting it as an int though.
//   for (int i = 0; i < (int)player1.size(); ++i) {
//     player1[i] = toupper(player1[i]);
//   }
//   std::cout << " " << std::endl;
//   std::cout << gameList[2] << std::endl;
//   std::cin >> player2;
//   // this will convert the user input to uppercase
//   // I'm not sure about casting it as an int though.
//   for (int i = 0; i < (int)player2.size(); ++i) {
//     player2[i] = toupper(player2[i]);
//   }
//   std::cout << gameList[3] << std::endl;
//   std::cout << " " << std::endl;
// };
//-------------------------------------------------------------------------------------

void Menu::selectionMenu() {
  Credits printCredits;
  newGame runGame;
  int selected = -1;

  while ((selected = Menu::mainMenu()) <= 4 && !std::cin.eof()) {
    if (selected == 1) {
      std::cout << "Starting a New Game" << std::endl;
      std::cout << "-------------------" << std::endl;
      runGame.runGame();
      // Menu::newGame();
    } else if (selected == 2) {
      std::cout << "Enter the filename from which to load a game" << std::endl;
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