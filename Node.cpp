
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
   // initilise the tile and the next to be null
   this->tile = tile;
   this->next = next;
    
    
    

}

Node::Node()
{
   // initilise the tile and the next to be null
   this->tile = nullptr;
   this->next = nullptr;
    
    
    

}

Node::Node(Node& other)
{
   // TODO
}