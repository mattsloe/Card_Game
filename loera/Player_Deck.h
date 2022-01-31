//
//  Player_Deck.h
//  Card_Game
//  The Player Deck manages the player's hand. It must always be init
//  with a deck of cards to start the draw pile.
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
  ~Player_Deck();
  
  int drawHand();
  int display()const;
  //@pre Deck must be at the end of the draw phase. hand should have 4 elements
  //@post hand will have 1 card in it. Returns reference to a card to be played
  //      By the calling object
  Card* chooseCards();
  
protected:
 // There are always 3 cards in the players hand. 1 Card gets drawn at the
// beginning of the turn. Player chooses 1 of 4 cards to play. That card
// gets popped, played, and discarded.
  std::vector<Card*> hand;
  std::vector<Card*> deck;
  
  int init();
  
private:
};

#endif /* Player_Deck_h */
