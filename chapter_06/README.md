# Chapter 06 -- Functions
> This chapter describes how to define and declare functions.
A function is a named block of code, which can take zero or more arguments and can yield a result.
We'll cover argument passing, returning values, and function overloading (multiple functions with same name but take different inputs).

## 6.1 Function Basics
A *function* typically consists of:
- a *return type*
- a list of zero or more *parameters* 
- a *function body*

We execute a function by calling it, using the *call operator* `()`, which takes an expression that is a function or points to a function.
Inside the parentheses are *arguments*, which are used to initialize the function's parameters.
The type of the call expression is the return type of the function.

#### Writing a Function
Let's say we want to compute the factorial of a number `n`.
```C++
int fact(int val) {
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}
```

The function is named `fact`, it takes one `int` parameter, and returns an `int` value.
The `return` ends execution and returns the value of `ret`.

#### Calling a Function

```C++
int main() {
	int j = fact(5);
	cout << "5! is " << j << endl;
	return 0;
}
```

The function call initializes the function's parameters from the arguments, and transfers control to the function.
Execution of the function ends when a `return` is encountered, which transfers control back to the calling function and returns the value.
The call to `fact` is equivalent to:

```C++
int val = 5;
int ret = 1;
while (val > 1)
	ret *= val--;
int j = ret;
```

#### Parameters and Arguments
Arguments are used to initialize parameters.
The first argument initializes the first parameter, and so on.
However, there's no guarantees about the order in which arguments are evaluated.

The type of the argument must match (or be convertible to) the type of the corresponding parameter.
There must be exactly the same number of arguments as parameters, so parameters are always initialized.

```C++
fact("hello"); // error
fact(); // error
fact(42, 10, 0); // error
fact(3.14); // ok
```

#### Function Parameter List
The parameter list can be empty but can't be omitted:
```C++
void f1() { /* ... */ }
void f2(void) { /* ... */ }
```
Can use the `void` keyword to be explicit there's no parameters.

We must specify the type of each parameter:
```C++
int f3(int v1, v2) { /* ... */ } // error
int f4(int v1, int v2) { /* ... */ } // ok
```
Parameters must have different names.

#### Function Return Type
Most types can be used as a `return` type, except for an array type or function type... we'll specify pointers to these types instead.
In particular, the return type can be `void` when the function does not return a value.

### 6.1.1 -- Local Objects
Names have *scope*, and objects have *lifetimes*.
*Scope* determines the part of the program's text where a name is visible, but *lifetime* is the time during the program's execution that the object exists.

The body of a function is a statement block, which forms a scope.
Parameters and objects in the body are *local variables*, and *hide* declarations of the same name made in an outer scope.
Objects defined outside functions exist throughout the program's execution, but the lifetime of a local object depends:

#### Automatic Objects
Ordinary local variables are created when the function passes through the variable's definition, and destroyed when control passes through the end of the block in which it is defined.
These are known as *automatic objects*.
Parameters are *automatic objects*
Automatic objects corresponding to parameters are initialized using the function's arguments, otherwise they are default initialized unless they have an initializer.

#### Local `static` Objects
To define a variable whose lifetimes continues across calls to a function, we can define it as `static`.
Each *local `static` object* is defined before the first time the program passes through the object's definition, and are not destroyed when a function ends, but rather when the program terminates.

```C++
size_t count_calls() {
	static size_t ctr = 0;
	return ++ctr;
}
int main() {
	for (size_t i = 0; i != 10; ++i)
		cout << count_calls() << endl;
	return 0;
}
```
In this example, `ctr` is a local `static` object, which is created before any calls to `count_calls`, and is destroyed when the program finishes.


#### Function Declarations
As with any other name, functions can be declared multiple times but defined only once.
A function declaration is just like a definition but with no function body.
Parameter names aren't necessary in a declaration, but can be useful.

```C++
void print(vector<int>::const_iterator beg,
		   vector<int>::const_iterator end);
```

The return type, function name, and parameter types describe the function's interface.
Function declarations are also known as *function prototypes*.

#### Function Declarations Go in Header Files
Pretty much what the title says... if you're going to use a function in multiple source files, declare it in a header file and include that header file in the source file that defines the function.

### 6.1.3 Separate Compilation
Split programs into multiple source files, each compiled independently.

#### Compiling and Linking Multiple Source Files
For example, say `fact` function defined in `fact.cpp` and declared in `Chapter6.hpp`. Have a separate `main` function that calls `fact` in `factMain.cpp`.

