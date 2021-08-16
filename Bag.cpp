//
// Bag.cpp
// Creates a bag which is used to hold tiles which are than taken from the Bag and placed in the players hand
//

#include "Bag.h"
#include <iostream>
#include "Tile.h"
#include "TileCodes.h"
#include <random>

#define MAX_BAG_TILES 72

Bag::Bag() {
  // constructor for a new bag of tiles
  this -> gameBag = new LinkedList();
}

Bag::~Bag() {
  // destructor
  std::cout << "Deleting Bag Object and Attributes: " << std::endl;
  delete gameBag;
}

void Bag::addTilesToBag(Bag * gameBag) {
  // add all of the starting tiles to the bag
  int counter = 0;
  // loop to add tiles to the bag
  while (counter < MAX_BAG_TILES) {
    Tile * randomTile = new Tile(randomColour(), randomShape());
    std::cout << "Adding Tile Numer: " << counter << " to the bag: " << std::endl;
    gameBag -> addFront(randomTile);
    ++counter;
  }
}

Colour Bag::randomColour() {
  Colour randomColour;
  // initialise ints for the colour and shape
  int colourValue = -1;
  int min = 1;
  int max = 6;
  std::random_device engine;
  std::uniform_int_distribution < int > uniform_dist(min, max);
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
  std::cout << "Randomly-chosen colour: " << colourValue << std::endl;
  return randomColour;
}

Shape Bag::randomShape() {

  Shape randomShape;
  // initialise ints for the colour and shape
  int shapeValue = -1;
  int min = 1;
  int max = 6;
  std::random_device engine;
  std::uniform_int_distribution < int > uniform_dist(min, max);
  shapeValue = uniform_dist(engine);
  // random shape
  if (shapeValue == (1)) {
    randomShape = CIRCLE;
  } else if (shapeValue == (2)) {
    randomShape = STAR_4;
  } else if (shapeValue == (3)) {
    randomShape = DIAMOND;
  } else if (shapeValue == (4)) {
    randomShape = SQUARE;
  } else if (shapeValue == (5)) {
    randomShape = STAR_6;
  } else {
    randomShape = CLOVER;
  }
  std::cout << "Randomly-chosen shape: " << shapeValue << std::endl;

  return randomShape;
}