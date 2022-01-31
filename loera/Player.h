//
//  Player.h
//  Card_Game
//  This is the header for the Player class. The Player is the interface
//  that is used by the client to play the game.
//    1) Create a player. They will handle the deck and cards by themself.
//    2) When it's the Player's turn, call playTurn();
//    3) Call attackOpponent(opponentPlayer); to initiate attack
//    4) Check this Player's isAlive() and the opponent's isAlive()
//          o if both are dead, its a draw
//          o if one is not alive, the other player wins
//    5) Continue to next Player's turn
//  Created by Matt Loera on 1/19/22.
//

#ifndef Player_h
#define Player_h

#include "Counter.h"
#include "Player_Deck.h"
#include <string>
/*This is the amount of HP a player starts with*/
const int LIFELINE = 5;
class Player
{
public:
  Player();
  Player(const Player&);
  ~Player();
  
  int isAlive();
  int playTurn(); //draw cards, play 1, hold 1, discard rest
  
//  int displayCards();
//  int chooseCards(int playCard, int holdCard);
  
  //Client uses this to initiate an attack on the referenced Player.
  //this Player will attack with ATK amount against referenced Player
  int attackOpponent(const Player&);
  //interface for use by Player
  int attack(int);  //get attacked for int amount
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
