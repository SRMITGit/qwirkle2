/* The helpful tips for help.txt were sourced from
Ultra BoardGames n.d., Tips to win Qwirkle | UltraBoardGames,
www.ultraboardgames.com, viewed 18 August 2021,
<https://www.ultraboardgames.com/qwirkle/tips.php>. */

#include "userPrompt.h"
#include "help.h"
#include "menu.h"
#include "newGame.h"
#include "tileColours.h"

UserPrompt::UserPrompt() {}
UserPrompt::~UserPrompt() {}

void UserPrompt::userPrompt() { std::cout << SIGN << SPACE; }

void UserPrompt::textPrompt() {
  Help displayHelp;
  Menu selectionMenu;
  newGame saveGame;
  std::string userChoice;
  std::cin >> userChoice;
  if (userChoice == "help") {
    displayHelp.displayHelp();
  } else if (userChoice == "save") {
    saveGame.saveGame();
  }
  std::cout << " " << std::endl;
  std::cout << "Please enter your menu selection from 1 to 4." << std::endl;
}
