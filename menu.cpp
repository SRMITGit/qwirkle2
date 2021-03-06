#include "menu.h"
#include "gameEngine.h"
#include "credits.h"
#include "help.h"
#include "loadGame.h"
#include "newGame.h"
#include "tileColours.h"
#include "tileEmoji.h"
#include "userPrompt.h"

Menu::Menu() {}
Menu::~Menu() {}
Credits::Credits() {}

// Returns the current size of the Menu
int Menu::size() { return MAX_MENU_SIZE; }

// Quits the entire program
void Menu::quit() {
  std::string quit = "Goodbye! ";
  std::cout << quit << GOODBYE << std::endl;
  exit(1);
}

int Menu::mainMenu() {
  UserPrompt userPrompt;
  // Reference:
  // https://stackoverflow.com/questions/60616203/how-can-i-make-a-function-that-prints-out-a-menu
  // Declaring Vector of String type
  // Strings can be added at any time with emplace_back
  std::vector<std::string> menuList;
  menuList.reserve(MAX_MENU_SIZE);
  menuList.emplace_back(std::move("1. New Game"));
  menuList.emplace_back(std::move("2. Load Game"));
  menuList.emplace_back(std::move("3. Credits"));
  menuList.emplace_back(std::move("4. Quit"));

  // Print Strings stored in Vector
  std::cout << GREEN_TEXT << "Menu" << RESET_COLOUR << std::endl;
  std::cout << "-------" << std::endl;
  /* Programiz n.d., C++ printf() - C++ Standard Library, www.programiz.com, viewed 18 August 2021, 
  <https://www.programiz.com/cpp-programming/library-function/cstdio/printf>. */  
  for (const std::string &menuChoice : menuList) {
    std::cout << menuChoice << std::endl;
  }
  userPrompt.userPrompt();
  userPrompt.textPrompt();

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
  Help displayHelp;
  int selected = -1;

  while ((selected = Menu::mainMenu()) <= size() && !std::cin.eof()) {
    if (selected == 1) {
      std::cout << BLUE_TEXT << "Starting a New Game " << RED_TEXT << JOYSTICK
                << RESET_COLOUR << std::endl;
      std::cout << "-------------------" << std::endl;
      runGame.runGame();
    } else if (selected == 2) {
      loadGame.readFile();
    } else if (selected == 3) {
      std::cout << "The Team!" << std::endl;
      printCredits.printCredits();
    } else if (selected == 4) {
      std::cout << " " << std::endl;
      Menu::quit();
    } else {
      std::cout << " " << std::endl;
      std::cout << "Invalid Input" << std::endl;
    }
  }
};