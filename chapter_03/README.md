# Chapter 03 - Strings, Vectors, and Arrays
The C++ standard library defines a number of abstract data types.
Two of the most important of these are `string`s and `vector`s, which are abstractions of the built-in array type.

`string`s and `vector`s are defined directly by the C++ langauge, as `int`s or `double`s are for example.
They are defined in the standard library, which we include in our programs.
A `string` is a variable-length sequence of characters.
A `vector` holds a variable-length sequence of objects of a given type, i.e. `double`s, `string`s, or `Sales_item`s.
Arrays are a built-in type that is a more primitive version of these library types, which we'll also cover.

## 3.1 Namespace `using` Declarations
Up until now, we've been using the scope operator (`std::cin`, for example) to access names in the standard namespace.
A `using` declaration allows us to shortcut this and just use `cin`:

```C++
using namespace::name;
```

For example:
```C++
#include <iostream>

using std::cin;
int main()
{
	int i;
	cin >> i; // ok
	cout << i; // error! no using declaration.
	std::cout << i; // ok
	return 0;
}
```

Note that a separate `using` declaration is required for each name.
Note that headers should not use `using` declarations, as the contents of a header are copied into a program's text, so that `using` would apply everywhere.
Also note that from here on, we will assume that the correct `using` declarations and `include` directives have been made, so we can refer to `cin` rather than `std::cin`, for example.

## 3.2 Library `string` Type
A `string` is a variable-length sequence of characters.
We must `include` the string header to use it:

```C++
#include <string>
using std::string;
```

### 3.2.1 Defining and Initializing `string`s
```C++
string s1; // default initialized to empty string
string s2 = s1; // copy initialized
string s3 = "hiya"; // copy of string literal
string s4(10, 'c'); // s4 is cccccccccc
```
An empty string is a string with no characters.
Note that there's difference between "direct initialization" and "copy initialization":
```C++
string s5 = "hiya"; // copy initialization
string s6("hiya"); // direct initialization
```

### 3.2.2 Operations on `string`s
The `string` class defines the operations we can perform on them.

#### Reading and Writing Strings
```C++
// remember, we assume
// include and using declarations
// have been made.
int main()
{
	string s;
	cin >> s;
	cout << s << endl;
	return 0;
}
```

Input operator disregareds leading whitespace, and reads until next whitespace character is encountered.
For example, reading `     Hello World!` into a string would yield `Hello`.

We can also chain them together:
```C++
string s1, s2;
cin >> s1 >> s2;
cout << s1 << s2 << endl;
```

For example, reading `     Hello World!` in this program would yield `HelloWorld!`.

#### Reading an Unknown Number of `string`s
```C++
int main()
{
	string word;
	while (cin > word)
		cout << word << endl;
	return 0
}
```

#### Using `getline` to Read an Entire Line
We can use `getline` to read an entire line instead of `<<`:
```C++
int main()
{
	string line;
	while (getline(cin, line))
		cout << line << endl;
	return 0;
}
```

#### The `string` `empty` and `size` Operations
There's also the `empty` and `size`  member functions.

`empty` returns a bool indicating if the `string` is empty:
```C++
while getline(cin, line)
	if (!line.empty())
		cout << line << endl;
```

`size` returns the length of a `string` (i.e. the number of characters in it.)
```C++
string line;
while (getline(cin, line))
	if (line.size() > 80)
		cout << line << endl;
```
#### The `string::size_type` Type
You might imagine that `size` returns an `int`, but actually it returns a `string::size_type` type.
This is a *companion type* that makes it possible to use library types in a machine-independent manner.
We don't know what precise type it is, but we know it's `unsigned`, and large enough to hold any `string`'s size.
You should use `string::size_type` when holding the size of a string, and can use `auto` so you don't type so much.

```C++
// len has type string::size_type
auto len = line.size();
```

#### Comparing `string`s
`==` and `!=`... if `string`s ar exactly the same, they are equal (same length, same characters, case sensitive).
`<`, `<=`, `>`, `>=` same as a case-sensitive dictionary:

- If two `string` different lengths, but all characters of shorter string are equal to corresponding characters of longer string, then the shorter string is `<` longer string.
- If any characters differ, then result depends on first character that differs.

