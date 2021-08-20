/* The helpful tips for help.txt were sourced from
Ultra BoardGames n.d., Tips to win Qwirkle | UltraBoardGames,
www.ultraboardgames.com, viewed 18 August 2021,
<https://www.ultraboardgames.com/qwirkle/tips.php>. */

#include "userPrompt.h"
#include "help.h"
#include "menu.h"
#include "newGame.h"

UserPrompt::UserPrompt() {}
UserPrompt::~UserPrompt() {}
// Help::Help() {}
// Menu::Menu() {}

void UserPrompt::userPrompt() {
  Help displayHelp;
  Menu selectionMenu;
  newGame saveGame;
  std::string userChoice;
  std::cout << SIGN << SPACE;
  std::cin >> userChoice;
  if (userChoice == "help") {
    displayHelp.displayHelp();
  } else if (userChoice == "save") {
    saveGame.saveGame();
  } else {
    selectionMenu.selectionMenu();
  }
}

// void UserPrompt::helpPrompt() {
// // void UserPrompt::userPrompt() {
//   Help displayHelp;
//   newGame saveGame;
//   std::string help;
//   std::string save;
//   std::string userResponse;

//  std::string save = ".save";

//   std::string fileName = "";
//   std::cout << "Enter name you wish to give to save game file" << std::endl;
//   std::cout << ">";
//   std::cin >> fileName;
//   fileName = "Saved Games/" + fileName;

//   // check if file name has a .save at the back, if none add it
//   if (fileName.find(save) != std::string::npos) {
//   } else {
//     fileName = fileName + save;
//   }

//   std::cout << SIGN << SPACE;
//   if (userResponse == "help") {
//     displayHelp.displayHelp();
//   } else if (userResponse == "save") {
//     saveGame.saveGame();
//   } else {
//       std::cout << SIGN << SPACE;
//     // return;
//   }
// }

/*
int Help::displayHelp() {
  std::string help;
  std::ifstream file("help.txt");
  try {
    if (file.is_open()) {
      while (std::getline(file, help) && !file.eof()) {
        std::cout << help << std::endl;
      }
      file.close();b
    } else {
      throw std::runtime_error("Could not open file");
    }
  } catch (std::exception &e) {
    std::cerr << "Oops, something went wrong! \n" << e.what() << "\n";
  }
  return EXIT_SUCCESS;
}; */

/* int Help::helpPrompt() {
std::cout << "Please enter input file name: ";
std::string help;
std::cin >> help;
std::ifstream ist(help.c_str());
// ist is an input stream for the file named name
if (!ist) throw std::runtime_error("Could not open file");
} */
