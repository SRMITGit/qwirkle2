/* Bag.cpp
Creates a bag which is used to hold tiles which are than taken from the Bag
and placed in the players hand
 */

#include "bag.h"
#include "tile.h"
// #include "TileCodes.h"
#include "loadGame.h"
#include "tileColours.h"
#include "tileEmoji.h"
#include <iostream>
#include <random>
#include <stdio.h>

Bag::Bag() {
  // constructor for a new Bag of tiles
  this->gameBag = new LinkedList();
}

Bag::~Bag() {
  // destructor
  std::cout << "Calling Bag Destructor - Deleting Bag Object and Attributes: "
            << std::endl;
  delete gameBag;
}

void Bag::addTilesToBag(Bag *gameBag) {
  // add all of the starting tiles to the Bag
  int counter = 0;
  // loop to add tiles to the Bag
  while (counter < MAX_BAG_TILES) {
    Tile *randomTile = new Tile(randomColour(), randomShape());
    // std::cout << "Adding Tile Numer: " << counter << " to the Bag: " <<
    // std::endl;
    gameBag->addFront(randomTile);
    ++counter;
  }
  std::cout << "Bag is full, total Tiles in the Bag:  " << gameBag->listSize()
            << std::endl;
}

// Created by Guy - trying to create a Bag not randomly generated.
void Bag::loadGameTileBag(Bag *gameBag) {
  loadGame loadGame;
  int counter = 0; // will need to count how many tile have already left the Bag
  int counter2 = 0;
  int counter3 = 0;

  // loop and add tiles to the Bag
  while (counter < MAX_BAG_TILES) {
    for (int i = 0; i < 1; i++) {
      for (int j = 0; j < 1; j++) {
        Tile *loadTile = new Tile(loadGame.getArrBag(counter2),
                                  loadGame.getArrBag(counter3));
        gameBag->addFront(loadTile);
        counter++;
        counter3++;
      }
      counter2++;
    }
  }
}

// Colour bag::randomColour() {
//   Colour randomColour;
//   // initialise ints for the colour and shape
//   int colourValue = -1;
//   int min = 1;
//   int max = 6;
//   std::random_device engine;
//   std::uniform_int_distribution<int> uniform_dist(min, max);
//   colourValue = uniform_dist(engine);
//   // random Colour
//   if (colourValue == (1)) {
//     randomColour = std::printf("R %s", RED_TEXT);  //\033[31m RED
//   } else if (colourValue == (2)) {
//     randomColour = std::printf("O %s", MAGENTA_TEXT);  //\033[35m ORANGE 
//   } else if (colourValue == (3)) {
//     randomColour = std::printf("Y %s", YELLOW_TEXT);  //\033[33m YELLOW
//   } else if (colourValue == (4)) {
//     randomColour = std::printf("G %s", GREEN_TEXT);  //\033[32m GREEN
//   } else if (colourValue == (5)) {
//     randomColour = std::printf("B %s", BLUE_TEXT);  //\033[34m  BLUE
//   } else {
//     randomColour = std::printf("P %s", CYAN_TEXT);  //\033[36m PURPLE 
//   }
//   // std::cout << "Randomly-chosen colour: " << colourValue << std::endl;
//   return randomColour;
//   // return 0;
// }

Colour Bag::randomColour() {
  Colour randomColour;
  // initialise ints for the colour and shape
  int colourValue = -1;
  int min = 1;
  int max = 6;
  std::random_device engine;
  std::uniform_int_distribution<int> uniform_dist(min, max);
  colourValue = uniform_dist(engine);
  // random Colour
  if (colourValue == (1)) {
    randomColour = RED;
  } else if (colourValue == (2)) {
    randomColour = ORANGE;
  } else if (colourValue == (3)) {
    randomColour = YELLOW;
  } else if (colourValue == (4)) {
    randomColour = GREEN;
  } else if (colourValue == (5)) {
    randomColour = BLUE;
  } else {
    randomColour = PURPLE;
  }
  // std::cout << "Randomly-chosen colour: " << colourValue << std::endl;
  return randomColour;
}

Shape Bag::randomShape() {
  Shape randomShape;
  // initialise ints for the colour and shape
  int shapeValue = -1;
  int min = 1;
  int max = 6;
  std::random_device engine;
  std::uniform_int_distribution<int> uniform_dist(min, max);
  shapeValue = uniform_dist(engine);
  // random shape
  if (shapeValue == (1)) {
    randomShape = std::printf("%s", LARGE_BLUE_CIRCLE); //CIRCLE  \U0001F535
    // std::printf(PURPLE_SQUARE, randomShape);
  } else if (shapeValue == (2)) {
    randomShape = std::printf("%s", STAR); //STAR_4);  \U00002B50 
    // std::printf(STAR, randomShape);
  } else if (shapeValue == (3)) {
    randomShape = std::printf("%s", BLUE_DIAMOND); //DIAMOND);  \U0001F537 
    // std::printf(WHITE_FLOWER, randomShape);
  } else if (shapeValue == (4)) {
    randomShape = std::printf("%s", PURPLE_SQUARE); //SQUARE);  \U0001F7EA 
    // std::printf(KANGAROO, randomShape);
  } else if (shapeValue == (5)) {
    randomShape = std::printf("%s", KANGAROO); //STAR_6);  \U0001F998 
    // std::printf(FIRE, randomShape);
  } else {
    randomShape = std::printf("%s", FIRE); //CLOVER);  \U0001F525 
    // std::printf(BLACK_SQUARE, randomShape);
  }
  // std::cout << "Randomly-chosen shape: " << shapeValue << std::endl;
  return randomShape;
  // return 0;
}
