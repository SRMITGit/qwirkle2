#ifndef ASSIGN2_TILEEMOJI_H
#define ASSIGN2_TILEEMOJI_H

// Sources to make Terminal Colours
// https://stackoverflow.com/questions/9158150/colored-output-in-c
// https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
// https://www.codegrepper.com/code-examples/actionscript/ansi+colors+orange
// https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/
// source: https://github.com/99x/emojicpp
// https://www.sololearn.com/Discuss/2178679/how-to-print-emoji-shapes-in-console-output-screen-in-c-c-language
// https://emojipedia.org/shortcodes/

// Emoji
/* Basically find the Unicode for the emoji you want to use
A smiley face is U+1F600 😀
Then, remove the "+" from it,
U+1F600 -> U1F600.
Put backslash before "U" and three zeros after "U".
"\U0001F600" */
#define LARGE_BLUE_CIRCLE "\U0001F535"
#define RED_CIRCLE "\U0001F534"
#define BLACK_CIRCLE "\U000026AB"
#define WHITE_CIRCLE "\U000026AA"
#define STAR "\U00002B50"
#define BLUE_DIAMOND "\U0001F537"
#define ORANGE_DIAMOND "\U0001F536"
#define DIAMOND "\U00002666"
#define BLACK_SQUARE "\U00002B1B"
#define WHITE_FLOWER "\U0001F4AE"
#define KANGAROO "\U0001F998"
#define FIRE "\U0001F525"

class Emoji {
public:
  Emoji();
  // Copy constructor
  Emoji(Emoji &other);
  // Move constructor
  Emoji(Emoji &&other);
  // Deconstructor
  ~Emoji();

  void tileEmoji();



  Emoji getEmojiList();
  int getNumber();
  int size();
  int mainEmoji();

  Emoji *get(int index);
  void add(Emoji *emojiList);
  void add(Emoji *emojiList, int index);
  void remove(int index);

  void selectionEmoji();
  void clear();
  void quit();
  // void newGame();

private:
  Emoji *colour;
  int *number;
  // std::vector<Emoji *> emojiList;
};





#endif // ASSIGN2_TILEEMOJI_H
