#ifndef ASSIGN2_EMOJI_H
#define ASSIGN2_EMOJI_H

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

#endif // ASSIGN2_EMOJI_H
