#include "bag.h"
#include "board.h"
#include "credits.h"
#include "linkedList.h"
#include "menu.h"
#include "player.h"
#include "tile.h"
#include "tileColours.h"
#include "tileEmoji.h"

int main(void) {
  Menu selectionMenu;
  std::cout << RED_CIRCLE << " " << BLACK_CIRCLE << " " << WHITE_CIRCLE << " "
            << " Welcome to Qwirkle! " << PURPLE_SQUARE << " " << WHITE_FLOWER
            << " " << KANGAROO << std::endl;
  std::cout << "------------------------------------" << std::endl;
  selectionMenu.selectionMenu();
  return EXIT_SUCCESS;
}