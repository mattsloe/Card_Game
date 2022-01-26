//
//  Player_Deck.h
//  Card_Game
//
//  Created by Matt Loera on 1/19/22.
//

#ifndef Player_Deck_h
#define Player_Deck_h
#include "Card.h"
#include <vector>

class Player_Deck
{
public:
  Player_Deck();
  Player_Deck(const Player_Deck&);
  ~Player_Deck();
  
  int drawHand()const;
  int display()const;
  int chooseCards(int playCard,int holdCard);
  
protected:
 // Card holdCard;
  //Card rng_card[3];
  std::vector<Card> drawCards;
  
private:
};

#endif /* Player_Deck_h */
