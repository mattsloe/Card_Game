//
//  Player.cpp
//  Card_Game
//
//  Created by Matt Loera on 1/27/22.
//

#include "Player.h"
#include <iostream>


Player::Player()
:atkCounter(),defCounter(),hpCounter(LIFELINE)
{}

Player::Player(const Player& toCopy)
:atkCounter(toCopy.atkCounter),defCounter(toCopy.defCounter),hpCounter(toCopy.hpCounter)
{} //Does not copy the deck yet. Implement later if needed.

Player::~Player()
{}

//for getting attacked by another player for atkAmount 
int Player::attack(int atkAmount)
{
  //use DEF first to counter atkAmt
  atkAmount = attackDefenses(atkAmount);
  hpCounter.decrement(atkAmount);
  return hpCounter.getCount();
}

int Player::isAlive()const
{
  if(hpCounter.getCount()) return 1;
  return 0;
}

int Player::playTurn(Player& opponent)
{
  //display stats
  displayStats();
  
  //draw phase
  deck.drawHand();
  //choose phase
  Card* toPlay = deck.chooseCards();
  //Play the chosen card
  /**This is ugly and I hate it but I learned a lot**/
  if(dynamic_cast<Attack_Card*>(toPlay)){
    //play atk card
    boostATK(toPlay->play());
  }else if(dynamic_cast<Defense_Card*>(toPlay)){
    //play def card
    boostDEF(toPlay->play());
  }else if(dynamic_cast<Spell_Card*>(toPlay)){
    //play spell card
    //how to do that with only a returned int??
    int* stats = new int[3];
    Spell_Card* t =dynamic_cast<Spell_Card*>(toPlay);
    t->getStats(stats);
    boostATK(stats[0]);
    boostDEF(stats[1]);
    boostHP(stats[2]);
    
  }else{
    std::cout << "DYNAMIC CAST ERROR!" << std::endl;
  }
  //attack opponent
  displayStats();
  std::cout << "ENTER to attack Opponent for " << atkCounter.getCount() << "...";
  std::cin.ignore(1000,'\n'); std::cin.get();
  attackOpponent(opponent);
  return 1;
}

int Player::attackOpponent(Player & enemy)
{
  
  //attack opponent
  enemy.attack(atkCounter.getCount());
  //clear ATK points
  atkCounter.reset();
  return 1;
}

int Player::boostATK(int amt)
{
  atkCounter.increment(amt);
  return atkCounter.getCount();
}

int Player::boostDEF(int amt)
{
  defCounter.increment(amt);
  return defCounter.getCount();
}

int Player::boostHP(int amt)
{
  hpCounter.increment(amt);
  return hpCounter.getCount();
}

int Player::displayStats()const
{
  using namespace std;
  cout << "[ATK:"; atkCounter.display(); cout <<"]";
  cout << "[DEF:"; defCounter.display(); cout <<"]";
  cout << "[Lifeline:"; hpCounter.display(); cout <<"]\n";
  return 1;
}

int Player::attackDefenses(int atkAmt)
{
  //get defense amount
  int def = defCounter.getCount();
  //decrement DEF by atkAmt
  defCounter.decrement(atkAmt);
  //return atkAmt-former DEF
  return atkAmt-def;
}
