#Chapter 02 Written Exercises
### Exercise 2.1
ints are at least as long as shorts, longs at least as long as ints, and long longs at least as long as longs.

Unsigned types are only >= 0, signed types can be positive or negative.

Doubles are at least 10 significant digits, while floats are at least 6.

### Exercise 2.2
I would use doubles for each of them... I'd rather be accurate then lose a few cents assuming something's an int lol.

### Exercise 2.3
	std::cout << u2 - u << std::endl; // ok, prints 32
	std::cout << u - u2 << std::endl; // prints a really big number

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl; // ok, prints 32;
	std::cout << i - i2 << std::endl; // ok, prints -32

	std::cout << i - u << std::endl; // ok, prints 0;
	std::cout << u - i << std::endl; // ok, prints 0;


### Exercise 2.5 - 2.8
See these solutions: https://github.com/adobrich/CppPrimer/tree/master/Chapter_02

### Exercise 2.9
(a) Illegal... input_value should be initialized before being used in this expression.
(b) Illegal, 3.14 will be truncated, so list initialization can't be used.
(c) Illegal, wage must be defined before it can be assigned to salary
(d) Legal, 3.14 truncated to 3

### Exercise 2.10
`global_str` is default initialized to the empty string.
`global_int` is default initialized to 0, since it is outside of any function body.
`local_int` is undefined, since it is defined inside the function body.
`local_str` is default initialized to the empty string

### Exercise 2.11
(a) definition, because there's an initializer.
(b) definition.
(c) declaration.

### Exercise 2.12
(a) invalid, double can't be a variable name.
(b) technically legal.
(c) not legal, can't use a hyphen.
(d) not legal, can't start with a number.
(e) legal, D is capitalized.

### Exercise 2.13
j is equal to 100.

### Exercise 2.14
The program is legal... the `i` defined in the for statement hides the `i` in block scope during the for statement execution.
Then, when printing, the original `i` is used, so the program prints `100 45`.

### Exercise 2.15
(a) is fine.
(b) the initializer to the reference must be an object.
(c) is fine.
(d) an initializer must be specified.

### Exercise 2.16
(a) assigns 3.14159 to d
(b) legal, d now equals 0.0
(c) legal, i is still 0.
(d) legal, i is still 0.

### Exercise 2.17
it prints `10 10`

### Exercise 2.19
Pointers are objects, whose value is the address of another object. We can dereference pointers to get the objects to which they point.

References are just aliases for another object.

### Exercise 2.20
The program sets the value of i (aka `*p1`) to be equal to 42 * 42

### Exercise 2.21
(a) illegal, pointer is to a double.
(b) illegal. even though i = 0, we can't initialize a null pointer from an int.
(c) legal.

### Exercise 2.22
`if (p)`... if `p` is valid and not a null pointer, will be true.
`if (*p)`... depends on the object to which `p` points. for example, if it is a nonzero int, will be true.

### Exercise 2.23
Very in depth answer here: https://github.com/adobrich/CppPrimer/tree/master/Chapter_02

### Exercise 2.24
A `void*` pointer can point to any object, while a `long*` pointer can only point to longs.

### Exercise 2.25
(a) ip is a pointer to int, i is an int, r is a reference to i.
(b) i is an int, ip is a null pointer to int.
(c) ip is a pointer to int, ip2 is an int.