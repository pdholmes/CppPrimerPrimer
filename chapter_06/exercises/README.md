## Exercise 6.1
What is the difference between a parameter and an argument? Parameters specify the inputs that a function expects, and are initialized by arguments in a function call.

## Exercise 6.2
(a) the return type of the function is an int, but it returns a string s
(b) the function does not specify a return type. if no output is expected, you can use "void".
(c) the parameters must have different names, and a curly brace is missing
(d) the function body must be specified in a statement block.

## Exercise 6.6
A parameter is defined when the program begins, but is not initialized until an argument is passed. A local variable is a variable defined in the scope of a function body. A local static variable is a local variable whose lifetime extends across calls to the function. Parameters are useful for accepting arguments to functions, local variables are useful when you only need a variable within a function, and local static variables are useful when you only need a varible within a function but you want it to exist even after the function is done executing.

## Exercise 6.8
Check Chapter6.h

## Exercise 6.9
Check fact.cpp and factMain.cpp

## Exercise 6.13
void f(T) takes T as an argument and makes a copy of it to initialize a parameter. void f(T&) initializes a parameter with a reference to T.

## Exercise 6.14
A parameter should be a reference when you wish to make changes to the argument being passed in. It should not be a reference if no change to variables outside the function is desired.

## Exercise 6.15
s is a reference to const because we do not wish to change the argument to s at all, but the reference is more efficient than copying the object. occurs is a plain reference because we wish to alter this argument. the char parameter c is not a reference because we will not alter it, and it's so small that space isn't an issue. if we made s a plain reference, we would have to be careful not to change its value anywhere, and if we made occurs a reference to const, the code to increment occurs would be invalid.

## Exercise 6.16
The parameter should be a const string &, so that you can also check string literals

## Exercise 6.18
(a) bool compare(matrix &, matrix &)
(b) vector<int>::iterator change_val(int, vector<int>::iterator)

## Exercise 6.19
(a) Illegal, too many arguments supplied
(b) legal
(c) legal
(d) ok, 3.8 will be cast as an int.

## Exercise 6.20
Reference parameters should be references to const when you don't need to change the argument. It can be limiting not to do this, for example if you'd like to 
accept an object of literal type.

## Exercise 6.24
The parameter should be a reference to an array, since arrays can't be copied. In this case, the parameter ia will actually be a pointer to the first element of the ia (the dimension is ignored) and we couldn't guarantee that there would be 10 elements.

## Exercise 6.30
The compiler found the first error where the return value was not a bool, but not the second potential error where you could flow off the end of the function without returning.

## Exercise 6.31
It's valid to return a reference when the object referenced by that object is not local to the function, i.e. it is a preexisting object. Same thing with a reference to const.

## Exercise 6.32
I believe the function is legal. the "get" function returns a reference to an int within the array `*arry`. in "main", we iterate through the indices of ia, using "get" to get a reference to the current element, and then setting that element to i. this should produce an array ia = {0, 1, ..., 8, 9}.

## Exercise 6.34
The big issue here is that if you input a negative number to the factorial function, it would recurse forever. For non negative integers, it would cause an extra call to the factorial function, but shouldn't affect the result.

## Exercise 6.35
Using `val--` would have decremented val, instead of just getting an integer one less than val. Then when multiplying by val, we would accidentally multiply by the decremented val. Also, val-- returns a copy of val before decrementing, so the next factorial function would receive 5 over and over and over.

## Exercise 6.36
`string (&func( /*    */ )) [10]`;

## Exercise 6.37
```C++
using strArr = string(&)[10];
strArr func(/*     */){}

auto func(/*     */) -> string(&)[10]

string s1[10];
decltype(s2) &func(/*     */)
```

Of these, I prefer the type alias. it's easy to read and not confusing.

## Exercise 6.39
(a) The second declaration overwrites the first one. 
(b) This is illegal, since the parameters (none) are the same.
(c) This is legal, although the compiler might get confused because a conversion to int from double exists.

## Exercise 6.40
(a) seems fine...
(b) this is in error, as the parameter with a default argument should come last

## Exercise 6.41
(a) is not legal, because you must provide a height.
(b) is legal, and good
(c) is legal, but probably does not much the programmer's intent, as `*` is converted to an int

## Exercise 6.43
(a) Probably in a header file? From answers: inline function declarations and definitions should be placed in a header file and included in source files when required. This is good practice since the definition of an inline function must match exactly each time it is defined.
(b) Put the declaration in a header file. Put the definition in source.

## Exercise 6.45
If they're short and aren't overloaded, then they should probably be inline.

## Exercise 6.46
No... unless the size function of the string was a constexpr function (which I don't think it is), and the strings it took were constexpr. But then it would be useless.

## Exercise 6.48
The loop keeps reading words in from the command line until the desired word is found. The assert then checks cin is still reading in words, i.e. we haven't hit an end of file. If it turns false, then the program terminates. I guess it is a good use of assert, since if the loop quits without reading sought then you probably just want to exit the program anyways.

Update: this is wrong ^. I think the condition cin always evaluates to true, while cin >> s may not. In any case, it's not a good use of assert. It'd be better to use assert to check for something that cannot be false for the program to run.

## Exercise 6.49
A candidate function are all the functions of the correct name that have been declared up til that point in the code.
A viable function is one whose parameter sets match the arguments that have been passed, either explicitly or via a type conversion.

## Exercise 6.50
(a) f(int, int) and f(double, double) are viable. The call is ambiguous, so it is in error.
(b) f(int) and f(double, double = 3.14) are viable, and f(int) is an exact match
(c) f(int, int) and f(double, double = 3.14) are viable. f(int, int) is the better match.
(d) f(int, int) and f(double, double = 3.14) are viable, with f(double, double = 3.14) the best match.

## Exercise 6.52
(a) involves a promotion from char to int, so rank 3
(b) involves an arithmetic conversion, so rank 4

## Exercise 6.53
(a) legal, differ by the const ness of the int object referenced by the references.
(b) also legal, for same reasons as (a).
(c) not legal, since top level const is ignored.

## Exercise 6.54
```C++
int f(int, int);
using func = decltype(f)*;
vector<func> v;
```