```C++
string str = "Hello";
string phrase = "Hello World";
string slang = "Hiya";

// str < phrase
// slang > str and slang > phrase
```

#### Assignment for `string`s
Can assign one string object to another.

#### Adding Two Strings
Same as concatentation:
```C++
string s1 = "hello, ", s2 = "world\n";
string s3 = s1 + s2; // s3 is hello, world\n
s1 += s2; // same as s1 = s1 + s2
```

#### Adding Literals and `string`s
As we saw before, type conversions automatically occur when another type is expected and a conversion exists.
Character literals and character string literals are not themselves `string`s, but a conversion exists:

```C++
string s1 = "hello", s2 = "world";
string s3 = s1 + ", " + s2 + '\n';
```

Note that to use the `+` operation, at least one operand must be a string, as `+` is not defined for character or string literals.
```C++
string s4 = s1 + ", "; // ok
string s5 = "hello" + ", "; // error, no string operand
string s6 = s1 + ", " + "world"; //ok!
// same as:
string s6 = (s1 + ", ") + "world";

string s7 = "hello" + ", " + s2; // error
```

### 3.2.3 Dealing with the Characters in a `string`
Want to access characters... we may want to iterate through all of them, or access only a specific one.
We may also want to know/change the characteristics of a character... useful functions appear in the `cctype` header!

#### Range-Based For
If we want to do something with each character in a string, the C++11 standard provides a `range for` statement that iterates through all elements of a given sequence:

```C++
for (declaration : expression)
	statement
```

```C++
string str("some string");
for (auto c : str)
	cout << c << endl;
```

A more complicated example for counting punctuation characters:
```C++
#include <cctype> 
//...
string s("Hello World!!!");
decltype (s.size()) punct_cnt = 0;
for (auto c : s)
	if (ispunct(c))
		++punct_cnt;
cout << punct_cnt <<
	" punctuation characters in " <<
	s << endl;
```

#### Using a Range for to Change the Characters in a `string`
If we want to change the value of the characters, we have to define the loop variable as a reference type:
```C++
string s("Hello World!");
for (auto &c : s)
	c = toupper(c);
cout << s << endl;
```

#### Processing Only Some Characters?
We can access individual characters in a `string` using a subscript or an iterator, which we'll cover more later.
The subscript operator (`[]`) takes a `string::size_type` that denotes the position of the character we want to access.
It returns a reference to the character at that position.

Subscripts start at `0`. Assuming `s` is at least two characters long, `s[0]` is the first element, `s[1]` is the second, and `s[s.size() - 1]` is the last.
Note, the subscript must be `>= 0` and `< size()`.
Outside of this range the result is undefined, and therefore subscripting an empty string is undefined.

```C++
if (!s.empty())
	cout << s[0] < endl;
```

```C++
string s("some string");
if (!s.empty())
	s[0] = toupper(s[0]);
```

#### Using a Subscript for Iteration
```C++
for (decltype(s.size()) index = 0;
	index != s.size() && !isspace(s[index]);
	++index)
	s[index] = toupper(s[index]);
```

This program generates `SOME string`.

Subscripts are not checked by C++, so it's up to us to make sure they are in range!!!

#### Using a Subscript for Random Access
```C++
const string hexdigits = "0123456789ABCDEF";
cout << "Enter a series of numbers between 0 and 15" << 
	" separated by spaces. Hit ENTER when finished: " <<
	endl;
string result;
string::size_type n;
while (cin >> n)
	if (n < hexdigits.size())
		result += hexdigits[n];
cout << "Your hex number is: " << result << endl;
```

If we give the program `12 0 5 15 8 15`, the output will be `Your hex number is: C05F8F`.

## 3.3 Library `vector` Type
A `vector` is a collection of objects, all of the same type.
A `vector` is a type of `container`: each object is given an associated index which gives access to that object.
We must include the `vector` header file to use them.

```C++
#include <vector>
using std::vector;
```

A `vector` is a *class template*... depending on the type of object we want to hold, the compiler will *instantiate* the corresponding type from the `vector` template:

```C++
vector<int> ivec;
vector<Sales_item> Sales_vec;
vector<vector<string>> file;
```

