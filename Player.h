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

#include <string>
#include "Player_Deck.h"
#include "Counter.h"

/*This is the amount of HP a player starts with*/
const int LIFELINE = 20;
class Player
{
public:
  Player();
  Player(const Player&);
  ~Player();
  
  //@post returns true if player is still alive
  int isAlive()const;
  

  int playTurn(Player& opponent);
  
  //interface for use by Player
  int attack(int);  //get attacked for int amount
  //interface for use by Card
  int boostATK(int);
  int boostDEF(int);
  int boostHP(int);
  
private:
  
protected:
  //std::string name;
  Counter atkCounter;
  Counter defCounter;
  Counter hpCounter;
  Player_Deck deck;
  
  int displayStats()const;
  
  //Client uses this to initiate an attack on the referenced Player.
  //this Player will attack with ATK amount against referenced Player
  //@post: return hp of opponent
  int attackOpponent(Player&);
  
  //cancels out attack amount 'point-for-point' with any DEF this
  //Player has.
  //@post returns attack amount less DEF, decrements DEF by attack
  //      amount
  int attackDefenses(int);
  
};

#endif /* Player_h */
