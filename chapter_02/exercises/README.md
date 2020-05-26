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

### Exercise 2.26
(a) Not legal, must specify an initializer
(b) legal
(c) legal
(d) illegal. sz is const, and can't be incremented.

### Exercise 2.27
(a) not legal... non const reference can't be initialized with 0
(b) valid
(c) ok, const reference can be initialized with 0
(d) ok
(e) ok
(f) not legal, can't specify a const reference
(g) ok

### Exercise 2.28
(a) invalid, cp is a constant pointer to an int, so it must be initialized.
(b) invalid, p1 is a valid pointer, but p2 is a const pointer, so it must be initialized.
(c) invalid, r is a reference to const bound to ic, but ic is a const int that must be initialized.
(d) invalid, p3 is a const pointer to a const int, so it must be initialized
(e) ok, p is a pointer to a const int.

### Exercise 2.29
(a) legal
(b) illegal, p3 is a pointer to const, so p1 must be a pointer to const
(c) illegal ic is a const int, so p1 must be a pointer to const
(d) illegal... p3 is a const pointer that must be initialized, can't change the address it holds
(e) illegal... p2 is a const pointer, so the address it holds can't be changed.
(f) illegal, ic is a const int, can't reassign.

### Exercise 2.30
v2 is top-level const... the object itself is const. v1 is not const.
p1 and r1 are not const.
p2 is low-level const, p3 is top and low-level const, and r2 is low-level const

### Exercise 2.31
`r1 = v2` not legal, r1 must be a reference to `const`.
`p1 = p2` not legal, p1 must be a pointer to `const`. `p2 = p1` is legal though.
`p1 = p3` not legal, p1 must be a pointer to `const`. `p2 = p3` is legal, since they are both low-level const.

### Exercise 2.32
Not legal, use a nullptr to initialize p

### Exercise 2.33
(a) a is an int with value 42.
(b) b is an int with value 42.
(c) c is an int with value 42.
(d) d is a pointer to an int with address of 42
(e) e is a pointer to a const int... illegal expresion
(g) g is a reference to a const int, can't assign

### Exercise 2.34
Check out this answer: https://github.com/adobrich/CppPrimer/blob/master/Chapter_02/exercise_34.cpp

### Exercise 2.35
j is an int with value 42. k is a reference to const bound to i. p is a pointer to int bound to i.
j2 is a const int with value 42. k2 is a reference to const int bound to i.

### Exercise 2.36
c is an int with value 3.
d is an int& bound to a.
`++c` increments c, so it has value 4.
`++d` increments a, so it has value 4.

### Exercise 2.37
c is an int with value 3.
d is an int& bound to a.

### Exercise 2.38
The main differences between `decltype` and `auto` are how they handle top-level `const` and how they handle references.

`auto` usually ignores top-level `const`, while `decltype` does not.

For example:

```C++
const int i = 0;
auto j = i; // j is an int.
decltype(i) k = i; // k is a const int
```

`decltype` will deduce a reference type if given a reference variable, while `auto` will use the type of the object to which the reference refers.

```C++
int i = 0, &r = i;
auto j = r; // j is an int.
decltype(r) k = r; // k is an int& 
```

### Exercise 2.39
Got this error: 
exercise_39.cpp:5:20: error: expected ';' after struct
struct Foo { } // Note: no semicolon!

### Exercise 2.40
```C++
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```
