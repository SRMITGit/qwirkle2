#ifndef ASSIGN2_USERPROMPT_H
#define ASSIGN2_USERPROMPT_H

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

// These chars add the User Prompt after the menu (Section 2.4)
#define SIGN char('>')
#define SPACE char(' ')

class UserPrompt {
public:
  UserPrompt();
  ~UserPrompt();
  void userPrompt();
   void helpPrompt();
 
};

#endif // ASSIGN2_USERPROMPT_H