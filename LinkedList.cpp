
#include "LinkedList.h"
#include "Tile.h"
#include <iostream>
#include <stdexcept>

LinkedList::LinkedList() {
  this->head = nullptr;

  // TODO
}

LinkedList::~LinkedList() {
  // deconstructor
  std::cout << "Calling Linked List Destructor to Delete all Nodes"
            << std::endl;
  Node *current = head;
  while (current != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
  }
  head = 0;
}

void LinkedList::addFront(Tile *tile) {
  // add to the front of the linked
  // create a new Node Temp data
  try {
    Node *tmpNode = new Node(tile, nullptr);
    //   // assign the value of passed in to the value of the new temp node
    tmpNode->tile = tile;
    tmpNode->next = head;
    head = tmpNode;
  } catch (const std::runtime_error &e) {
    std::cerr << "Oops, can't add to the front! \n" << e.what() << "\n";
  }
}

void LinkedList::addBack(Tile *tile) {
  // node that we want to add needs to point to nullptr as we want to add it to
  // the end of the linked list and last node always points to nullptr
  try {
    Node *toAdd = new Node();
    toAdd->tile = tile;
    toAdd->next = nullptr;

    if (head == nullptr) {
      head = toAdd;
    } else {
      Node *current = head;

      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = toAdd;
    }
  } catch (const std::runtime_error &e) {
    std::cerr << "Oops, can't add to the back! \n" << e.what() << "\n";
  }
}

void LinkedList::removeFront() {
  // removes the first node in the list
  try {
    if (this->head != NULL) {
      // create a temp node and assign it the head
      // so now temp node and head are the same
      // head is a pointer to the first node in the list that we want to remove
      Node *tmpNode = head;
      // move the head to point to the next node in the list
      head = head->next;
      delete tmpNode;
    }
  } catch (const std::runtime_error &e) {
    std::cerr << "Oops, remove from the front! \n" << e.what() << "\n";
  }
}

void LinkedList::removeBack() { // https://www.youtube.com/watch?v=i3b3O7slIzk
  // case 1 - Empty Linked List
  try {
    if (this->head == nullptr) {
      std::cout << "List was empty so cannot remove from BACK!" << std::endl;
      return;
    } else {
      Node *current = head;  // ptr
      Node *previous = NULL; // prev
      // case 2 - One Node Linked List
      if (head->next == NULL) {
        current = head;
        head = NULL;
      }
      // case 3 - Two Node or More Linked List
      else {
        current = head;
        while (current->next != NULL) {
          previous = current;
          current = current->next;
        }
        // once loop finished point the last node in the list to NULL
        previous->next = NULL;
        delete current;
      }
    }
  } catch (const std::runtime_error &e) {
    std::cerr << "Oops, remove from the back! \n" << e.what() << "\n";
  }
}

unsigned int LinkedList::listSize() const {
  // if length of linked list is zero then loop will not run as head will be
  // current and this will be pointing to a nullptr
  unsigned int count = 0;
  Node *current = head;
  while (current != nullptr) {
    ++count;
    current = current->next;
  }

  return count;
}

Tile LinkedList::get(unsigned int index) const {

  unsigned int count = 0;
  Node *current = head;
  // need to make sure that value given is zero or greater
  // int returnValue = std::numeric_limits<int>::min();
  // if (index >= 0 && index < size()) // can get rid of this now we changed it
  // to unsigned
  Tile *returnValue = current->tile;
  try {
    if (index < listSize()) {
      while (count < index) {
        ++count;
        current = current->next;
      }
      returnValue = current->tile;
    } else {
      // in c++ can throw any object as an exception
      // find the most relevant error from the base Exception class
      // find the constructor to create an object of that type of object that
      // want to throw
      throw std::out_of_range("Sorry, that tile cannot be reached.");
    }
  } catch (std::exception &e) {
    std::cerr << "Oops, something went wrong! \n" << e.what() << "\n";
  }
  return *returnValue;
}

void LinkedList::printNodes() {
  //   {
  //       if length of linked list is zero then loop will not run as head will
  //       be current and this will be pointing to a nullptr
  unsigned int count = 0;
  Node *current = head;
  //      // look unit we get to the tail node
  std::cout << "Your hand is " << std::endl;
  while (current != nullptr) {
    std::cout << current->tile->getTileColour() << current->tile->getTileShape()
              << ",";
    ++count;
    current = current->next;
  }
  std::cout << std::endl;
  //   }
}

void LinkedList::clear() {
  while (head != nullptr) {
    removeFront();
  }
}