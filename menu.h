#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H

#include <vector>

// Sources to make Terminal Colours
// https://stackoverflow.com/questions/9158150/colored-output-in-c
// https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
// https://www.codegrepper.com/code-examples/actionscript/ansi+colors+orange
// https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/

// Resets everything back to the standard colour.
#define RESET_COLOUR "\033[0m"
// Text Colours
#define BLACK_TEXT "\033[30m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define MAGENTA_TEXT "\033[35m"
#define CYAN_TEXT "\033[36m"
#define WHITE_TEXT "\033[37m"
// Background Colours
#define BLACK_BACKGROUND "\033[40m"
#define RED_BACKGROUND "\033[41m"
#define YELLOW_BACKGROUND "\033[43m"
#define BLUE_BACKGROUND "\033[44m"
#define MAGENTA_BACKGROUND "\033[45m"

// These chars add the User Prompt after the menu (Section 2.4)
#define SIGN char('>')
#define SPACE char(' ')

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

  Menu *get(int index);
  void add(Menu *menuList);
  void add(Menu *menuList, int index);
  void remove(int index);

  void selectionMenu();
  void clear();
  void quit();
  // void newGame();

private:
  Menu *colour;
  int *number;
  std::vector<Menu *> menuList;
};

#endif // ASSIGN2_MENU_H