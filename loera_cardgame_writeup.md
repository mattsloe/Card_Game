#Card Game Writeup
  *Matt Loera*
#Introduction
This program is a Card Game that uses the Command Line Interface.  The card game is merely an example game showing some basic mechanics that can be implemented using the Card Game Libraries. The Card Game Library includes all of the code to handle different players, different card types, collections of cards (into a Player_Deck), etc. This program was my first attempt at designing a program using an Object-Oriented paradigm. 

#Mechanics
The card game consists of two user-Players that take turns playing cards and attacking each other. Each player has 3 stats attached to them. First, is their Lifeline. This is set to 20 by default, but can be changed in the Player header. Each player's turn has 4 phases. First the player draws 3 cards from the deck (they should have 4 total to choose from.) Next the player can choose cards. The player can choose 1 card to play and 1 card to hold onto for the next turn. The rest are discarded.  Next, the Player plays the card that they chose. This only involves changing the player's own stats, but this mechanic can be very flexible as in the Spell cards. Finally, the last phase of a player's turn is the attack phase, where the player attacks with the sum of their attacking cards they have in play. The attack hits the opponent's defense points first, cancelling them out, before attacking the opponent's Lifeline directly. A player loses when thier Lifeline drops to zero. 

#Implementation
The most useful part of Object-Oriented implementation for this game is in the inheritance heirarchy for the Card class. In my design, I created a virtual class called Card that would be the ancestor of all of the different card types. I put pure virtual function play() as well as display(). All cards, no matter what type they are, would need to implement a version of these methods. This type of function implementation in the hub class allowed me to have a collection of pointers to different Card types (Attack_Card,Defense_Card,Spell_Card) and be able to call these basic methods for each and the program would call the proper function. This way, I could iterate through a stack of Cards and just call print(). 

One of the challenges that I ran into with this was when I was implementing the play() function for the cards. In that case, I actually didn't get the inheritance right, as the program was trying to a virtual play() function that came from the Card base class. I actually had to use a workaround (using the dynamic_bind) to back-identify what kind of specific Card I was using in order to call the right function. 

I also ran into a design challenge late in my implementation when I ran into a circular dependency. I actually had to change my implementation in order to force it to work. It was not pretty but I learned a lot from handling that. The problem arose from trying to have different objects interact with each other, while trying to keep their info encapsulated. I'll have to think on how I would approach that in the future; I don't think I have the tools at the moment for an elegant solution. 