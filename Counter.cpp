//
//  Counter.cpp
//  Card_Game
//
//  Created by Matt Loera on 1/27/22.
//

#include "Counter.h"
#include <iostream>

Counter::Counter(const Counter& toCopy)
  :count(toCopy.count),_default(toCopy._default)
{}

Counter::Counter(int inCount)
  :count(inCount),_default(inCount)
{
  if(inCount < 0){
    count = 0;
    _default = 0;
  }
}

Counter::~Counter()
{}

//increments
int Counter::increment(int amount)
{
  
  count += amount;
  if(count<0) count = 0;
  return 1;
}

//decrements. if result < 0, sets to 0
int Counter::decrement(int amount)
{
  count -= amount;
  if(count<0) count = 0;
  return 1;
}

//returns count
int Counter::getCount()const
{
  return count;
}

int Counter::display()const
{
  std::cout << count;
  return 1;
}

int Counter::reset()
{
  count = _default;
  return 1;
}
