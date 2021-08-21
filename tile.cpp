#include "tile.h"

// Constructor to create a new shape
Tile::Tile(Colour colour, Shape shape) {
  // default contructor
  this->colour = new Colour(colour);
  this->shape = new Shape(shape);
}
Tile::~Tile() {
  // destructor
  delete colour;
  delete shape;
}
Colour Tile::getTileColour() { return *colour; }
Shape Tile::getTileShape() { return *shape; }