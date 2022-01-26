//
//  Test.h
//  Card_Game
//
//  Created by Matt Loera on 1/20/22.
//

#ifndef Test_h
#define Test_h

#include <iostream>
#include "Card.h"
#include "Card_Loader.h"
#include <vector>

void testCard()
{
  //create instances of default cards
  std::cout << "Create instances of default cards" << std::endl;
  Attack_Card atkCard;
  Defense_Card defCard;
  Spell_Card splCard;
  
  std::cin.get();
  system("clear");

  
  //display the cards
  std::cout << "Display the cards." << std::endl;
  atkCard.display();
  defCard.display();
  splCard.display();
  
  std::cin.get();
  system("clear");
  
  //play the cards
  std::cout << "Play the cards." << std::endl;
  atkCard.play();
  defCard.play();
  splCard.play();
  
  std::cin.get();
  system("clear");
  
  //create some initialized cards and display
  std::cout << "create initialized cards" << std::endl;
  Attack_Card atk("Attacker","This is an attack card",10);
  atk.display();
  Defense_Card def("Defender","This is a defense card",9);
  def.display();
  Spell_Card spl("Effect","This is a spell card",1,2,3);
  spl.display();
}

void testLoadCard()
{
  vector<Card*> cardDeck;
  if(loadFromFile(cardDeck)){
    std::cout << "Loaded successfully" << std::endl;
  }else{
    std::cout << "Error loading deck" << std::endl;
  }
  
  //print the deck
  for(const auto& aCard:cardDeck){
    aCard->display();
  }
}


void testCounter()
{
  
}

void testPlayer()
{
  
}

void testDeck()
{
  
}


#endif /* Test_h */