We might use `$ CC factMain.cpp fact.cpp -o main` to tell the compiler where to find all of the code we use, but check your own compiler's documentation.


## 6.2 Argument Passing
When a function is called, its parameters are created and initialized by the arguments passed in the call.
This works the same way as variable initialization.
i.e., if the parameter is a reference, then the parameter is bound to its argument... otherwise the argument's value is copied.

When a parameter is a reference, we say the argument is "passed by reference" or the function is "called by reference".
When the argument value is copied, we say the argument is "passed by value" or "called by value".

### 6.2.1 Passing Argument by Value
The value of an argument that is "passed by value" is not changed by a function.

```C++
int n = 0;
int i = n;
i = 42; // value in i changed, n unchanged
```

Passing by value works the same way; the value is copied into the parameter, then nothing the function does changes the argument's value.
For example, inside `fact`, we use 

```C++
ret *= val--;
```

This has no effect on the argument to `fact`... calling `fact(i)` does not decrement `i`.

#### Pointer Parameters
Pointer arguments work the same way, as the value of the pointer is copied, making a distinct pointer from the argument that points to the same object.

```C++
int n = 0, i = 42;
int *p = &n, *q = &i; // p points to n; q points to i
*p = 42; // value in n is changed; p unchaged
p = q; // p now points to i; values in i and n are unchanged.
```

```C++
void reset (int *ip) {
	*ip = 0; // changes value of object to which ip points
	ip = 0; // changes only local copy of ip; argument uncahnged
}
```

```C++
int i = 42;
reset(&i); // changes i but not address of i
cout << "i = " << i << endl; // print i = 0;
```

### 6.2.2 Passing Argument by Reference
Operations on a reference are operations on the object to which the reference refers.
```C++
int n = 0, i = 42;
int &r = n; // r bound to n
r = 42; // n is now 42
r = i; // n now has value of i
i = r; // i has same value as n
```

Reference parameters allow a function to change the value of its arguments.

```C++
void reset(int &i) { // i is another name for object passed to reset
	i = 0; // changes value of object to which i refers
}
```

Reference parameters are bound to their initializers, so in this case, changes to `i` are changes to the object to which `i` refers.
Basically, we are passing an object directly.

```C++
int j = 42;
reset(j); // j passed by reference
cout << "j = " << j << endl; // print j = 0
```

#### Using References to Avoid Copies
Some objects can be very large, or may not be copied.
We can use references to avoid copying objects, but if we don't intend to change an object through its reference, these should be references to const.

```C++
bool isShorter(const string &s1, const string &s2){
	return s1.size() < s2.size();
}
```

#### Using Reference Parameters to Return Additional Information
Functions can only return a single value... however reference parameters effectively let you return multipe results.
We can pass additional reference arguments for multiple outputs:

```C++
// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
string::size_type find_char(const string &s, char c, string::size_type &occurs) {
	auto ret = s.size(); //position of first occurrence, if any
	occurs = 0; // set the occurrence count parameter
	for (decltype(ret) i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (ret == s.size())
				ret = i; // remember the first occurrence of c
			++occurs; // increment the occurrence count
		}
	}
	return ret; // count is returned implicity in occurs
}
```

To call `find_char`, we have to pass three arguments, like so:

```C++
auto index = find_char(s, 'o', ctr);
```

After the call, ctr will be the number of times `o` occurs, and index will refer to the first occurrence if there is one.

### 6.2.3 `const` Parameters and Arguments
As before, top-level `consts` are ignored when copying to initialize an object.
In the following example, we can pass either a `const` or non`const` object:

```C++
void fcn(const int i) { /*  */ }
```

Since the parameter `i` can be initialized from either a `const` or non`const` object, the following is in error:
```C++
void fcn(const int i) { /*  */ }
void fcn(int i) { /*   */ } // error: redefines fcn(int)
```

We'll see later we can define several different functions with the same name, but only if their parameter lists are sufficiently different.

#### Pointer or Reference Parameters and `const`
The same initialization rules for pointers and references and `const` objects apply to parameters:

```C++
int i = 0;
const int ci = i;
string::size_type ctr = 0;
reset(&i); // calls int* version
reset(&ci); // error: can't initialize int* from pointer to const
reset(i); // calls int& version
reset(ci); // error: can't bind plain ref to const object
reset(42); // error: cant bind plain ref to literal
reset(ctr); // error: types don't match; ctr has unsigned type

// ok: find_char's first param is ref. to const
find_char("Hello World!", 'o', ctr);
```

