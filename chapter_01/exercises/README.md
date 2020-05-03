# Chapter 01 Written Exercises
### Exercise 1.6
The code fragment is not legal. We should include `std::cout` at the
start of each line to correctly print the output.

### Exercise 1.8
`std::cout << "/*";` is legal.

`std::cout << "*/";` is legal.

`std::cout << /* "*/" */;` is illegal.

`std::cout << /* "*/" /* "/*" */;` is surprisingly legal, and prints `"/*"`

### Exercise 1.12
The loop iterates from -100 to 100, adding each to its sum.
The final value of sum is 0.

### Exercise 1.14
Both types of loops can be used in place of the other... generally, for loops make more sense when the range of values to iterate over is known beforehand, while `while` loops are better when the number of iterations are unknown.

### Exercise 1.15
See a good answer here: https://github.com/adobrich/CppPrimer/tree/master/Chapter_01

### Exercise 1.17
If the program is only presented equal values, it will just generate a single line saying how many times that number occured.

If all values are different, then we'll generate one line per number, each saying that number appeared 1 time.