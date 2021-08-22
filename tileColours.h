#ifndef ASSIGN2_TILECOLOURS_H
#define ASSIGN2_TILECOLOURS_H

#include <iostream>
#include <string>
#include <vector>

// Sources to make Terminal Colours
// https://stackoverflow.com/questions/9158150/colored-output-in-c
// https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
// https://www.codegrepper.com/code-examples/actionscript/ansi+colors+orange
// https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/
// source: https://github.com/99x/emojicpp
// https://www.sololearn.com/Discuss/2178679/how-to-print-emoji-shapes-in-console-output-screen-in-c-c-language
// https://emojipedia.org/shortcodes/

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

enum Colours {
  RED = 'R',
  ORANGE = 'O',
  YELLOW = 'Y',
  GREEN = 'G',
  BLUE = 'B',
  PURPLE = 'P'
};

class TileColours {
public:
  TileColours();
  // Copy constructor
  TileColours(TileColours &other);
  // Move constructor
  TileColours(TileColours &&other);
  // Deconstructor
  ~TileColours();

  void tileColours();

  TileColours getTileColoursList();
  int getNumber();
  int size();
  int mainTileColours();

  TileColours *get(int index);
  void add(TileColours *tileColoursList);
  void add(TileColours *tileColoursList, int index);
  void remove(int index);

  void selectionTileColours();
  void clear();
  void quit();

private:
  TileColours *tileColour;
  int *number;
  std::vector<Colours *> coloursList;
};

#endif // ASSIGN2_TILECOLOURS_H
