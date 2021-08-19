#ifndef ASSIGN2_HELP_H
#define ASSIGN2_HELP_H

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

class Help {
public:
  // default constructor
  Help();
  // default destructor
  ~Help();
  // copy constructor
  Help(Help &other);

  void helpList();
  void addToEndHelpList(std::string helpText);
  std::string helpText;
  Help *next;

  Help(std::string helpText);

  // int displayHelp();
  void displayHelp();
  int helpPrompt();

  // void printHelp();

  // Getters and setters
  std::string getHelpText();
  void setHelpText();

private:
  // these have to be pointers so we can create class attributes on the heap
  Help *helpPoint, *head, *tail, *current, *temp;
};

// class Student {
// public:
//   // default constructor
//   Student();
//   // constructor
//   Student(std::string name, std::string studentID, std::string email);
//   // destructor
//   ~Student();
//   // copy constructor
//   Student(Student &other);
//   // setters
//   void setName(std::string name);
//   void setstudentID(std::string studentID);
//   void setEmail(std::string email);

//   // getters
//   std::string getName();
//   std::string getstudentID();
//   std::string getEmail();
//   // other
//   void printStudentDetails();

// private:
//   // these have to be pointers so we can create class attributes on the heap
//   std::string *name;
//   std::string *studentID;
//   std::string *email;
// };

#endif // ASSIGN2_HELP_H
