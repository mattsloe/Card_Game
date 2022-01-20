//
//  Card.h
//  Card_Game
//
//  Created by Matt Loera on 1/19/22.
//

#ifndef Card_h
#define Card_h

#include <string>

class Card
{
public:
  Card();
  Card(const Card&);
  ~Card();
  
  int play();
  int display()const;
  
protected:
  std::string name;
  std::string description;
  
private:
  
};

class Attack_Card: public Card
{
public:
  Attack_Card();
  Attack_Card(const Attack_Card&);
  ~Attack_Card();
  
protected:
  int atkValue;
  
private:
};

class Defense_Card: public Card
{
public:
  Defense_Card();
  Defense_Card(const Defense_Card&);
  ~Defense_Card();
  
protected:
  int defValue;
  
private:
};

class Spell_Card: public Card
{
public:
  Spell_Card();
  Spell_Card(const Spell_Card&);
  ~Spell_Card();
  
protected:
  int atkValue;
  int defValue;
  int hpValue;
  
private:
};

#endif /* Card_h */
