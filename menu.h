#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Menu {
public:
  Menu();
  // Copy constructor
  Menu(Menu &other);
  // Move constructor
  Menu(Menu &&other);
  // Deconstructor
  ~Menu();

  Menu getMenuList();
  int getNumber();
  int size();
  int mainMenu();
  int length = 0;

  Menu *get(int index);
  void add(Menu *menuList);
  void add(Menu *menuList, int index);
  void remove(int index);

  void selectionMenu();
  void clear();
  void quit();

private:
  Menu *colour;
  int *number;
  std::vector<Menu *> menuList;
};

#endif // ASSIGN2_MENU_H