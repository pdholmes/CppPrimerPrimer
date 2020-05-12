# Lecture 02 - Variables and Basic Types
## 2.0
Types are fundamental... they tell us what data mean and what operations we can perform.

Several primitive types, mechanisms exists for defining our own data types.

Types determine the meaning of data and operations. For example even the meaning of
```C++
i = i + j;
```
depends on the types of i and j. Are they ints? Sales_items?

## 2.1 Primitive Built-in Types
### 2.1.1 Arithmetic Types
- Integral types
- Floating-point types

Integral types: bool, char, extended characters, short, int, long, long long
Number of bits allocated depends on type.

Floating-point types: float, double, long double
Number of minimum significant digits depends on type.

Typically, we'll only work with ints and doubles.

#### Signed and Unsigned Types
Except for bool and extended character types, the integral types may be *signed* or *unsigned*.
*signed* can be negative or positive, *unsigned* only >= 0.

Rules of thumb:
- use unsigned type when you know values can't be negative.
- use ints for integer arithmetic.
- don't use char or bools in arithmetic.
- use double for floating-point computations.

### 2.1.2 Type Conversions
Many types support conversion to another type. Type conversions happen automatically when we use an object of one type where an object of another type is expected, and the conversion exists.

```C++
bool b = 42; // b is `true`
int i = b; // i has value 1
i = 3.14 // i has value 3
double pi = i // pi has value 3.0
unsigned char c = -1 // assuming 8-bit chars, c has value 255
signed char c2 = 256 // assuming 8-bit chars, value of c2 is undefined.
```

So in summary...
- when we assign a nonbool arithmetic type to a bool object, the bool is false if 0 and true otherwise
- assigning bool to another artihemtic type, the value is 1 if true and 0 if the bool is false
- when we assign a floating=point value to an object of integral type, the value is truncated
- when we assign an integral value to an object of floating-point type, the fractional part is 0.
- if we assign an out-of-range value to an object of unsigned type, we "wrap around"... so for example assuming an 8-bit char which holds 0-255, assigning 256 would yield 0, assigning 257 would yield 1. similarly assigning -1 yields 255.
- if we assign an out of range value to an object of signed type, the result is undefined. never do this!

```C++
int i = 42;
if (i) // condition will evaluate as true
	i = 0;
```

#### Expressions involving unsigned types
```C++
unsigned u = 10;
int i = -42;
std::cout << i + i << std::endl; // prints -84
std::cout << u + i << std::endl; // if 32 bit ints, prints 4294967264 (wraps around)
```

also, don't use unsigned in a for loop that decrements
```C++
for (unsigned u = 10; u >= 0; --u) // goes down to zero... then decrements past it!
	std::cout << u << std::endl;
```

```C++
unsigned u = 11;
while (u > 0) {
	--u;
	std::cout << u << std::endl;
}
```

Lol at this from here https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/:
> Many notable bugs in video game history happened due to wrap around behavior with unsigned integers. In the arcade game Donkey Kong, it’s not possible to go past level 22 due to a bug that leaves the user with not enough bonus time to complete the level. In the PC game Civilization, Gandhi was known for being the first one to use nuclear weapons, which seems contrary to his normally passive nature. Gandhi’s aggression setting was normally set at 1, but if he chose a democratic government, he’d get a -2 modifier. This wrapped around his aggression setting to 255, making him maximally aggressive!


### 2.1.3 Literals
A value, such as 42 (this author really likes 42. perhaps it is the answer to the Ultimate Question of Life, the Universe, and Everything), is known as a *literal* because its value is self-evident. Every literal has a type. The form and value of a literal determine its type.

