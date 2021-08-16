#include <iostream>
#include <string>
#include <vector>

// #include "vectorMenuTest.h"

// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
// using std::vector;

// template <typename T> 
// void PrintVector(const Vector<T> &vector) {
//   for (size_t i = 0; i < vector.size(); ++i) {
//     std::cout << vector[i] << std::endl;
//   }
// }

int main() {
  // LinkedList* colour = new LinkedList();
  std::vector<std::string> Items{"1. New Game", "2. Load Game", "3. Credits", "4. Quit"};

  // colour.push_back(std::move("Yellow"));
   Items.emplace_back(std::move("Yellow"));
  // an error is thrown because of the less than in: i < colour.size()
  // for (int i = 0; i < (int)Items.size(); ++i)
  for (size_t i = 0; i < Items.size(); ++i) {
    std::cout << Items[i] << std::endl;
  }
  // delete colour;

  //  PrintVector(Items);
}
