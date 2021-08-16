#ifndef LINKEDLISTTEST
#define LINKEDLISTTEST

#include "menuTest.h"

class Node{
public:
    Menu* menu;
    Node* next;
};

class LinkedListTest{
public:
    LinkedListTest();
    LinkedListTest(LinkedListTest& other);
    ~LinkedListTest();

    int size();

    Menu* get(int index);

    void add_front(Menu* data);
    void add_back(Menu* data);

    //Contract: Elements should exist in the list to be deleted.
    void remove_front();
    void remove_back();

    void remove(int index);

    void clear();

private:

    Node* head;
    
};


#endif //LINKEDLISTTEST