#### Use references to `const` when possible
If we don't need to change an argument's value, use a reference to `const`! This way the function will work with more types (i.e. const objects, literals)

```C++
// bad design: first param. should be const string&
string::size_type find_char(string &s, char c, string::size_type &occurs); 
```

```C++
// fails at compile time, because literal can't initialize string&
find_char("Hello World!", 'o', ctr);
```

Also, if we didn't use a reference to `const`, we couldn't use this function inside other functions that use references to `const`:

```C++
bool is_sentence(const string &s){
	// look for single period at end of s
	string::size_type ctr = 0;
	return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}
```

The call would fail if `find_char` took in a plain `string&`.

### 6.2.4 Array Parameters
We cannot copy an array, and when we use an array it is usually converted to a pointer.
Therefore, we cannot pass an array by value, and when we pass an array as an argument we are actually passing a pointer to the array's first element.

```C++
// all equivalent
void print(const int*);
void print(const int[]);
void print(const int[10]); // dimension for documentation purposes.
```

```C++
int i = 0, j[2] = {0, 1};
print(&i); // ok: &i is int*
print(j); // ok: j converted to int*
```

As always, we must be careful to only access elements of the array that are in range... however, because the size of the array is not ordinarily known, there are several common techniques to manage pointer parameters:

#### Using a Marker to Specify the Extent of an Array
First, if the array contains an end marker (like a C-style character string), we can do something like:

```C++
void print(const char *cp){
	if (cp) // if not null pointer
		while(*cp) // so long as not null character
			cout << *cp++; // print and advance
}
```

This doesn't work well when there's no obvious end marker, like `int` arrays.

#### Using the Standard Library Conventions
Probably the preferred technique in C++ is to pass pointers to the first and one past the last element in the array... this approach is used widely in the standard library.

```C++
void print (const int *beg, const int *end) {
	while (beg != end)
		cout << *beg++ << endl; // print and advance.
}
```

You can call this using the library `begin` and `end` functions:

```C++
int j[2] = {0, 1};
print(begin(j), end(j));
```

#### Explicitly Passing a Size Parameter
Common in C programs and older C++ programs, here we define a second parameter that indicates the size of the array:
```C++
void print(const int ia[], size_t size) {
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << endl;
	}
}
```

```C++
int j[] = {0, 1};
print(j, end(j) - begin(j));
```

#### Array Parameters and `const`
Notice that in each of these example we used pointers to `const`, which we should do if we don't need write access to the array elements.

#### Array Reference Parameters
We can define parameters that are references to arrays:

```C++
void print(int (&arr)[10]) {
	for (auto elem : arr)
		cout << elem << endl;
}
```

Notice that the parentheses are necessary (or else we define an array of 10 references).
Also notice that the size of an array is part of its type, which severely limits the usefulness of this version of `print`, because it can only be called for an array of exactly ten `int`s

#### Passing a Multidimensional Array
We're going to skip... but basically you're passing to a pointer to the first element of an array (with which a multidimensional array, is itself a pointer to the first element of an inner array).

### 6.2.5 `main`: Handling Command-Line Options
Until now, we've defined `main` with an empty parameter list:

```C++
int main() {...}
```

However, we can pass arguments from the command line to `main`, like a set of options.
For example, say we make the following call to our program `prog`:

```C++
prog -d -o ofile data0
```

These are passed into two (optional) parameters:
```C++
int main(int argc, char *argv[]) { ... }
```

Where `argv` is an array of pointers to C-style character strings, and `argc` is the number of strings in that array.
For example, after that call, `argc` would be 5 and 

```C++
argv[0] = "prog";
argv[1] = "-d";
argv[2] = "-o";
argv[3] = "ofile";
argv[4] = "data0";
argv[5] = 0;
```

The element just past the last pointer (`argv[5]`) is guaranteed to be 0.

### 6.2.6 Functions with Varying Parameters
Assuming you know the type of the arguments, but not how many, we can use a library type named `initializer_list`.
If the argument types vary, you could write function templates, which are covered much later in the book (Sec. 16.4).
Note that if you try to use `auto` to specify the type of a parameter, it's actually going to make a function template.

