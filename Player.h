//
//  Player.h
//  Card_Game
//
//  Created by Matt Loera on 1/19/22.
//

#ifndef Player_h
#define Player_h

#include "Counter.h"
#include "Player_Deck.h"
#include <string>

class Player
{
public:
  Player();
  Player(const Player&);
  ~Player();
  
  int attack(int);  //get attacked for int amount
  int isAlive();
  int playTurn(); //draw cards, play 1, hold 1, discard rest
//  int displayCards();
  int chooseCards(int playCard, int holdCard);
  int attackOpponent(const Player&,int ATK);
  
  //interface for use by Card
  int boostATK(int);
  int boostDEF(int);
  int boostHP(int);
  
private:
  
protected:
  std::string name;
  Counter atkCounter;
  Counter defCounter;
  Counter hpCounter;
  Player_Deck deck;
  
};

#endif /* Player_h */
