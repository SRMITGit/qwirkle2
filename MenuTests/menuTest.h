#ifndef MenuTest_H
#define MenuTest_H 

// #include <iostream>
// #include <string>
// #include <vector>
// #include <istream>
// #include "LinkedListTest.h"

// using std::vector;
// using std::cin;
// using std::cout;
// using std::endl;

// #include "Credits.h"

#define RESET "\033[0m"
// Text Colours
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
// Background Colours
#define BLACK_BACKGROUND "\033[40m"
#define RED_BACKGROUND "\033[41m"
#define YELLOW_BACKGROUND "\033[43m"
#define BLUE_BACKGROUND "\033[44m"
#define MAGENTA_BACKGROUND "\033[45m"

class Menu {
public:
   Menu();
   Menu(Menu& other);
   Menu(Menu&& other);
   ~Menu();

   /**
    * Return the current size of the Menu.
    */
   int size();

   /**
    * Get a menu item at the given index.
    * Nullptr if out-of-range
    */
   Menu* get(int index);

   /**
    * Add a menu item to the Menu to the bottom of the Menu
    */
   void add(Menu* menu);

   /**
    * Add a menu item at the given index of the Menu
    */
   void add(Menu* menu, int index);

   /**
    * Remove a menu item from the Menu at the given index
    */
   void remove(int index);

   /**
    * Removes all menu items from the Menu.
    * Delete the menu items
    */
   void clear();

private:
   LinkedListTest* menu;
   // Card* Menu[MAXIMUM_Menu_SIZE];
   // // Card** Menu;
   // int length;

//    std::vector<Card*> Menu;
//  vector<std::string> menuItem;

};

#endif // MenuTest_H
