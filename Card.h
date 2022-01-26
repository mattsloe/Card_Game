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
  Card(std::string name="Default Name",std::string description="description");
  Card(const Card&);
  virtual ~Card();
  
  virtual int play() =0;
  virtual int display()const =0;
  int displayCardInfo()const;
  
protected:
  std::string name;
  std::string description;
  
private:
  
};

class Attack_Card: public Card
{
public:
  Attack_Card(std::string name="default",std::string description="description",
              int atkValue = 0);
  Attack_Card(const Attack_Card&);
  ~Attack_Card();
  
  int play();
  int display()const;
  
protected:
  int atkValue;
  
private:
};

class Defense_Card: public Card
{
public:
  Defense_Card(std::string name="default",std::string description="description",
               int defValue = 0);
  Defense_Card(const Defense_Card&);
  ~Defense_Card();
  
  int play();
  int display()const;
  
protected:
  int defValue;
  
private:
};

class Spell_Card: public Card
{
public:
  Spell_Card(std::string name="default",std::string description="description",
             int atkValue = 0, int defValue=0, int hpValue=0);
  Spell_Card(const Spell_Card&);
  ~Spell_Card();
  
  int play();
  int display()const;
  
protected:
  int atkValue;
  int defValue;
  int hpValue;
  
private:
};

#endif /* Card_h */