### 3.3.1 Defining and Initializing `vector`s
```C++
vector<string> svec; // svec has no elements
```

We'll see that we can efficiently add elements to `vector`s at run time, so empty `vector`s can still be useful.
We can also supply initial values for the elements in a `vector`:

```C++
vector<int> ivec;
// give ivec some values
vector<int> ivec2(ivec);
vector<int> ivec3 = ivec;
vector<string> svec(ivec2); // error
```

#### List Initializing a `vector`
```C++
vector<string> articles = {"a", "an", "the"};
```

```C++
vector<string> v1{"a", "an", "the"};
vector<string> v2("a", "an", "the"); // error
```

#### Creating a Specified Number of Elements
```C++
vector<int> ivec(10, -1); // ten ints, each -1
vector<string> svec(10, "hi!"); // ten strings, each "hi!"
```

#### Value Initialization
```C++
vector<int> ivec(10); // ten ints, each 0
vector<string> svec(10); // ten strings, each empty
```

`vector`s of built-in type are value initialized to 0.
Elements of class type are default initialized... so a default initialized must exist.

And you can't do this to specify a size:
```C++
vector<int> vi = 10;
```
because it thinks you're trying to copy 10 into the `vector`.

#### List Initializer or Element Count?
```C++
vector<int> v1(10); // 10 elements, each 0
vector<int> v2{10}; // 1 element, value 10
vector<int> v3(10, 1); // 10 elements, each 1
vector<int> v4{10, 1}; // 2 elements, values 10 and 1
```

Put simply, parentheses tell the compiler how you want to construct the vector, while curly braces tell the compiler what values you want to give the elements.
If it's not possible to give the value in the curly brace (i.e. types don't match), then the compiler will try to use those values to construct the object:

```C++
vector<string> v5{"hi"}; // 1 element, "hi"
vector<string> v6("hi"); // error
vector<string> v7{10}; // 10 elements, each empty
vector<string> v8{10, "hi"}; // 10 elements, each "hi"
```
### 3.3.2 Adding Elements to a `vector`.
We use the `push_back` member to add elements to `vector`s at run time.
It "pushes" the value as a new last element on the "back" of the `vector`.

```C++
vector<int> v2;
for (int i = 0; i != 100; ++i)
	v2.push_back(i);
```

```C++
string word;
vector<string> text;
while (cin >> word) {
	text.push_back(word);
}
```

*Note:* `vector`s grow efficiently, so usually it's faster to avoid prespecifying the size of the `vector` (if not all elements have the same value).

#### Programming Implications of Adding Elements to a `vector`
Adding elements to `vector`s is easy and efficient.
However, we have to be careful when writing loops that change the size of the `vector`.
In particular, we can't use a `range for` if the loop body adds elements to the `vector`.

### 3.3.3 Other `vector` Operations
`vector`s share many of the same operations as `string`s.
In particular, `range for`s work the same:

```C++
vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
for (auto &i : v)
	i *= i;
for (auto i : v)
	cout << i << " ";
cout << endl;
```

The `empty` and `size` members are the same as well, but the `size_type` of the `vector` depends on its type:
```C++
vector<int>::size_type // ok
vector::size_type // error
```

Equality and relational operators are the same as strings, but depend on the types of objects the `vector`s hold.


#### Computing a `vector` Index
Say we have a bunch of grades, and we want to see how many are in each interval of 10.
For example, given the input 
`42 65 95 100 39 67 95 76 88 76 83 92 76 93`
we would want the output
`0 0 0 1 1 0 2 3 2 4 1` meaning 0 scores in 0 - 9 range, ..., 1 score in 30-39 range... 4 scores in 90 - 99 range, and 1 score of 100.

We'll use a vector to hold the counters of each cluster:
```C++
vector<unsigned> scores(11, 0);
unsigned grade;
while (cin >> grade) {
	if (grade <= 100) {
		++scores[grade/10];
	}
}
```

The expression `grade/10` gets the correct subscript index.

#### Subscripting Does Not Add Elements
Subscripting fetches an existing element; it does not add elements!
```C++
vector<int> ivec;
for (decltype(ivec.size()) ix = 0; ix != 10; ++ix) {
	ivec[ix] = ix; // ivec has no elements; can't subscript!
}
```

