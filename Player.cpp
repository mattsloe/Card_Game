//
//  Player.cpp
//  Card_Game
//
//  Created by Matt Loera on 1/27/22.
//

#include "Player.h"

Player::Player()
{}

Player::Player(const Player& toCopy)
{}

Player::~Player()
{}

//for getting attacked by another player for atkAmount 
int Player::attack(int atkAmount)
{
  return hpCounter.getCount();
}

int Player::isAlive()
{
  return 1;
}

int Player::playTurn()
{
  return 1;
}

int Player::chooseCards(int playCard, int holdCard)
{
  return 1;
}

int Player::attackOpponent(const Player & enemy, int ATK)
{
  return 1;
}

int Player::boostATK(int amt)
{
  return atkCounter.getCount();
}

int Player::boostDEF(int amt)
{
  return defCounter.getCount();
}

int Player::boostHP(int amt)
{
  return hpCounter.getCount();
}
