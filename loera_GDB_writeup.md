#Debugging and Testing
  *Matt Loera*
I made sure to build the testing into the program from the beginning. This was especially important, since the modularity of the program design would make it very granular. I included a supplementary file called "test" that contained various test cases for the program. Working with gdb, this made it very easy to track function calls and breakpoints for the program, as they would all be in one place. 

Since I strove for a more test-driven development, I used gdb extensively at every step of programming this assignment. I tested every Class and function as I implemented them. This allowed me to work out a lot of the kinks at the beginning instead of having to step between different aspects of the program to chase down unwanted behavior or memory leaks. 

Valgrind was also a very useful tool. At major intervals, I ran the program with valgrind to check for memory leaks. 

As I worked through the program, especially the parts with dynamic binding, it was useful to step through the function calls to see exactly which function that the program was calling at a given step. This took a lot of the guesswork out of figuring out how the inheritance and polymorphism worked in my program. This made gdb a very good learning tool for seeing how this works in action. 