
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include "Tile.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
    /**
     * Add the value to the front of the Linked List
     */
    void addFront(Tile* tile);
    
    /**
     * Add the value to the back of the Linked List
     */
    void addBack(Tile* tile);
    /**
     * print the data of all of the Nodes in the Linked List
     */
    /**
    * Remove the value at the front of the Linked List
    */
    void removeFront();
    /**
    * Remove the value at the back of the Linked List
    */
    void removeBack();
    
    /**
     * Clear all of the nodes in the linked list
     */
    void clear();
    
    /**
     * Return the current size of the Linked List.
     * make it const as we are stating that we will not change the contents of the object to
     * be explicit
     */
    
    unsigned int listSize() const;
    Tile get(unsigned int index) const;

    void printNodes();

private:
   Node* head;
};




#endif // ASSIGN2_LINKEDLIST_H