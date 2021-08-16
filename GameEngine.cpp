//
//  GameEngine.cpp
//  Qwirkle
//
//  Created by Philip Beeby on 18/7/21.
//

#include"GameEngine.h"
#include <iostream>
#include <string>

GameEngine::GameEngine(Player player1, Player player2){
    std::cout << "Creating a new GameEngine Object: " << std::endl;
    std::cout << "Using existing Player Object: " << std::endl;
    // this->player1 = player1.;
    // this->player2 = new Player(player_2_name);
    std::cout << "Creating a game bag: " << std::endl;
    this->gameTileBag = new Bag();
    std::cout << "Adding Tiles to the game bag: " << std::endl;
    // Bag * newBag = new Bag();
    gameTileBag -> addTilesToBag(gameTileBag);

}

GameEngine::GameEngine(std::string player_1_name, std::string player_2_name){
    // constructor
    std::cout << "Creating a new GameEngine Object: " << std::endl;
    std::cout << "Creating a new Player Object: " << std::endl;
    this->player1 = new Player(player_1_name);
    this->player2 = new Player(player_2_name);
    std::cout << "Creating a game bag: " << std::endl;
    this->gameTileBag = new Bag();
    std::cout << "Adding Tiles to the game bag: " << std::endl;
    // Bag * newBag = new Bag();
    gameTileBag -> addTilesToBag(gameTileBag);




}
GameEngine::~GameEngine(){
    // destructor
    std::cout << "Deleting GameEngine Object and Attributes: " << std::endl;
    delete player1;
    delete player2;
    delete gameTileBag;


}
// void GameEngine::setName(std::string name){
//     // update the GameEngine name (prolly won't need this)
//     *(this->name) = name;
    
// }
// void GameEngine::setGameEngineID(std::string GameEngineID){
//     // update the GameEngineID (prolly won't need this)
//     *(this->GameEngineID) = GameEngineID;
    
// }
// void GameEngine::setEmail(std::string email){
//     // update the GameEngine email (prolly won't need this)
//     *(this->email) = email;
    
// }
// std::string GameEngine::getName(){
//     return *name;
    
// }
// std::string GameEngine::getGameEngineID(){
//     return *GameEngineID;
    
// }
// std::string GameEngine::getEmail(){
//     return *email;
    
// }

// void GameEngine::printGameEngineDetails(){
//     // print out all of the attributes of a GameEngine
//     std::cout << "Name: " << getName() << std::endl;
//     std::cout << "GameEngine ID: " << getGameEngineID() << std::endl;
//     std::cout << "Email: " << getEmail() << std::endl;
    
// }