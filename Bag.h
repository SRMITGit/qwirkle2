//
//  Bag.h


//

#ifndef Bag_h
#define Bag_h

#include "LinkedList.h"

class Bag: public LinkedList
{
public:
    //defaul constructor
    Bag();
    //destructor
    ~Bag();
    //copy constructor
    Bag(Bag& other);
    // void addTilesToBag();
    void addTilesToBag(Bag * gameBag);
    void loadGameTileBag(Bag * gameBag);
    Colour randomColour();
    Shape randomShape();


private:
    // create a new linked list for the bag
    LinkedList* gameBag;

};

#endif /* Bag_h */
