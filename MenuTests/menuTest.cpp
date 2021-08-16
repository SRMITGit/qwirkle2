

#include "menuTest.h"
#include "menuItem.h"
#include "LinkedListTest.h"

Menu::Menu() {
    menu = new LinkedListTest();
}
Menu::Menu(Menu& other) {
    menu = new LinkedListTest(*other.menu);
}
Menu::Menu(Menu&& other) {

}
Menu::~Menu() {
    delete menu;
}

/**
* Return the current size of the Menu.
*/
int Menu::size() {
    return menu->size();
}

/**
* Get a menu item at the given index.
* Nullptr if out-of-range
*/
MenuItem* Menu::get(int index) {
     return menu->get(index);
}

/**
* Add a menu item to the Menu to the bottom of the Menu
*/
void Menu::add(Menu* menuItem) {
    menu->add_back(menuItem);
}

/**
* Add a menu item at the given index of the Menu
*/
void Menu::add(Menu* menuItem, int index) {
    
}

/**
* Remove a menu item from the Menu at the given index
*/
void Menu::remove(int index) {
   menu->remove(index);
}

/**
* Removes all menu items from the Menu.
* Delete the menu items
*/
void Menu::clear() {
     menu->clear();
}
