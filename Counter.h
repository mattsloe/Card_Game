//
//  Counter.h
//  Card_Game
//
//  Created by Matt Loera on 1/19/22.
//

#ifndef Counter_h
#define Counter_h
class Counter
{
public:
  Counter();
  Counter(const Counter&);
  ~Counter();
  
  int increment(int amount);
  int decrement(int amount);
  int getCount()const;
  int display()const;
  
protected:
  int count;
  
private:
};

#endif /* Counter_h */
