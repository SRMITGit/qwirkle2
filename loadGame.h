#include <string>
#include <iostream>

#define ARRAY_SIZE 108

class loadGame
{
public:
    loadGame();

    ~loadGame();
    void readFile();

    char getArrBag(int num);

private:
    std::string read;
    std::string fileName;
    char arrBag[ARRAY_SIZE];

};