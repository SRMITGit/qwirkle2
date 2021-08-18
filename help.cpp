/* The helpful tips for help.txt were sourced from
Ultra BoardGames n.d., Tips to win Qwirkle | UltraBoardGames, 
www.ultraboardgames.com, viewed 18 August 2021, <https://www.ultraboardgames.com/qwirkle/tips.php>. */

#include "help.h"

Help::Help() {}
Help::~Help() {}

int Help::displayHelp() {
  std::string help;
  std::ifstream file("help.txt");
  try {
    if (file.is_open()) {
      while (std::getline(file, help) && !file.eof()) {
        std::cout << help << std::endl;
      }
      file.close();
    } else {
      throw std::runtime_error("Could not open file");
    }
  } catch (std::exception &e) {
    std::cerr << "Oops, something went wrong! \n" << e.what() << "\n";
  }
  return EXIT_SUCCESS;
};
