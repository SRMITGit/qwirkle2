#ifndef ASSIGN2_BAG_H
#define ASSIGN2_BAG_H

#include "LinkedList.h"

#define MAX_BAG_TILES 72

class Bag : public LinkedList {
public:
  // default constructor
  Bag();
  // destructor
  ~Bag();
  // copy constructor
  Bag(Bag &other);
  // void addTilesToBag();
  void addTilesToBag(Bag *gameBag);
  void loadGameTileBag(Bag *gameBag);
  Colour randomColour();
  Shape randomShape();

private:
  // create a new linked list for the bag
  LinkedList *gameBag;
};

#endif /* ASSIGN2_BAG_H */
