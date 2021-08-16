#include "menuItem.h"

#include <iostream>

MenuItem::MenuItem(int _number)
{
   this->number = _number;
}

MenuItem::MenuItem(MenuItem& other) {
   this->number = other.number;
}

MenuItem::~MenuItem() {
}

int MenuItem::getNumber() {
   return number;
}
