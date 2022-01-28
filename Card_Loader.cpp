//
//  Card_Loader.cpp
//  Card_Game
//
//  Created by Matt Loera on 1/27/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "Card.h"

const char FILENAME[] = "data.dat";
using namespace std;

//read in an ATK card given ifstream
Attack_Card* readInATK(ifstream&);
Defense_Card* readInDEF(ifstream&);
Spell_Card* readInSPL(ifstream&);

//load deck from file
int loadFromFile(vector<Card*>& deck)
{
  cout << "...loading deck from file\n";
  ifstream infile;
  char buf[1000];
  
  infile.open(FILENAME);
  if(!infile){
    cout << "error opening file" << endl;
    return 0;
  }
  for(int i = 0; i < 3; i++){
    infile.getline(buf,1000,'\n');
  }
  
  while(infile.getline(buf,1000,'|')){
    switch(buf[0]){
      case 'A': deck.push_back(readInATK(infile));
        break;
      case 'D': deck.push_back(readInDEF(infile));
        break;
      case 'S': deck.push_back(readInSPL(infile));
        break;
      //default:
        //infile.getline(buf,1000,'\n');
    }
  }
  return 1;
}
//ALG:
//fstream instream;
//
//while(instream.getline(buf,1000,|)) //read until EOF
//switch(buf[0])
//  case 'A': readInATK(instream)
//    break;
//  case 'D': readInDEF(instream)
//    break;
//  case 'S': readInSPL(instream)
//    break;
//  default:
//    getline(buf,1000,'\n') //discard the rest of the line
Attack_Card* readInATK(ifstream& infile)
{
  char name[1000];
  char description[1000];
  int atkPts;
  
  infile.getline(name,1000,'|'); //read in name
  infile.getline(description,1000,'|'); //read in description
  infile >> atkPts; //read in atk number
  infile.ignore(100,'\n');
  
  return new Attack_Card(name,description,atkPts);
}

Defense_Card* readInDEF(ifstream& infile)
{
  char name[1000];
  char description[1000];
  int defPts;
  
  infile.getline(name,1000,'|'); //read in name
  infile.getline(description,1000,'|'); //read in description
  infile >> defPts; //read in atk number
  infile.ignore(100,'\n');
  
  return new Defense_Card(name,description,defPts);
  //return *(defPtr);
}

Spell_Card* readInSPL(ifstream& infile)
{
  char name[1000];
  char description[1000];
  int atkPts, defPts, hpPts;
  
  infile.getline(name,1000,'|'); //read in name
  infile.getline(description,1000,'|'); //read in description
  infile >> atkPts >> defPts >> hpPts; //read in numbers
  infile.ignore(100,'\n');
  
  return new Spell_Card(name,description,atkPts,defPts,hpPts);
}
