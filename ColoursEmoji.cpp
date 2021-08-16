#include <iostream>
#include <string>
#include <vector>

#include "tileColours.h"
#include "tileEmoji.h"

Colours::Colours() {}
Colours::~Colours() {}
Emoji::Emoji() {}
Emoji::~Emoji() {}

void Colours::tileColours() {
  // Declaring Vector of String type
  // Values can be added here using initialise-list syntax
  std::vector<std::string> menuList{"1.New Game", "2. Load Game", "3. Credits",
                                    "4. Quit"};

  // Print Strings stored in Vector
  for (std::string i : menuList) {
    std::cout << i << " ";
  }

  std::cout << "Menu" << std::endl;
  std::cout << "----" << std::endl;
  std::cout << GREEN_TEXT << menuList[0] << "  | \U0001F600" << RESET_COLOUR
            << std::endl;
  std::cout << YELLOW_BACKGROUND << menuList[1] << RESET_COLOUR << " " << FIRE
            << RESET_COLOUR << std::endl;
  std::cout << BLUE_TEXT << menuList[2] << RESET_COLOUR << std::endl;
  std::cout << RED_BACKGROUND << menuList[3] << RESET_COLOUR << std::endl;
};

void Emoji::tileEmoji() {
  std::cout << LARGE_BLUE_CIRCLE << std::endl;
  std::cout << RED_CIRCLE << RESET_COLOUR << std::endl;
  std::cout << BLACK_CIRCLE << RESET_COLOUR << std::endl;
  std::cout << WHITE_CIRCLE << RESET_COLOUR << std::endl;
  std::cout << STAR << RESET_COLOUR << std::endl;
  std::cout << BLUE_DIAMOND << RESET_COLOUR << std::endl;
  std::cout << ORANGE_DIAMOND << RESET_COLOUR << std::endl;
  std::cout << BLACK_SQUARE << RESET_COLOUR << std::endl;
  std::cout << WHITE_FLOWER << RESET_COLOUR << std::endl;
  std::cout << BLUE_DIAMOND << RESET_COLOUR << std::endl;
  std::cout << KANGAROO << RESET_COLOUR << std::endl;
};
