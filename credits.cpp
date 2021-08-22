#include "credits.h"
#include "menu.h"

Credits::~Credits() {}

int Credits::printCredits() {
  std::string credits;
  std::ifstream file("credits.txt");
  try {
    if (file.is_open()) {
      while (std::getline(file, credits) && !file.eof()) {
        std::cout << credits << std::endl;
      }
      file.close();
    } else {
      throw std::runtime_error("Could not open file");
    }
  } catch (std::exception &e) {
    std::cerr << "Oops, can't seem to find that file! \n> " << e.what() << "\n";
  }
  return EXIT_SUCCESS;
};
