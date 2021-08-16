#ifndef ASSIGN2_CREDITS_H
#define ASSIGN2_CREDITS_H

class Credits {
public:
  Credits();
  // Copy constructor
  Credits(Credits &other);
  // Move constructor
  Credits(Credits &&other);
  // Deconstructor
  ~Credits();

  int printCredits();

private:
  Credits *credits;
};

#endif // ASSIGN2_CREDITS_H