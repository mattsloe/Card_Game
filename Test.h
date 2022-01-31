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
#include "Counter.h"
#include "Player_Deck.h"
#include <vector>
#include "Player.h"

using namespace std;

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
 //create a counter
  Counter aCounter;
  aCounter.display();
  
//increment it
  aCounter.increment();
  
//display it
  aCounter.display();
  //decrement it
  aCounter.decrement(3);
  cout << "Decrement by 3\n";
  //display it
  cout << "Should be 0: ";
  aCounter.display();
  
  //create a copy
  aCounter.increment(5);
  Counter bCounter(aCounter);
  cout << "\n Incrementing by 5 and Creating a copy.\n";
  cout << "Should be 5: ";
  bCounter.display();
  
  //create an initialized
  cout << "\nCreating Initialized counter to 99\n";
  Counter cCounter(99);
  cout << "Should be 99: ";
  cCounter.display();
  cout <<"\nCreating Initialized to -99\n";
  Counter dCounter(-99);
  cout << "Should be 0: ";
  dCounter.display();
}

void testPlayer()
{
  //create a player
  Player player1;
  
  //create opponent
  Player player2;
  
  //create references to players
  Player* curPlayer = &player1;
  Player* opponent = &player2;
  //try out playing a turn
  while(player1.isAlive() && player2.isAlive()){
    curPlayer->playTurn(*(opponent));
    
    //switch player pointers
    Player* tmp = opponent;
    opponent = curPlayer;
    curPlayer = tmp;
    
  }
  if(!player1.isAlive() && !player2.isAlive()){
    cout << "It's a draw!" << endl;
  }
  if(player1.isAlive()) cout << "Player 1 wins." << endl;
  if(player2.isAlive()) cout << "Player 2 wins." << endl;
  
}

void testDeck()
{
  Player_Deck aDeck;
  aDeck.display();
  
  cout << "Drawing a hand.\n";
  aDeck.drawHand();
//  aDeck.display();
  Card* toPlay = aDeck.chooseCards();
  toPlay->display();
  toPlay->play();
  
  
  
}


#endif /* Test_h */
