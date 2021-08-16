
#include "Tile.h"
#include <iostream>

//Constructor to create a new shape
Tile::Tile(Colour colour, Shape shape){
    // default contructor
    std::cout << "Creating a new Shape Object: " << std::endl;
    this->colour = new Colour(colour);
    this->shape = new Shape(shape);

}
Tile::~Tile(){
    // destructor
    std::cout << "Deleting Shape Object and Attributes: " << std::endl;
    delete colour;
    delete shape;
}
Colour Tile::getTileColour(){
    return *colour;
    
}
Shape Tile::getTileShape(){
    return *shape;
}

