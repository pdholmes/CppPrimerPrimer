# Chapter 04 - Expressions
C++ defines many operators to use in expression, many of which we have already seen and used.
In this chapter, we will take a deeper dive into operators applied to operands of built-in type, as well as some operators defined by the library.

> An *expression* is composed of one or more *operands* and yields a *result* when evaluated.

## 4.1 Fundamentals
###4.1.1 Basic Concepts
*unary* operators, like address-of (&) and dereference (`*`) act on a single operator
*binary* operators, such as equality (`==`) and multiplication (`*`) act on two operands.
(also a ternary operator, and function calls take unlimited operands)
Context determines what a symbol means, i.e. (`*`);

#### Grouping Operators and Operands
*Precedence*, *associativity*, and *order of evaluation* are important... just like order of operations in math.
i.e. the result of `5 + 10 * 20/2` depends on order.

#### Operand Conversions
Operands are often automatically converted when necessary and a type exists.
Usually this behavior is as we expect (i.e. `int`s promoted to floating-point type).
Generally, small integral types (bools, chars) are promoted to `int`s.

#### Overloaded Operators
As we've seen previously, the type of the operands determine which operator to use. (i.e., adding two Sales_item objects together)

#### Lvalues and Rvalues
Every expression is either an *rvalue* or an *lvalue*, a designation inherited from C.
Typically, when we use an object as an rvalue we use its value, and when we use an object as an lvalue we use its location in memory.
Operators differ as to whether they require/return rvalues/lvalues.
However, we can (almost) always use an lvalue when an rvalue is required, but not the other way around.

Examples:
- assignment requires lvalue as LHS, yields lvalue
- address-of requires lvalue, returns pointer as rvalue
- dereference and subscript yield lvalues
- increment/decrement requires lvalues

### 4.1.2 Precedence and Associativity
Two or more operators ==> compound expression.
Precedence and associtativity determine grouping for operands... can override with parentheses.
Precedence determines priority of operators, associativity determines grouping within same precedence level.
For example, division and multiplication have same precedence, higher than addition.
Left associative, so we group left to right.

`3+4*5` is 23, not 35 because of precedence
`20-15-3` is 2, not 8, because of associativity.

`6 + 3 * 4 / 2 + 2` yields 14.

#### Parentheses Override Precedence and Associativity
...self-explanatory

#### When Precedence and Associativity Matter
An example we've already seen:
```C++
int ia[] = {0, 2, 4, 6, 8};
int last = *(ia + 4); // ok, last is 8

last = *ia + 4; // ok, last is 4.
```

Input and output expressions... IO is left associative.
```C++
cin >> v1 >> v2; // read into v1 and then v2
```

### 4.1.3 Order of Evaluation
We've talked about how operands are grouped, but not about the order in which operands are evaluated.
In most cases the order is unspecified, such as

```C++
int i = f1() * f2();
```

We know that `f1()` and `f2()` will be called before `*`, but don't know the order.
For this reason, the following is undefined:

```C++
int i = 0;
cout << i << " " << ++i << endl; // undefined
```

We know the grouping of the operators, but not the order of evaluation, so we can't refer to and change the same object.

The only operators that guarantee order of evaluation are &&, ||, the conditional (? :) and the comma (,) operator

#### Order of Evaluation, Precedence, and Associativity
Looking at 
`f() + g() * h() + j()`, we know g and h are multiplied by precedence, then f is added to that result and then that result is added to j by associativity.
But there are no guarantees about function call order.

## 4.2 Arithmetic Operators
Not too much to say here... the unary (`-`) operator (i.e. negation) has higher precedence than multiplication and division.

We introduce the `%` operator, known as the "remainder" or "modulus" operator, which takes two integral values.
```C++
int ival = 42;
double dval = 3.14;

ival % 12; // ok: result is 6
ival % dval; // error
```

Operands and results of arithmetic operators are rvalues.

## 4.3 Logical and Relational Operators
#### Logical AND and OR Operators
&& and || use *short-circuit evaluation*, meaning the RHS will only be evaluated if and only if the LHS does not determine the result.

#### Logical NOT operator
! returns inverse of the truth value of its operand

#### The Relational Operators
(`<, <=, >, >=`) have their usual meaning.
They are left associative and return `bool` values.

```C++
if (i < j < k) // true if k greater than 1!
```

```C++
if (i < j && j < k)
```

#### Equality Tests and the `bool` literals
If you want to test the truth value of an arithmetic or pointer object, usually you should just use the value itself as a condition:

```C++
if (val) //...
if (!val) //...
```

Don't do this:
```C++
if (val == true)
```
because if `val` is not a bool, then true get converted to the arithmetic type (i.e. 1)

## 4.4 Assignment Operators
LHS must be a modifiable lvalue.
i.e., can't do
```C++
1024 = k;
i + j = k;
ci = k; // ci const
```

Result of assignment is LHS operand.

#### Assignment is Right Associative
```C++
int ival, jval;
ival = jval = 0; // ok;
```

```C++
int ival, *pval;
// can't assign pointer value to int
ival = pval = 0; // error;

string s1, s2;
s1 = s2 = "OK";
```

#### Assignment Has Low Precedence
Can use assignment in conditions, but usually must parenthesize.

