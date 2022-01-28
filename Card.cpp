//
//  Card.cpp
//  Card_Game
//
//  Created by Matt Loera on 1/20/22.
//
#include "Card.h"
#include <iostream>
#include <iomanip>

Card::Card(std::string _name,std::string _description)
  :name(_name),description(_description)
{
  
}

Card::Card(const Card& toCopy)
  :name(toCopy.name),description(toCopy.description)
{
  
}

Card::~Card()
{
}

//int Card::play()
//{
//  return 1;
//}

int Card::displayCardInfo()const
{
  std::cout << '[' << name << "]|" << description << '|' << std::endl;
  return 1;
}

/* *****ATTACK CARD***** */
Attack_Card::Attack_Card(std::string name,std::string description,
                         int atkValue)
  :Card(name,description),atkValue(atkValue)
{
  
}

Attack_Card::Attack_Card(const Attack_Card& toCopy)
  :Card(toCopy),atkValue(toCopy.atkValue)
{
  
}

Attack_Card::~Attack_Card()
{
  
}

int Attack_Card::play()
{
  std::cout << "Playing Attack Card\n";
  return 1;
}

int Attack_Card::display()const
{
//  std::cout << "==================================================\n";
  Card::displayCardInfo();
  std::cout << std::setw(30)<< std::right <<"Attack: +" << atkValue;
  return 1;
}

/* *****DEFENSE CARD***** */
Defense_Card::Defense_Card(std::string name,std::string description,
                           int defValue)
  :Card(name,description),defValue(defValue)
{
  
}

Defense_Card::Defense_Card(const Defense_Card& toCopy)
  :Card(toCopy),defValue(toCopy.defValue)
{
  
}

Defense_Card::~Defense_Card()
{
  
}

int Defense_Card::play()
{
  std::cout << "Playing Defense Card." << std::endl;
  return 1;
}

int Defense_Card::display()const
{
//  std::cout << "==================================================\n";
  Card::displayCardInfo();
  std::cout << std::setw(30)<< std::right <<"Defense: +" << defValue;
  return 1;
}

/* *****SPELL CARD***** */
Spell_Card::Spell_Card(std::string name,std::string description,
                       int atkValue,int defValue,int hpValue)
  :Card(name,description),atkValue(atkValue),defValue(defValue),hpValue(hpValue)
{
  
}

Spell_Card::Spell_Card(const Spell_Card& toCopy)
  :Card(toCopy),atkValue(toCopy.atkValue),defValue(toCopy.defValue),
   hpValue(toCopy.hpValue)
{
  
}

Spell_Card::~Spell_Card()
{
  
}

int Spell_Card::play()
{
  std::cout << "Casting Spell Card" << std::endl;
  return 1;
}

int Spell_Card::display()const
{
//  std::cout << "==================================================\n";
  Card::displayCardInfo();
  if(atkValue) std::cout<< std::right<< std::setw(30)<< "Attack: " << atkValue << std::endl;
  if(defValue) std::cout<< std::right<< std::setw(30)<< "Defense: " << defValue << std::endl;
  if(hpValue) std::cout<<  std::right<< std::setw(30)<<"Healing: " << hpValue << std::endl;
  return 1;
}