#### `initializer_list` Parameters
An `initializer_list` is a library type representing an array of values of the specified type, whic is defined in the `initializer_list` header.
It's a template type, kind of like a `vector`, so we must specify the type of the elements that the list will contain:

```C++
initializer_list<string> ls;
initializer_list<int> li;
```

The elements in an `initializer_list` are always `const`, and can't be changed.

As an example of using an `initializer_list`, say we want to print different arguments corresponding to different kinds of error messages

```C++
void error_msg(initializer_list<string> il) {
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " " ;
	cout << endl;
}
```

When we pass a sequence of values to an `initializer_list`, we must enclose the sequence in curly braces:

```C++
// expected, actual are strings
if (expected != actual)
	error_msg({"functionX", expected, actual});
else
	error_msg({"functionX", "okay!"});

```

A function with an `initializer_list` parameter could have other parameters as well.

#### Ellipsis Parameters
We're going to skip... mostly for interfacing with C code

## 6.3 Return Types and the `return` Statement
A `return` statement terminates the execution of a function, returning control to the point where the function was called.

```C++
return;
return expression;
```

### 6.3.1 Functions with No Return Value
The first type of `return` statement above can only be used with a function that has a return type of `void`.
Technically the `return` is not necessary (as `void` function implicitly have a return), but it can be used to exit the function before the last statement, sort of like a break.


```C++
void swap(int &v1, int &v2){
	if (v1 == v2)
		return;
	int tmp = v2;
	v2 = v1;
	v1 = tmp;
	// no explicit return necessary.
}
```
### 6.3.2 Functions that Return a Value
The second statement above provides the funciton's result. If the function return type is not void, a value must be returned.
Generally the compiler will try to ensure the type of the return statement is correct, and that functioons are only exited through a valid `return` statement.

```C++
// incorrect return values, this code will not compile
bool str_subrange(const string &str1, const string &str2) {
	// same sizes: return normal equality test
	if (str1.size() == str2.size())
		return str1 == str2; // ok; == returns bool
	// find the size of smaller string;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i])
			return; // error #1: no return value; compiler should detect error
	}

	// error #2: contrl might flow off the end without `return`
	// compiler might not detect this
}
```

#### How Values are Returned
The return value is used to initialize a temporary object at the call site, which is the result of the function call.
This follows the normal rules of initialization... if the return type is a reference, then we return just another name for the object to which it refers. Otherwise, the return value is copied to the call site.

#### Never Return a Reference or Pointer to a Local Object
When a function completes, its storage is freed, so local objects are "destroyed".
Thus, it's an error to return a reference or pointer to a local object, because the object doesn't exist after the function completes:

```C++
const string &manip() {
	string ret;
	// transform ret in some way
	if (!ret.empty())
		return ret; // WRONG: returning reference to local object!
	else
		return "Empty"; // WRONG: "Empty" is a local temporary `string`
}
```

One way to ensure the `return` is safe is to ask what *preexisting* object the reference is referring to or pointer is pointing to.

#### Funcations that Return Class Types and the Call Operator
The call operator has associativity and precedence like any other operator... in particular, it has the same precedence as the dot and arrow operators, which are all left associative. That makes it legal to write statements like:
```C++
// call the size member of the `string` returned by shorterString.
auto sz = shorterString(s1, s2).size();
```

#### Reference Returns are Lvalues
This implies we can use reference returns on the LHS of assignment, for example:

```C++
char &get_val(string &str, string::size_type ix) {
	return str[ix];
}

int main() {
	string s("a value");
	cout << s << endl;
	get_val(s, 0) = 'A';
	cout << s << endl; // prints A value
	return 0;
}
```

As always, if the returned value is a reference to const, we can't assign to it.

#### List Initializing the Return Value
Can use curly braces to return a braced list of values, which are used to initialize temporary that is the function's return:

```C++
vector<string> process() {
	// ...
	// expected and actual are strings
	if (expected.empty())
		return {};
	else if (expected == actual)
		return {"functionX", "okay"};
	else
		return {"functionX", "expected", "actual"};
}
```
#### Return for main
The `main` function is the one exception where a function with a non-`void` return type must return a value.
If there is no return, the compiler implicitly inserts a return of 0.

We can also use the value returned by `main` as a status indicator... to make return values machine independent, the `cstdlib` header defines two preprocessor variables that we can use to indicate success or failure:


```C++
int main()
{
	if (some_failure)
		return EXIT_FAILURE; // defined in cstdlib
	else
		return EXIT_SUCCESS;
}
```

