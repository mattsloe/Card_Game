//
//  Player_Deck.cpp
//  Card_Game
//
//  Created by Matt Loera on 1/27/22.
//

#include "Player_Deck.h"
#include "Card_Loader.h" //to load the deck from file.
#include <iostream>

//calls loadFromFile(deck), draw 3 cards
Player_Deck::Player_Deck()
{
  init();
}

Player_Deck::~Player_Deck()
{
  //rm all Card memory
  for(auto i:deck){
    delete i;
  }
}

int Player_Deck::drawHand()
{
  //draw 3
  for(int i=0; i<3; i++){
    hand.push_back(deck[rand()%deck.size()]);
  }
  return 1;
}

int Player_Deck::display()const
{
  for(int i=0; i<hand.size();i++){
    std::cout << "[" << i+1 << "]";
    hand[i]->display();
  }
  return 1;
}

Card* Player_Deck::chooseCards()
{
  int choice = -1;
  display();
  //prompt for one card to play
  std::cout << "Pick one card to play: ";
  while(choice < 0 || choice >= hand.size()){ //check user input range
    std::cin >> choice;
  }
  
    //Save this card to return to calling object
  Card* cardToPlay = (hand[choice]);
    //erase the card from hand
  hand.erase(hand.begin()+choice);
  
  //prompt for one card to hold
  display();
  choice = -1; //reset user choice
  std::cout << "Pick one card to hold: ";
  while(choice < 0 || choice >= hand.size()){
    std::cin >> choice;
  }
  Card* tmp = hand[choice];
  hand.clear();
  hand.push_back(tmp);
    //discard the rest
  
  std::cout << "Holding:\n";
  display();
  return cardToPlay;
}

int Player_Deck::init()
{
  loadFromFile(deck);
    //draw a card from deck into hand
  hand.push_back(deck[rand()%deck.size()]);
  
  return 1;
}
