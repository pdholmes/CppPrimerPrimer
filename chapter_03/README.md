# Lecture 03 - Strings, Vectors, and Arrays
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