#### Recursion
Just make sure you have something keeping the recursion from running forever!
```C++
int factorial(int val){
	if (val > 1)
		return factorial(val - 1)*val;
	return 1;
}
```

### 6.3.3 Returning a Pointer to an Array
Can't copy an array so can't return one directly... must return a pointer or reference.
The syntax is fairly intimidating though... can use type aliases to make it more straightforward:

```C++
typedef int arrT[10]; // arrT is synonym for the type array of ten ints
using arrT = int[10]; // equivalent

arrT* func(int i); // func returns a pointer to an array of ten ints
```

Just a reminder about how to declare arrays:
```C++
int arr[10]; // arr is array of ten ints
int *p1[10]; // p1 is array of ten pointers
int (*p2)[10] = &arr; // p2 points to array of ten ints
```

The form of a function that returns a pointer to an array is:
```C++
Type (*function(parameter_list))[dimension]
```

For example,
```C++
int (*func(int i))[10];
```
says func is a function that takes in an int, and returns a pointer to an array of ten ints.

#### Using a Trailing Return Type
Can help simplify complicated function declarations:
```C++
auto func(int i) -> int(*)[10];
```

#### Using decltype
If we know the array(s) that the function can return a pointer to:

```C++
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
// returns a pointer to an array of five int elements:
decltype(odd) *arrPtr(int i) {
	return (i % 2) ? &odd : &even; // return pointer
}
```

## 6.4 Overloaded Functions
Functions with the same name, but different parameter lists, appearing in the same scope are called *overloaded*.

```C++
void print(const int char *cp);
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);
```

These functions do the same general task, but use different parameter types. The compiler deduces which function to use based on the argument type we pass:

```C++
int j[2] = {0, 1};
print("Hello World"); // calls print(const char*)
print(j, end(j) - begin(j)); // calls print(const int*, size_t)
print (begin(j), end(j)); // calls print(const int*, const int*)
```

The `main` functtion may not be overloaded.

#### Defining Overloaded Functions
Say we want to find a record based on a name, phone number, account number, and so on...

```C++
Record lookup(const Account&); // find by account
Record lookup(const Phone&);
Record lookup(const Name&);
Account acct;
Phone phone;
Record r1 = lookup(acct);
Record r2 = lookup(phone);
```

Overloaded functions must differ in the number or the type(s) of their parameters.
It's an error for twoo functions to differ only in terms of their return types:
```C++
Record lookup(const Account&);
bool lookup(const Account&); // error
```

#### Determining Whether Two Parameter Types Differ
Parameter names are ignored, so the following are declaring the same function:
```C++
Record lookup(const Account &acct);
Record lookup(const Account&); 
```

```C++
typedef Phone Telno;
Record lookup(const Phone&);
Record lookup(const Telno&); // Telno and Phone same type
```

#### Overloading and `const` Parameters
We mentioned before that top-level const parameters have no effect on the objects that can be passed to the function (because a top-level const can be initialized from a nonconst).

```C++
Record lookup(Phone);
Record lookup(const Phone); // redeclares

Record lookup(Phone*);
Record lookup(Phone* const); // const pointer, redeclares
```

However, we can overload based on whether the parameter is a reference or pointer *to* const or nonconst version of a given type.
These `const`s are low-level:

```C++
Record lookup(Account&);
Record lookup(const Account&); // new function


Record lookup(Account*); // new function
Record lookup(const Account*); // new function
```

The compiler can use the `const`ness of the argument to distinguish which function to call.
Technically, a non`const` object can be used for the `const` versions because you can convert to `const`, but the compiler will prefer the non`const` version.

#### `const_cast` and Overloading
```C++
const string &shorterString(const string &s1, const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}
```

This function returns a reference to a const string, but maybe we'd like to call the function with non`const` strings and return a non`const` string. We can use `const_cast` to achieve this:

```C++
string &shorterString(string &s1, string &s2) {
	auto &r = shorterString(const_cast<const string&>(s1),
							const_cast<const string&>(s2));
	return const_cast<string&>(r);
}
```

#### Calling an Overloaded Function
Once defined, we have to know which overloaded function to call with appropriate argumnents. 
The compiler performs *function matching* to associate a function call with a specific function.
The book talks more about function matching in 6.6, which we're going to skip.

One of three things can happen:

