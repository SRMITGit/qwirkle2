// #include "LinkedList.h"

#include <iostream>
#include "menu.h"
#include "credits.h"
#include "Tile.h"
#include "TileCodes.h"
#include "Student.h"
#include "LinkedList.h"
#include "Bag.h"
#include "Player.h"
#include "board.h"

#define MAX_BAG_TILES 108

// #define EXIT_SUCCESS    0

void testTileCreation();
void testLinkedListCreation();
void testStudentCreation();
void playerTest();

int main(void)
{
    //begin test of the board

    // Board *board = new Board(26, &std::cout);
    // board->display();
       

    Menu selectionMenu;
    std::cout << "Welcome to Qwirkle!" << std::endl;
    std::cout << "-------------------" << std::endl;
    //START run tests
    // this is how you can create a new bag at the start of the game

    // Bag *newBag = new Bag();
    // Tile *redSquare = new Tile(RED, SQUARE);
    // std::cout << "Add Node to the Back and then Print out the Linked List " << std::endl;
    // newBag->addBack(redSquare);
    // std::cout << "Size of the Linked list is: " << newBag->listSize() << std::endl;
    // newBag->addTilesToBag(newBag);
    // newBag->printNodes();
    // // delete redSquare;
    // delete newBag;
    // delete board;
 

    // testTileCreation();
    // testStudentCreation();
    // testLinkedListCreation();
    // playerTest();
    // END tests

    selectionMenu.selectionMenu();

    // these are tests so please un/comment as needed
    // need to include

    return EXIT_SUCCESS;
}

void testTileCreation()
{
    // testing the creation of a new tile
    std::cout << "Creating a new Tiles" << std::endl;
    std::cout << "Creating a new Tiles" << std::endl;
    Tile *redCircle = new Tile(RED, CIRCLE);
    Tile *orange4Star = new Tile(ORANGE, STAR_4);
    Tile *yellowDiamond = new Tile(YELLOW, DIAMOND);
    Tile *green6Star = new Tile(GREEN, SQUARE);
    Tile *blueSquare = new Tile(BLUE, STAR_6);
    Tile *purpleClover = new Tile(PURPLE, CLOVER);
    std::cout << "New Tile 1 Created: Red Circle: " << redCircle->getTileColour() << redCircle->getTileShape() << std::endl;
    std::cout << "New Tile 2 Created: Orange 4 Star: " << orange4Star->getTileColour() << orange4Star->getTileShape() << std::endl;
    std::cout << "New Tile 3 Created: Yellow Diamon: " << yellowDiamond->getTileColour() << yellowDiamond->getTileShape() << std::endl;
    std::cout << "New Tile 4 Created: Green 6 Star: " << green6Star->getTileColour() << green6Star->getTileShape() << std::endl;
    std::cout << "New Tile 5 Created: Blue  Square: " << blueSquare->getTileColour() << blueSquare->getTileShape() << std::endl;
    std::cout << "New Tile 6 Created: Purple Clover: " << purpleClover->getTileColour() << purpleClover->getTileShape() << std::endl;
    // memory clean up
    delete redCircle;
    delete orange4Star;
    delete yellowDiamond;
    delete green6Star;
    delete blueSquare;
    delete purpleClover;
}

