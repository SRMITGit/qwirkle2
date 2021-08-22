/* The helpful tips for help.txt were sourced from
Ultra BoardGames n.d., Tips to win Qwirkle | UltraBoardGames,
www.ultraboardgames.com, viewed 18 August 2021,
<https://www.ultraboardgames.com/qwirkle/tips.php>. */
#include "help.h"
#include "tileColours.h"
#include "tileEmoji.h"
#include "userPrompt.h"

Help::Help() {}
Help::~Help() {}

void Help::displayHelp() {
  std::vector<std::string> helpText;
  helpText.emplace_back("You can score double points when you add a tile "
                        "that forms more than one line.");
  helpText.emplace_back(
      "Try not to make a line of 5 tiles because your opponents will "
      "add the 6th tile and score the bonus Qwirkle.");
  helpText.emplace_back("When you have an identical pair of tiles in your "
                        "deck, i.e. two circles, try to play them asap.");
  helpText.emplace_back("You can use small two-tile combos to block your "
                        "opponent's attempt for a Qwirkle.");

  // Print Strings stored in Vector
  std::cout << YELLOW_TEXT << " Help " << RESET_COLOUR << MEMO << std::endl;
  std::cout << "-------" << std::endl;
  for (const std::string &helpPoint : helpText) {
    std::cout << helpPoint << std::endl;
  }
};

// ---------------------------------------------------------------
/* int Help::displayHelp() {
  UserPrompt userPrompt;
  std::string help;
  std::ifstream file("help.txt");
  try {
    if (file.is_open()) {
      while (std::getline(file, help) && !file.eof()) {
        std::cout << help << std::endl;
      }
      file.close();
      userPrompt.userPrompt();
    } else {
      throw std::runtime_error("Could not open file");
    }
  } catch (std::exception &e) {
    std::cerr << "Oops, something went wrong! \n" << e.what() << "\n";
  }
  return EXIT_SUCCESS;
}; */

// void Help::helpList() {
//   this->head = nullptr;
//   this->tail = nullptr;
//   this->current = nullptr;
// };

// void Help::addToEndHelpList(std::string helpText) {
//   Help *temp = new Help();
//   temp->helpPoint = helpText;
//   temp->next = nullptr;

//   if (this->head == nullptr) {
//     this->head = temp;
//     this->tail = temp;
//   } else {
//     this->tail->next = temp;
//     this->tail = this->tail->next;
//   }
// };

// void Help::printHelp() {
//   if (this->head != nullptr) {
//     Help *temp = head;
//     while (temp->next != nullptr) {
//       std::cout << temp->helpPoint << std::endl;
//       temp = temp->next;
//     }
//     std::cout << temp->helpPoint << std::endl;
//   } else {
//     return;
//   }
// };
//
// std::string Help::getHelpText() { return *helpText; }

// Help::~Help() {
//   std::cout << "Deleting helpPoint maybe " << std::endl;
//   delete helpPoint;
// }

// Help::Help(std::string helpText) {
//   // default contructor
//   this->helpText = new std::string(helpText);
// }

//
//  Student.cpp
//  Qwirkle
//
//  Created by Philip Beeby on 18/7/21.
//

// #include "Student.h"
// // #include <iostream>
// // #include <string>

// Student::Student() {
//   // default contructor
//   this->name = new std::string("default_name");
//   this->studentID = new std::string("default_StdID");
//   this->email = new std::string("default_email");
// }

// Student::Student(std::string name, std::string studentID, std::string email)
// {
//   // constructor
//   std::cout << "Creating a new Student Object: " << std::endl;
//   this->name = new std::string(name);
//   this->studentID = new std::string(studentID);
//   this->email = new std::string(email);
// }
// Student::~Student() {
//   // destructor
//   std::cout << "Deleting Student Object and Attributes: " << std::endl;
//   delete name;
//   delete studentID;
//   delete email;
// }
// void Student::setName(std::string name) {
//   // update the student name (prolly won't need this)
//   *(this->name) = name;
// }
// void Student::setstudentID(std::string studentID) {
//   // update the studentID (prolly won't need this)
//   *(this->studentID) = studentID;
// }
// void Student::setEmail(std::string email) {
//   // update the student email (prolly won't need this)
//   *(this->email) = email;
// }
// std::string Student::getName() { return *name; }
// std::string Student::getstudentID() { return *studentID; }
// std::string Student::getEmail() { return *email; }

// void Student::printStudentDetails() {
//   // print out all of the attributes of a student
//   std::cout << "Name: " << getName() << std::endl;
//   std::cout << "Student ID: " << getstudentID() << std::endl;
//   std::cout << "Email: " << getEmail() << std::endl;
// }