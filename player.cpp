// s3831786 Gordon Richard - RMIT

#include "Player.h"
#include <ostream>

Player::Player(std::string name) { this->name = name; }
Player::~Player() {}

Player::Player(std::string name, LinkedList *hand) {
  this->name = name;
  this->hand = hand;
}

void Player::setPlayerHand(LinkedList *hand) { this->hand = hand; }
void Player::setPlayerScore(int score) { this->score = score; }
void Player::addPlayerScore(int score) { this->score += score; }

LinkedList *Player::getPlayerHand() { return hand; }

int *Player::getPlayerScorePtr() {
  int *scorePtr = &score;
  return scorePtr;
}

int Player::getPlayerScore() { return score; }

std::string Player::getPlayerName() { return name; }
std::string *Player::getPlayerNamePtr() {
  std::string *namePtr = &name;
  return namePtr;
}

void Player::printPlayerHand() { this->hand->printNodes(); }

int Player::size() { return length; }
