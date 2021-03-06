#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <iostream>
#include <ostream>

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:
  // standard constructor
  Tile(Colour colour, Shape shape);
  // destructor
  ~Tile();

  // getters
  Colour getTileColour();
  Shape getTileShape();

private:
  Colour *colour;
  Shape *shape;
  std::ostream *outputStream = &std::cout;
};

#endif // ASSIGN2_TILE_H