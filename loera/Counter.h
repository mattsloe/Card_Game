//
//  Counter.h
//  Card_Game
//  This class of object is in charge of keeping count!
//  Count cannot be negative.
//  The default value of the counter is the initialized value.
//  Created by Matt Loera on 1/19/22.
//

#ifndef Counter_h
#define Counter_h
class Counter
{
public:
  Counter(const Counter&);
  Counter(int count=0);
  ~Counter();
  
  int increment(int amount=1);
  int decrement(int amount=1);
  //sets the counter to initialized value
  int reset();
  //@post returns the count
  int getCount()const;
  int display()const;
  
protected:
  int count;
  int _default;
  
private:
};

#endif /* Counter_h */
