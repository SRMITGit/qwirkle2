#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "tile.h"

class Node {
public:
  Node();
  Node(Tile *tile, Node *next);
  Node(Node &other);

  Tile *tile;
  Node *next;
  int tileSearch;
};

#endif // ASSIGN2_NODE_H