Integer literals: 20. (either int, unsigned int, long, unsigned long, long long, or unsigned long long, the smallest in which the literal's value fits)
```C++
int i = 20;
```

Floating-point literals: 3.14159 are doubles by default.
```C++
double d = 3.14159;
```
Character literals `'a'` within single quotes.
```C++
char c = 'a';
```

String literals `"Hello World!"` within double quotes. A string literal is an *array* of constant chars, with a null character appended to the end of the string. So the actual size of the string literal is one more than its apparent size.

```C++
std::string s = "Hello World!";
```

String literals are automatically concatenated when only spearated by spaces, tabs or newlines.
```C++
std::cout << "a really, really long string literal "
			 " that spans two lines" << std::endl;
```

Bool literals: the words `true` and `false` are literals of type `bool`.
```C++
bool b1 = true; bool b2 = false;
```

#### Escape Sequences
Non printable characters, like `'\n'`, will print a new line. We use them like any other character

## 2.2 Variables
A *variable* provides named storage that programs can manipulate.
Each variable has a type, which determines the size and layout of the variable's memory, the values that can be stored in that variable, the operations we can apply on it, etc. "Variables" and "objects" can be used interchangeably.

### 2.2.1 Variable Definitions
*Type specifier*, followed by a list of one or more variable names separated by commas, ends with a semicolon. Optionally, we can provide an initial value.

```C++
int sum = 0, value, units_sold = 0;
Sales_item item;
std::string book("0-201-78345-X");
```

We'll learn more about strings in Chapter 3.

#### Initializers
An object that is initialized gets the specified value at the moment it is created.
Can be a complicated expression.

```C++
double price = 109.99, discount = price * 0.16;
double salePrice = applyDiscount(price, discount);
```

Notably... initialization is not "assignment", though both use the `=` symbol.
Initialization gives a variable a certain value when it is created, while assignment replaces an old value with a new one.

#### List Initialization
Several forms of initialization...

```C++
int units_sold = 0;
int units_sold = {0}; // list initialization
int units_sold{0}; // list initialization
int units_sold(0);
```
... quick aside. Can't use list initialization when it may lead to a loss of information.
```C++
long double ld = 3.1415926536;
int a{ld}, b = {ld}; // error: narrowing conversion required.
int c(ld), d = ld; // ok: but value will be truncated
```

#### Default Initialization
Define a variable without an initializer ==> default initialization.
What value the variable is given depends on the type.

If the variable is of built-in type, default value depends on where it is defined.
Defined outside function body ==> initialized to zero.
Defined inside function ==> *uninitialized*... the value is undefined.

```C++
int a, b, c, d = 0; // only d = 0, the rest have undefined value!!
int a = 0, b = 0, c = 0, d = 0; // better
```

```C++
std::string s1; // s1 default initialized as empty string
Sales_item item; // default initialized, depends on Sales_item class.
```

**Pro tip:** explicitly initialize variables of built-in type to avoid undefined variable values. Can just use 0, for example.

### 2.2.2 Variable Declarations and Definitions
*Separate compilation* allows us to split programs into several files, each compiled independently.
We need a way to share code across files.
To do so, we distinguish between *declarations* and *definitions*.
Declarations make a name known to a program, while definitions create the object.

...this isn't very important now, but will be more important later.
Declarations specify a type and name of a variable.
A variable definition is a declaration, but not vice versa.
Definitions also allocate storage and may provide an initial value for a variable.

We use the `extern` keyword to to obtain a declaration that is not a definition.
We can't supply an initializer.

```C++
extern int i; // declares but does not define i
int j; // declares and defines j

// this would be an error if inside a function:
extern double pi = 3.1416; // definition, because we supplied an initializer.
```

Variables must be defined exactly once but may be declared many times.

### 2.2.3 Identifiers
aka variable names.

Can use letters, digits, or underscores. Identifiers are case-sensitive. Can't begin with a number.

Rules of thumb:
- identifiers should give some notion of a variable's meaning
- should normally be lowercase
- can begin classes with uppercase letter, i.e. `Sales_item`
- multiple words should be broken up, i.e. `student_loan`, not `studentloan`

There's a bunch of C++ keywords that can't be used as identifiers.
We've already seen several, for example, `while`, `if`, `for`, `false`, `true`, `int`, `char`, `class`, etc.

### 2.2.4 Scope of a Name
A *scope* is a part of a program in which a name has a particular meaning.
Generally, scopes are delimited by curly braces.

Basically, scopes are where a name is associated with a particular object.
For example, in the scope of this class, the name Patrick is associated with me.
On some random street though, the name Patrick is likely to refer to a completely different object.

```C++
#include <iostream>
int main() {
	int sum = 0;
	for (int val = 1; val <= 10; ++val)
		sum += val;
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	return 0;
}
```
`main` is defined outside curly braces, so it has *global scope*

`sum` is defined within the scope of the block that is the body of the `main` function... accessible until the end of the main function. `sum` has *block scope*

`val` is defined in the scope of the for statement... can't be used elsewhere in main.

#### Nested Scopes
```C++
#include <iosteram>

int reused = 42;
int main() {
	int unique = 0;
	std::cout << reused << " " << unique << std::endl;

	int reused = 0; // new, local object named reused hides global reused
	std::cout << reused << " " << unique << std::endl;

	// explicitly request global reused:
	std::cout << ::reused << " " << unique << std::endl;

	return 0;
}
```

the local `reused` in *in scope* once it is defined.

Using the scope operator `::` with an empty left hand side means you want to fetch a name from the global scope.

## 2.3 Compound Types
This section can be rather confusing at first, but is extremely important to understand thoroughly!

> A *compound type* is a type defined in terms of another type.

C++ has several compound types, the most important of which -- references and pointers -- we'll cover here.

So far, we've only dealt with declarations that consists of a type followed by variable names. More generally, a declaration involves a *base type* followed by a list of *declarators* that names variables and gives them types related to the base type.

### 2.3.1 References
A *reference* defines an alternative name for an object. A reference type "refers to" another type.

```C++
int ival = 1024;
int &refVal = ival; // refVal refers to (is another name for) ival
int &refVal2; // error: a reference must be initialized.
```
Instead of copying the initializer's value, we *bind* the reference to its initializer. Once initialized, there is no way to rebind a reference to a different object.

#### A Reference is an Alias
A reference is not an object, it is just *another name* for an already existing object.

All operations on that reference actually operate on the object to which the reference is bound.

```C++
int ival = 1024;
int &refVal = ival;

refVal = 2; // assigns 2 to ival

int ii = refVal; // same as ii = ival
int &refVal3 = refVal; // binds refVal3 to ival
```

#### Reference Definitions
```C++
int i = 1024, i2 = 2048; // i and i2 are both ints
int &r = i, r2 = i2; // r is a reference bound to i; r2 is an int.
int i3 = 1024, &ri = i3; // i3 is an int, ri is a reference bound to i3
int &r3 = i3, &r4 = i2; // both r3 and r4 are references.

int &refVal4 = 10; // error: initializer must be an object
double dval = 3.14;
int &refVal5 = dval; // error: initializer must be an int object
```

### 2.3.2 Pointers
> A *pointer* is a compound type that "points to" another type. Like references, pointers are used for indirect access to other objects. Unlinke a reference, a pointer is an object in its own right.

They can be assigned and copied, can point to different objects over its lifetime, don't require an initializer, and have undefined value at block scope if they are not initialized.

We define a pointer type by writing a declarator of the form `*d`, where d is the name being defined:
```C++
int *ip1, *ip2; // both ip1 and ip2 are pointers to int
double dp, *dp2; // dp2 is a pointer to double; dp is a double
```

#### Taking the Address of an Object
A pointer holds the address of another object. We get that address using the *address-of* operator (the `&` operator):

```C++
int ival = 42;
int *p = &ival; // p holds the address of ival; p is a pointer to ival
```

Almost always, the types of the pointer and the object to which it points must match:
```C++
double dval;
double *pd = &dval;
double *pd2 = pd;

int *pi = pd; // error: types of pi and pd differ
pi = &dval; // error: assigning the address of a double to a pointer to int
```
The type of the pointer is used to infer the type of the object to which the pointer points.

The value (i.e. the address) of a pointer can:
- point to an object
- point to a location immediately past the end of an object
- it can be a null point, i.e. not be bound to any object
- it can be invalid (if its not any of the preceding three)

#### Using a Pointer to Access an Object
We use the *dereference operator* (`*`) to access the object to which a pointer points. We can only dereference a pointer when it points to an object!

```C++
int ival = 42;
int *p = &ival; // p is a pointer to ival
cout << *p; // * yields the object to which p points, i.e., 42
```

```C++
*p = 0; // * yields the object, assign a new value to ival through p
cout << *p; // prints 0
```

```C++
int i = 5;
int *p = &i;

// the following are equivalent... *p is the same as i
i = i + 5;
i = *p + 5;
*p = *p + 5;
```

Note that `&` and `*` have different meanings depending on whether they are used in an expression or as part of a declaration.

#### Null Pointers
```C++
// equivalent definitions:
int *p1 = nullptr;
int *p1 = 0;
```

#### Assignment and Pointers
References aren't objects, and we can't make them refer to a different object after they're initialized.
Pointers, on the other hand, are objects, and we can change the object they point to.
```C++
int i = 42;
int *pi = 0; // null pointer
int *pi2 = &i;
int *pi3; // pi3 uninitialized
pi3 = pi2; // pi3 and pi2 now point to the same object
pi2 = 0; // pi2 now a null pointer
```

#### Other Pointer Operations
Can use pointers in a condition, which will be true if the pointer is not a null pointer.
```C++
if (p) // true if pointer is not a nullptr
```

Can use `==` and `!=` to see if two pointers point to the same object.
```C++
if (p1 == p2); // true if p1 and p2 point to same object
```

#### `void*` Pointers
> The type `void*` is a special pointer type that can hold the address of any object.

```C++
double obj = 3.14, *pd = &obj;
void *pv = &obj; // obj can be an object of any type
pv = pd; // pv can hold a pointer to any type
```

### 2.3.3 Understanding Compound Type Declarations
Legal, but may be misleading:

```C++
int* p;
```

The `*` modifies `p`, not the type. For example:
```C++
int* p1, p2; // p1 is a pointer to int; p2 is an int.

int *p1, *p2; // both p1, p2 are pointers to int
```

#### Pointers to Pointers
```C++
int ival = 1024;
int *pi = &ival; // pi points to an int
int **ppi = & pi; // ppi points to a pointer to an int.
```

#### References to Pointers
```C++
int i = 42;
int *p; // p is a pointer to int
int *&r = p; // r is a reference to the pointer p
r = &i; // r refers to a pointer; assigning &i to r makes p point to i
*r = 0; // dereferencing r yields i, the object to which p points; changes i to 0
```
