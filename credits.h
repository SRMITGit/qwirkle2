#ifndef ASSIGN2_CREDITS_H
#define ASSIGN2_CREDITS_H

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

class Credits {
public:
  Credits();
  // Copy constructor
  Credits(Credits &other);
  // Deconstructor
  ~Credits();

  int printCredits();

private:
  Credits *credits;
};

#endif // ASSIGN2_CREDITS_H