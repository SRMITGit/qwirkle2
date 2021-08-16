// Reference: https://www.youtube.com/watch?v=ryRf4Jh_YC0
#include <iostream>
#include <string>
#include <vector>

#include "vectorMenuTest.h"
using std::vector;

// this will print the values in the vector
// make it a Template so that any type can be accessed
template <typename T> 
void PrintVector(const Vector<T> &vector) {
  for (size_t i = 0; i < vector.size(); ++i) {
    std::cout << vector[i] << std::endl;
  }
}

class Menu_Item {
  public:
    std::string Items;
    // vector<std::string> Items{"1. New Game", "2. Load Game", "3. Credits", "4. Quit"};
    // float x = 0.0f, y = 0.0f, z = 0.0f;

    Menu_Item() {}
    // Menu_Item(float scalar) : x(scalar), y(scalar), z(scalar) {}
    // Menu_Item(float x, float y, float z) : x(x), y(y), z(z) {}
    // Menu_Item(std::string Items) {"1. New Game", "2. Load Game", "3. Credits", "4. Quit"}
    Menu_Item(std::string Items) {}
    // copy constructor
    Menu_Item(const Menu_Item& other) 
        // : x(other.x), y(other.y), z(other.z) { //, Items(other.Items)
        : Items(other.Items) {//Item1(other.Item1), Item2(other.Item2), Item3(other.Item3), Item4(other.Item4) {
            std::cout << "Copy\n";
        }

     // move constructor
    Menu_Item(Menu_Item&& other)
         // : x(other.x), y(other.y), z(other.z) { //, Items(other.Items)
        : Items(other.Items) {//Item1(other.Item1), Item2(other.Item2), Item3(other.Item3), Item4(other.Item4) {
            std::cout << "Move\n";
        }

    // copy constructor
    Menu_Item& operator = (const Menu_Item& other)
        {
            std::cout << "Copy\n";
            // x = other.x; y = other.y; z = other.z; 
            Items= other.Items;
            return *this;
        }

    // move constructor
    Menu_Item& operator = (const Menu_Item&& other)
        {
            std::cout << "Move\n";
            // x = other.x; y = other.y; z = other.z; 
            Items= other.Items;
            return *this;
        }

    // destroy constructor
    ~Menu_Item() { 
        std::cout << "Destroy\n";
    }
};

template <> 
void PrintVector(const Vector<Menu_Item> &vector) {
  for (size_t i = 0; i < vector.Size(); ++i) {
    // std::cout << vector[i].x << " ," << vector[i].y << " ," << vector[i].z << std::endl; // << " ," << vector[i].Item1 
    std::cout << vector[i].Items << std::endl; 
  }
};

int main() {
//   Vector<std::string> menuList;

Vector<Menu_Item> menuList;
  menuList.EmplaceBack(Menu_Item("1. New Game")); //"1. New Game", "2. Load Game", "3. Credits", "4. Quit"
  menuList.EmplaceBack(Menu_Item("2. Load Game"));
  menuList.EmplaceBack(Menu_Item("3. Credits"));
  menuList.EmplaceBack(Menu_Item("4. Quit"));
    // menuList.PushBack(Menu_Item(1.0f));
    // menuList.EmplaceBack(Menu_Item(2, 3, 5));
    // menuList.EmplaceBack(Menu_Item());
    menuList.PushBack(Menu_Item());
    PrintVector(menuList);
//     menuList.PopBack();
//     menuList.PopBack();
//     PrintVector(menuList);
//     menuList.EmplaceBack(Menu_Item(8, 9, 10));
//     menuList.EmplaceBack(Menu_Item(1, 7, 5));
//     menuList.EmplaceBack(Menu_Item());
//     PrintVector(menuList);
//     menuList.Clear();
//     PrintVector(menuList);
//     menuList.EmplaceBack(Menu_Item(3, 6, 9));
//     menuList.EmplaceBack(Menu_Item(2, 4, 7));

  // using cin.get requires user to hit Ctrl-D to stop the program
//   std::cin.get();
}