Worse way to write this loop:
```C++
int i = get_value();
while (i != 42) {
	// do something with i
	i = get_value();
}
```

Better way to write this loop:
```C++
int i;
while ((i = get_value()) != 42) {
	// do something with i
}
```

#### Beware of Confusing Equality and Assignment Operators
Assigns j to i, then tests condition:
```C++
if (i = j)
```

```C++
if (i == j)
```

#### Compound Assignment Operators
```C++
+=, -=, *=, /=, %=
<<=, >>=, &=, ^=, |=
```

## 4.5 Increment and Decrement Operators
Prefix vs postfix form:
prefix yields incremented value, postfix yields unincremented value.
```C++
int i = 0, j;
j = ++i; // j = 1, i = 1
j = i++; // j = 1, i = 2
```

Pro tip: use prefix unless postfix necessary, slightly more efficient because you don't have to store unincremented value.

#### Combining Dereference and Increment in a Single Expression
```C++
auto pbeg = v.begin();
// prints elements 
while (pbeg != v.end() && *beg >= 0) {
	cout << *pbeg++ << endl;
}
```

Equivalent to `*(pbeg++)`, so pbeg++ increments and returns unincremented version, which get dereferenced.

#### Remember that Operands Can be Evaluated in Any Order
Associativity and Precedence determine grouping of operands, but not order of evaluation:

From before, we had
```C++
for (auto i = s.begin(); it != s.end() && !isspace(*it); ++it)
	*it = toupper(*it);
```

Attempting to dereference and increment in a single expression:
```C++
auto beg = s.begin();
while (beg != s.end() && !isspace(*beg))
	*beg = toupper(*beg++); // error!
```
The assignment is undefined, could either be:
```C++
*beg = toupper(*beg); // if LHS evaluated first
*(beg+1) = toupper(*beg); // if RHS evaluated first
```

## 4.6 The Member Access Operators
"Dot" and "arrow" operators.

```C++
string s1 = "a string", *p = &s1;
auto n = s1.size();
n = (*p).size(); // parentheses!
n = p->size()
```

The parentheses are necessary, because dereference has a lower precedence than the dot operator.
```C++
*p.size() // error
```

## 4.7 The Conditional Operator
A new operator! Basically a really concise if-else statement.
```C++
cond ? expr1 : expr2;
```

```C++
string finalgrade = (grade < 60) ? "fail" : "pass";
```

#### Nesting Conditional Operators
```C++
finalgrade = (grade > 90) ? "high pass" :
	(grade < 60) ? "fail" : pass;
```
Right associative!

#### Using a Conditional Operator in an Output Expression
Use parentheses! Conditional operator has fairly low precedence.

```C++
cout << ((grade < 60) ? "fail" : "pass"); // as expected
cout << (grade < 60) ? "fail" : "pass"; // prints 1 or 0
cout << grade < 60 ? "fail" : "pass"; // error
```

## 4.8 The Bitwise Operators
We're going to skip... but basically you can operate on individual bits.
Shift operators `<<` and `>>` are left associative, which is why
```C++
cout << "hi" << " there" << endl;
```

executes as 
```C++
( (cout << "hi") << " there" ) << endl;
```

There's also bitwise not, and, xor, and or operators.

## 4.9 The `sizeof` Operator
Returns the size in bytes of an expression or type name.

```C++
sizeof(char); // guaranteed to be 1.
Sales_data data, *p;
sizeof(Sales_data);
sizeof data;
sizeof p;
sizeof *p;
sizeof data.revenue;
sizeof Sales_data::revenue;
```

Note that sizeof on an array returns the size of the entire array, so to get the number of elements, we can do:
```C++
constexpr size_t sz = sizeof(ia)/sizeof(*ia); // returns the number of elements in ia
int arr2[sz]; // ok; sizeof returns constant expression
```

## 4.10 Comma Operator
Takes two operands, guarantees the order in which operands evaluated (left, then right).
Result is the value of RHS expression

```C++
vector<int>::size_type cnt = ivec.size();
// assign values from size, size-1, ... 1 to ivec
for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
	ivec[ix] = cnt;
```

## 4.11 Type Conversions
We've talked about implicit conversions:
- small integral types promoted to int
- nonbool converted to bool
- initialization (i.e. double to initialize int)
- arithmetic/relational operators, convert to common type

### 4.11.1 The Arithmetic Conversions
In summary, small integral types get promoted to int, then to floating point types if necessary to preserve precision.

### 4.11.2 Other Implicit Conversions
- array to pointer conversions
- pointer conversions (i.e. nullptr, void* can point to other types)
- conversion to bool
- conversion to const
- conversion defined by class type (i.e. library string converting C-style string)

### 4.11.3 Explicit Conversions
The book says this is dangerous and we shouldn't do it... but we should probably know it exists.
We use a *cast* to request an explicit conversion.

#### `static_cast`

```C++
// cast used to force floating-point division
double slope = static_cast<double>(j) / i; 
```

#### `const_cast`
"Cast away the const"
```C++
const char *pc;
char *p = const_cast<char*>(pc);
```
however... writing through p is undefined, unless the object to which it points was originally not a `const`.

#### `reinterpret_cast`
Can "reinterpret" the type of the object, i.e. reinterpret an `int*` as a `char*`, but very dangerous!