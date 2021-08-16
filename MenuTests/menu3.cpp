// Sources to make Terminal Colours
// https://stackoverflow.com/questions/9158150/colored-output-in-c
// https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
// https://www.codegrepper.com/code-examples/actionscript/ansi+colors+orange
// https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/
// https://www.geeksforgeeks.org/array-strings-c-3-different-ways-create/

#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstdio>

#include "menu.h"

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;

// string player1, player2;

#define MAX_TILES_IN_BAG 106
#define MAX_TILES_TO_START 6

int i;

int mainMenu() {
  // Declaring Vector of String type
  // Values can be added here using initialise-list syntax
  vector<std::string> menuList{"1.New Game", "2. Load Game", "3. Credits",
                                    "4. Quit"};

  // Strings can be added at any time with push_back
  menuList.push_back("Add More");

  // Print Strings stored in Vector
  for (int i = 0; i < (int)menuList.size(); ++i)
    cout << menuList[i] << "\n";
  //}
  // int mainMenu() {
  cout << "Menu" << endl;
  cout << "----" << endl;
  cout << GREEN << menuList[0] << RESET << endl;
  cout << YELLOW_BACKGROUND << menuList[1] << RESET << endl;
  cout << BLUE << menuList[2] << RESET << endl;
  cout << RED_BACKGROUND << menuList[3] << RESET << endl;

  int selected = 0;
  string input;
  cin >> input;
  if (stringstream(input) >> selected) {
    return selected;
  } else {
    return -1;
  }
};
void start(){

};

void newGame() {
  string player1 = "";
  string player2 = "";
  cout << "Starting a New Game" << endl;
  cout << " " << endl;
  cout << "Enter a name for player 1 (uppercase characters only)" << endl;
  cin >> player1;
  cout << " " << endl;
  cout << "Enter a name for player 2 (uppercase characters only)" << endl;
  cin >> player2;
  cout << " Let's Play!" << endl;
  cout << " " << endl;
};
/*
void credits() {
std::vector<std::string> creditList {
" Name: Philip Beeby",
" Email: s3666628@student.rmit.edu.au",
" Student ID: s3666628",
" Name: Guy Leighton",
" Student ID: s3587205",
" Email: s3587205@student.rmit.edu.au",
" Name: Stephen Patrikios",
" Student ID: s3852734",
" Email: s3852734@student.rmit.edu.au",
" Name: Gordon Richard",
" Student ID: s3831786",
" Email: s3831786@student.rmit.edu.au"
};

// Strings can be added at any time
//with push_back
    creditList.push_back("Add another member");

    // Print Strings stored in Vector
    for (int i = 0; i < (int) creditList.size(); ++i)
        std::cout << creditList[i] << "\n";

    cout << "-------------------------------------" << endl;
    cout << creditList[0] << endl;
    cout << creditList[1] << endl;
    cout << creditList[2] << endl;
    cout << " " << endl;
    cout << creditList[3] << endl;
    cout << creditList[4] << endl;
    cout << creditList[5] << endl;
    cout << " " << endl;
    cout << creditList[6] << endl;
    cout << creditList[7] << endl;
    cout << creditList[8] << endl;
    cout << " " << endl;
    cout << creditList[9] << endl;
    cout << creditList[10] << endl;
    cout << creditList[11] << endl;
    cout << "-------------------------------------" << endl;
}; */

int creditListFile() {
    // Source: https://www.programiz.com/cpp-programming/library-function/cstdio/fopen
    int c;
	FILE *creditListFile;
	creditListFile = fopen("credits.txt", "r");
	if (creditListFile)
	{
		while ((c = getc(creditListFile)) != EOF)
			putchar(c);
		fclose(creditListFile);
	}
	return 0;

  // char credit[100];
  // ifstream ;
  // //  string line;
  //  creditListFile.open("credits.txt");
  //  creditListFile >> credit;
  //   cout << "open the file" << endl;
  //  cout << credit << endl;
  //  creditListFile >> credit;
  //  cout << credit << endl;
  //   cout << "display" << endl;
  //  creditListFile.close();
  //  return;

//   fstream creditListFile;
//   creditListFile.open("credits.txt", ios::in);
//   if (!creditListFile) {
//     cout << "No such file";
//   } else {
//     char credits;

//     while (1) {
//       creditListFile >> credits;
//       if (creditListFile.eof())
//         break;

//       cout << credits << endl;
//     }
//   }
//   creditListFile.close();
//   return 0;
};

int main() {
  int selected = -1;
  while ((selected = mainMenu()) != 4) {
    if (selected < 1 || selected > 4) {
      cout << "Sorry, that's not a valid choice." << endl;
    } else if (selected == 1) {
      cout << "Starting a New Game" << endl;
    } else if (selected == 2) {
      cout << "Enter the filename from which to load a game" << endl;
    } else if (selected == 3) {
      cout << "The Team!" << endl;
      // credits();
      creditListFile();
    } else if (selected == 4) {
      cout << "Quit" << endl;
      // this function will redisplay the menu until 4 Quit is selected
      start();
    } else {
      cout << "Sorry, that's not a valid choice." << endl;
    }
  }

  return 0;
}