Instead we should use `push_back`
```C++
vector<int> ivec;
for (decltype(ivec.size()) ix = 0; ix != 10; ++ix) {
	ivec.push_back(ix);
}
```

Again, we must be careful only using subscripts to elements in range.
Subscripting an element out of range is called a *buffer overflow* error.

## 3.4 Introducing Iterators
Iterators are a more general way for accessing elements of `vector`s than subscripting.
We'll see later that there are other library containers which may not support subscripts, but all support iterators.

Iterators, like pointers, give indirect access to an element.

### 3.4.1 Using iterators
Unlike pointers and the address-of operator, we use the `begin()` and `end()` member functions to get an iterator.

```C++
auto b = v.begin(), e = v.end();
```

The iterator returned by `end` is *one past the end* of the container.
If the container is empty, `begin` and `end` return the same iterator.
Generally, we don't know (and don't care) about the type of the iterator.

#### Iterator Operations
We dereference iterators to obtain the element denoted by an iterator.
We can only dereference a *valid* iterator that is not an off-the-end iterator.

```C++
string s("some string");
if (s.begin() != s.end()) {
	auto it = s.begin();
	*it = toupper(*it);
}
```

#### Moving Iterators from One Element to Another
Iterators use the increment operator (++) to "advance the iterator to the next position".
Can't use on the iterator returned by `end`.

```C++
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
	*it = toupper(*it);
}
```

Note, we use `it != s.end()` instead of `it < s.end()` because some iterators for other container types don't have the relational `<` operator, but all have `==` and `!=`.

#### Iterator Types
Again, we don't know the precise type an iterator has, much like with `string::size_type`.
The library types defined types named `iterator` and `const_iterator` that represent actual iterator types.

*pro tip* just use `auto` with the `begin` and `end` members.

```C++
vector<int>::iterator it;
string::iterator it2;

vector<int>::const_iterator it3;
string::const_iterator it4;
```

`const_iterator`s are very similar to pointers to `const`... we can read, but can not write through them. We must use `cost_iterator`s if a `vector` or `string` is `const`.

#### The `begin` and `end` operations
`begin` and `end` return `const` iterators if the object is `const`:

```C++
vector<int> v;
const vector<int> cv;
auto it1 = v.begin(); // type vector<int>::iterator
auto it2 = cv.begin(); // type vector<int>::const_iterator
```

