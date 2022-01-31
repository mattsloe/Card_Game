/* 
   Author: 0x010 (Matt Loera)
   Description: This is the main driver program.
*/
#include <iostream>
#include "Player.h"
using std::cout;
using std::endl;
int main()
{
  Player player1, player2;
  Player* curPlayer = &player1;
  Player* opponent = &player2;
  
  //seed rand
  
  cout << "Welcom to THE GAME!." << endl;
  cout << "Each turn, you will get to choose 1 card to play, and " <<
          "1 card to hold for the next turn." << endl;
  cout << "PLAYER 1 get ready..." << endl;
  cout << "Press ENTER";
  std::cin.ignore(1000,'\n'); std::cin.get();
  system("clear");
  
  while(player1.isAlive() && player2.isAlive()){ //play until one is not alive
    if(curPlayer == &player1){
      cout << "======PLAYER 1======\n";
      
    }
    else{
      cout << "======PLAYER 2======\n";
      
    }
    curPlayer->playTurn(*(opponent));
    
    //switch player pointers
    Player* tmp = opponent;
    opponent = curPlayer;
    curPlayer = tmp;
    system("clear");
    
  }
  
  if(!player1.isAlive() && !player2.isAlive()){
    cout << "It's a draw!" << endl;
  }
  if(player1.isAlive()) cout << "Player 1 wins." << endl;
  if(player2.isAlive()) cout << "Player 2 wins." << endl;
  
  
  return 0;
}