void testStudentCreation()
{
    std::cout << "TODO: Implement Qwirkle soon!!" << std::endl;
    //Student Testing - can move this test somewhere else when the time comes
    // testing that we can create a new student
    std::cout << "Creating a new Test Student 01" << std::endl;
    Student *phil = new Student("Philip Beeby", "S3666628", "s3666628@student.rmit.edu.au");
    std::cout << "Printing out Test Student 01 -  name: " << phil->getName() << std::endl;
    std::cout << "Printing out Test Student 01 -  StudentID: " << phil->getstudentID() << std::endl;
    std::cout << "Printing out Test Student 01 -  email: " << phil->getEmail() << std::endl;
    std::cout << "Updating details of Test Student 01 to test Setter methods" << std::endl;
    phil->setName("Paul");
    phil->setstudentID("S366225");
    phil->setEmail("paul.beeby@mac.com.au");
    std::cout << "Printing out the student details" << std::endl;
    phil->printStudentDetails();
    std::cout << "Deleting Test Student 01 from Heap: " << std::endl;
    delete phil;
}
void testLinkedListCreation()
{
    // testing the creation of a new tile
    LinkedList *list = new LinkedList();
    list->removeFront();
    std::cout << "Size of the list at start of testing is: " << list->listSize() << std::endl;
    Tile *purpleDiamond = new Tile(PURPLE, DIAMOND);
    Tile *orangeDiamond = new Tile(ORANGE, DIAMOND);
    Tile *redSquare = new Tile(RED, SQUARE);
    std::cout << "Size of the Linked list is: " << list->listSize() << std::endl;
    std::cout << "Add Node to the Back and then Print out the Linked List " << std::endl;
    list->addBack(purpleDiamond);
    std::cout << "Size of the Linked list is: " << list->listSize() << std::endl;
    list->printNodes();
    std::cout << "Add Node to the Front and then Print out the Linked List " << std::endl;
    list->addFront(orangeDiamond);
    std::cout << "Size of the Linked list is: " << list->listSize() << std::endl;
    list->printNodes();
    std::cout << "Add Node to the Front Again and then Print out the Linked List " << std::endl;
    list->addFront(redSquare);
    std::cout << "Size of the Linked list is: " << list->listSize() << std::endl;
    list->printNodes();
    std::cout << "Remove Node From the Front and then Print out the Linked List " << std::endl;
    list->removeFront();
    std::cout << "Size of the Linked list is: " << list->listSize() << std::endl;
    list->printNodes();

    //     list->addBack(redSquare);
    //     list->addFront(redSquare);
    //     list->printNodes();
    std::cout << "Get details of tiles in zero position in the Linked List: " << list->listSize() << std::endl;
    Tile tileAtZero = list->get(0);
    std::cout << "Colour of the tile: " << tileAtZero.getTileColour() << std::endl;
    std::cout << "Shape of the tile: " << tileAtZero.getTileShape() << std::endl;
    std::cout << "Clearing the Linked List of all nodes: " << list->listSize() << std::endl;
    list->clear();
    std::cout << "Printing the list post clearing: " << list->listSize() << std::endl;
    list->printNodes();
    std::cout << "Adding purpleDiamond to the back: " << list->listSize() << std::endl;
    list->addBack(purpleDiamond);
    std::cout << "Adding redSquare to the front: " << list->listSize() << std::endl;
    list->addFront(redSquare);
    list->printNodes();
    std::cout << "Removing purpleDiamond from the back: " << list->listSize() << std::endl;
    list->removeBack();
    list->printNodes();
    std::cout << "Removing RedSquare from the back: " << list->listSize() << std::endl;
    list->removeBack();
    list->printNodes();
    std::cout << "Removing from the back when list is Empty: " << list->listSize() << std::endl;
    list->removeBack();
    list->printNodes();
    std::cout << "Adding purpleDiamond to the back: " << list->listSize() << std::endl;
    list->addBack(purpleDiamond);
    list->printNodes();
    std::cout << "Removing from the back when list has ONE element: " << list->listSize() << std::endl;
    list->removeBack();
    list->printNodes();

    delete list;
}

// test function for the player object - Gordon Richard s3831786
void playerTest()
{

    std::cout << "Begin test of get methods" << std::endl;

    // test - creating new Player object and passing a string to act as playerName ( todo: implement function Player-> getPlayerName)
    Player *testPlayer = new Player("Banana");
    std::cout << "The players name: " << testPlayer->getPlayerName() << std::endl;
    // test - printing out the score value
    std::cout << "Current score: " << testPlayer->getPlayerScore() << std::endl;
    // test - printing the player's hand
    std::cout << "The player's hand: " << testPlayer->getPlayerHand() << std::endl;
    std::cout << "Begin test of set methods" << std::endl;
    // test - setting playerScore
    testPlayer->setPlayerScore(999);
    std::cout << "Current score after setting (expect 999): " << testPlayer->getPlayerScore() << std::endl;
    //incrementing the score by the value 2
    testPlayer->addPlayerScore(2);
    std::cout << ("New score after adding 2 points (expect 1001): ") << testPlayer->getPlayerScore() << std::endl;

    delete testPlayer;
}