- the compiler finds exactly one function that is a *best match* for the arguments
- there is *no match* when no function's parameters match the arguments. this is an error.
- there is more than one function that matches, and none is clearly best. this is an *ambiguous call*, and is an error.

### 6.4.1 Overloading and Scope
Generally a bad idea to define functions locally... we'll do it here to explain overloading and scope.

There's nothing special going on... as usual, declaring a name in an inner scope hides a name in an outer scope. Names *do not* overload across scopes:

```C++
string read();
void print(const string&);
void print(double);
void fooBar(int ival)
{
	bool read = false; // new scope: hides outer declaration of read
	string s = read(); // error;
	// bad practice: usually bad idea to declare functions at local scope
	void print(int); // new scope: hides previous prints
	print("Value: "); // error
	print(ival); // ok
	print(3.14); // ok: prints 3
}
```

## 6.5 Features for Specialized Uses
### 6.5.1 Default Arguments
Functions with a *default argument* can be called with or without that argument.

For example, we might have a `string` representing a window on screen.

```C++
typedef string::size_type sz;
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
```

We've provided a default argument for each parameter.

#### Calling Functions with Default Arguments
```C++
string window;
window = screen(); // use all default args
window = screen(66); // replace first default arg.
window = screen(66, 256); // replace first and 2nd.
window = screen(66, 256, '#'); // replace all
```

Arguments are resolved by position... default arguments are used for the trailing arguments of the call. For example, can't override default `backgrnd` without first overriding `ht` and `wid`.

```C++
window = screen( , , '?'); // error
window = screen('?'); // calls screen('?', 80, ' ')
```

#### Default Argument Declarations
Although you can declare a function multiple times, each parameter can have its default argument specified only once in a given scope.

#### Default Argument Initializers
Local variables can't be used as default arguments, but basically any other expression can:

```C++
sz wd = 80;
char def = ' ';
sz ht();
string screen(sz = ht(), sz = wd, char = def)
string window = screen(); // calls screen(ht(), 80, ' ')
```

Names used as default arguments are resolved in the scope of the function declaration:
```C++
void f2() {
	def = '*'; // changes value of default argument
	sz wd = 100; // hides outer def of wd but does not change default
	window = screen(); // calls screen(ht(), 80, '*')
}
```

### 6.5.2 Inline and `constexpr` Functions 
Making a short snippet of code into a function has several advantages, however, calling a function can be slower than evaluating an equivalent expression of code.

#### `inline` Functions Avoid Function Call Overhead
A function specified as `inline` is expanded "in line" at each call.

For example, 

```C++
cout << shorterString(s1, s2) << endl;
```

would be expanded into something like

```C++
cout << (s1.size() < s2.size() ? s1 : s2) << endl;
```

We can define `shorterString` to be inline using the `inline` keyword:

```C++
inline const string&
shorterString(const string &s1, const string &s2) {
	return s1.size() <= s2.size() ? s1 : s2;
}
```

The `inline` specification is only a *request* to the compiler that may be ignored, such as if your function is too long.

#### `constexpr` Functions
A `constexpr` function can be used in a constant expression, but must meet certain restrictions.
The return type and each parameter type must be a literal type, and the function body must contain exactly one return statement:

```C++
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz(); // ok
```

`constexpr` functions are implicitly inline.

### 6.5.3 Aids for Debugging
We're going to skip, but basically there's a couple of preprocessor marcos and variables that may help with debugging.

Check out the `assert` macro and `NDEBUG` variables if you're curious.

## 6.6 Function Matching
We're going to skip, but this section details how the compiler chooses which overloaded functions to call.

## 6.7 Pointers to Functions
I think we're also going to skip this section... just know that you can have a pointer to a function rather than an object.
For example:

```C++
bool lengthCompare(const string &, const string &);

bool (*pf)(const string &, const string &); // unitialized

pf = lengthCompare; // pf now points to lengthCompare function
pf = &lengthCompare; // equivalent
```

You can use function pointers to call the function to which the pointer points:

```C++
bool b1 = pf("hello", "goodbye"); // calls lengthCompare
bool b2 = (*pf)("hello", "goodbye"); // equivalent
bool b3 = lengthCompare("hello", "goodbye"); // equivalent
```

For pointers to overloaded functions, the compiler will use the pointer type to deduce which of the overloaded functions to use, which must match one of the overloaded functions exactly.

The rest of the chapter explains how you can pass function pointers as parameters, and how to return pointers to functions, as well as how to use `auto` or `decltype` with function pointer types.