We can also explicitly request a `const_iterator` (i.e. we don't want to change the element) using `cbegin()` and `cend()`.
```C++
auto it3 = v.cbegin();//
```

#### Combining Dereference and Member Access
Say we have a `vector` of `string`s, and want to access a string element's members:
```C++
(*it).empty() // dereferences it and calls member
*it.empty() // attempts to fetch member `empty` from it...
// parentheses are necessary!
```

To simplify expressions like these, the language defines the arrow operator (->) to combine dereference and member access.

```C++
for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
	cout << *it << endl;
}
```

#### Some `vector` Operations Invalidate Iterators
Any operation, such as `push_back()`, that changes the size of a `vector` may invalidate all iterators into that `vector`.
Loops that use iterators should not add elements to the container.

### 3.4.2 Iterator Arithmetic
Incrementing an iterator moves the iterator one element at a time, and we can use `==` and `!=` to compare them.
Iterators for `string` and `vector` support additional operations:

```C++
iter + n
iter - n
iter1 += n
iter1 -= n
iter1 - iter2
>, >=, <, <=
```

#### Arithmetic Operations on Iterators
```C++
auto mid = vi.begin() + vi.size() / 2;
```
If vi has 20 elements, then `vi.size()/2` is 10.
`mid` is equivalent to `vi[10]`.

#### Using Iterator Arithmetic
Binary search example:

```C++
// text must be sorted
auto beg = text.begin(), auto end = text.end();
auto mid = text.begin() + (end - beg)/2;

while (mid != end && *mid != sought) {
	if (sought < *mid)
		end = mid;
	else
		beg = mid + 1;
	mid = beg + (end - beg)/2;
}
```

## 3.5 Arrays
Similar to a `vector`... but fixed size. Can't add elements!
Can sometimes offer better run-time performance, at the cost of flexibility.

### 3.5.1 Defining and Initializing Built-in Arrays.
An array is a compound type (like pointers and references), defined in terms of another "base" type.
The dimension (number of elements) is part of the array's type, so it must be known at compile time, and therefore must be a constant expression.

```C++
unsigned cnt = 42; //not constant expression.
constexpr unsigned sz = 42;

int arr[10]; // array of ten ints
int *parr[sz]; // array of 42 ptrs to int
string bad[cnt]; // error: cnt not constant expr.
string strs[get_size()]; // ok if get_size is constexpr
```

Default-initialized arrays defined inside functions have undefined values.
Can't use `auto` to deduce type from initializers.

#### Explicitly Initializing Array Elements
Can list-initialize array, don't need to specify dimension.
If specified dimension > # of initializers, the rest of the elements are value initialized.
```C++
const unsigned sz = 3;
int ia1[sz] = {0, 1, 2};
int a2[] = {0, 1, 2};

//same as {0, 1, 2, 0, 0}:
int a3[5] = {0, 1, 2};

//same as {"hi", "bye", ""}
string a4[3] = {"hi", "bye"};

//error
int a5[2] = {0 ,1, 2};
```

#### Character Arrays are Special
We can initialize character arrays from string literals... remember that string literals end with a null character.

```C++
char a1[] = {'C', '+', '+'};
char a2[] = {'C', '+', '+', '\0'}; // explicit null
char a3[] = "C++"; // same as a2
const char a4[6] = "Daniel"; // error: no space for null!
```

#### No Copy or Assignment
Though your compiler may have it as a compiler extension, it is illegal to copy an array, or assign one array to another:
```C++
int a[] = {0, 1, 2};
int a2[] = a; // error
a2 = a; // error
```

#### Understanding Complicated Array Declarations
Like `vector`s, arrays can hold elements of many types, like an array of pointers. 
We can also define pointers and references to arrays.

```C++
int *ptrs[10]; // 10 ptrs to int
int &refs[10]; // error: no array of references
int (*Parray)[10] = &arr; // ptr to array of ten ints
int (&arrRef)[10] = arr; // ref to array of ten ints
```

...easiest read inside out.
```C++
int *(&arry)[10] = ptrs; // ref to array of 10 ptrs.
```

### Accessing the Elements of an Array
Can use range for or subscripting to access elements.
type `size_t` when using a variable to subscript an array. defined in `cstddef` header, can hold any object in memory.

We can rewrite the grading example:
```C++
unsigned scores[11] = {}; // value initialized to 0
unsigned grade;
while (cin >> grade)
	if (grade <= 100)
		++scores[grade/10];
```

range for example:
```C++
for (auto i : scores)
	cout << i << " ";
cout << endl;
```

Again, be careful that your subscripts are in range before using them!

### 3.5.3 Pointers and Arrays
Pointers and arrays are closely intertwined...

Usually we get a pointer using the address-of operator:
```C++
string nums[] = {"one", "two", "three"};
string *p = &nums[0]; // ok
```

In most places we use an array, the compiler automatically substitutes a pointer to the first element.
```C++
string *p2 = nums; // equivalent to p2 = &nums[0]
```

Operations on arrays are often really operations on pointers.
For example, using `auto` the deduced type is a pointer, not an array.
```C++
int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
auto ia2(ia); // ia2 is int*, points to first element of ia
//same as:
auto ia2(&ia[0]);

ia2 = 42; // error: ia2 is a pointer.
```

This is not true with `decltype`, which deduces the array type.

#### Pointers are Iterators
We can use pointers to arrays much the same way as iterators to `vector`s or `string`s.
For example, we can increment them, or test for equality:

```C++
int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *p = arr; // p points to first element
++p; // p points to arr[1] now.

int *e = &arr[10] // "off-the-end" pointer

for (int *b = arr; b != e; ++b) {
	cout << *b << endl;
}
```

#### The Library `begin` and `end` functions
A less error-prone way to compute the off-the-end pointer is to use the library `end` function, in the `iterator` header:

```C++
int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *beg = begin(ia);
int *last = end(ia);
```

```C++
int *pbeg = begin(arr), *pend = end(arr);
while (pbeg != pend && *pbeg >= 0)
	++pbeg;
```

#### Pointer Arithmetic
Just like with iterators, we can add or subtract integral values to pointers to array elements.
Be careful to make sure the pointer is still in range, and don't dereference an off-the-end pointer!

```C++
constexpr size_t sz = 5;
int arr[sz] = {1, 2, 3, 4, 5};
int *ip = arr; 
int *ip2 = ip + 4; // points to arr[4]

//ok: arr converted to pointer
// p points one past the end of arr
int *p = arr + sz; // 
int *p2 = arr + 10; // error, only 5 elements.
```

```C++
auto n = end(arr) - begin(arr); // n is 5
```

Can use relational operators to compare pointers to elements of the same array, not between arrays though:
```C++
int *b = arr, *ee = arr + sz;
while (b < e) {
	//use *b
	++b;
}
```

#### Interaction between Dereference and Pointer Arithmetic
```C++
int ia[] = {0, 2, 4, 6, 8};
int last = *(ia + 4); // ok, last is 8

last = *ia + 4; // ok, last is 4.
```

#### Subscripts and Pointers
Subscripting with arrays is really just using pointers...
```C++
int ia[] = {0, 2, 4, 6, 8};

// ia is converted to a pointer
// ia[2] fetches the element to which
// (ia + 2) points
int i = ia[2];

int *p = ia;
i = *(p + 2); // equivalent to above
```

We can use the subscript operator on any pointer, as long as that pointer points to an element
```C++
int *p = &ia[2];
int j = p[1]; // same as ia[3]
int k = p[-2]; // same as ia[0]
```
Importantly, the indexes may be signed for the built-in array subscript, but must be unsigned for subscripts to `vector` or `string`.

#### C-Style Character Strings
"Character string literals" or C-style character strings are character arrays that are *null-terminated*.

#### C Library String Functions
Found in `cstring` header, useful functions for dealing with C-Style Character Strings like `strlen`, `strcmp`, `strcat`, `strcpy`.
C-style character strings must be null-terminated!

```C++
char ca[] = {'C', '+', '+'}; // not null-terminated
cout << strlen(ca) << endl; // disaster
```

#### Comparing Strings
Using library strings:
```C++
string s1 = "A string example";
string s2 = "A different string";
if (s1 < s2) // false: s2 < s1
```

This doesn't work with C-style strings, as it compares the pointer values, not the strings themselves
```C++
const char ca1[] = "A string example";
const char ca2[] = "A different string";

// undefined: compares two unrelated addresses
if (ca1 < ca2) 
```

We can call `strcmp` instead:
```C++
if (strcmp(ca1, ca2), < 0)
```

#### Caller is Responsible for Size of a Destination String
Adding strings together is easy with library `string`s:
```C++
string largeStr = s1 + " " + s2;
```

Doing so with C-style strings is more error-prone, because we must pass an array to hold the resulting string:
```C++
strcpy(largeStr, ca1);
strcat(largeStr, " ");
strcat(largeStr, ca2);
```

If we miscalculate the size needed for `largeStr`, it can lead to serious error.

*pro tip* just use library `string`s

### 3.5.5 Interfacing to Older Code
#### Mixing Library `string`s and C-style Strings
We can use string literals to initialize library `string`s, and the `+` operator to add string literals to library `string`s.

```C++
string s("Hello World");
```
More generally, we can use null-terminated character arrays anywhere we can use a string literal.
The reverse functionality is not provided... however, the `string` type has a member function `c_str()` that returns a C-style character string:

```C++
char *str = s; // error
const char *str = s.c_str(); // ok
```

Changing s may invalidate this array however (i.e., the pointer may no longer be valid).

#### Using an Array to Initialize a Vector
We can initialize a `vector` from an array by passing pointers marking the range of values to use.
```C++
int int_arr[] = {0, 1, 2, 3, 4, 5, 6};
vector<int> ivec(begin(int_arr), end(int_arr));

vector<int> subVec(int_arr + 1, int_arr + 4);
```

*pro tip* use library types instead of arrays.

## 3.6 Multidimensional Arrays
We're going to skip this subsection, but in summary multidimensional arrays are just arrays that hold arrays.
