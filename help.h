#ifndef ASSIGN2_HELP_H
#define ASSIGN2_HELP_H

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Help {
public:
  // default constructor
  Help();
  // default destructor
  ~Help();
  // copy constructor
  Help(Help &other);

  void displayHelp();
  void printHelp();

  void helpList();
  std::string helpText;
  void addToEndHelpList(std::string helpText);
  std::string helpPoint;
  Help *next;

  // int helpPrompt();

  // // Getters and setters
  // std::string getHelpText();
  // void setHelpText();

private:
  // these have to be pointers so we can create class attributes on the heap
  Help *head, *tail, *current, *temp;
};

#endif // ASSIGN2_HELP_H
