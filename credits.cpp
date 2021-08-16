#include <iostream>
#include <fstream>
#include <string>

#include "credits.h"
#include "menu.h"

Credits::~Credits() {}

int Credits::printCredits() {
  std::string credits;
  std::ifstream file("credits.txt");
  if (file.is_open()) {
    while (std::getline(file, credits) && !file.eof()) {
      std::cout << credits << std::endl;
    }
    file.close();
  } else
    std::cout << "Cannot open file!" << std::endl;
  return EXIT_SUCCESS;
};
