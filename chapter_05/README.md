# Chapter 05 - Statements
C++ statements provide functionality for conditional execution, loops, and jump statements.
Statements are executed sequentially... *flow-of-control* statements allow more complicated execution paths.

## 5.1 Simple Statements
An expression becomes an *expression statement* when it is followed by a semicolon.
This causes the expression to be *evaluated* and the result discarded.

```C++
ival + 5; // useless
cout << ival; // useful
```

### Null Statements
Simplest statement is the *null statement*

```C++
;
```
 
boom. Useful where statement required, but the user doesn't need one
```C++
while(cin >> s && s != sought)
	; // statement required
// while does all the work.
```

Pro tip: comment null statements so people know they're on purpose

### Beware of Missing or Extraneous Semicolons
```C++
ival = v1 + v2;; // ok...  null statement
```

```C++
// disaster!
// extra semicolon, ++iter is not in loop
while (iter != svec.end()) ;
	++iter;
```

### Compound Statements (Blocks)
A *block* is a sequence of statements surrounded by a pair of curly braces.
A block is a scope.

For example, `while` or `for` loops require a single statement, so if we want to execute more than one, we put them in a block.
```C++
while (val <= 10) {
	sum += val;
	++val;
}
```

Note, no semicolon! Empty blocks are also fine `{ }`, same as null statement.

## 5.2 Statement Scope
Variables defined in the control structure of `if`, `switch`, `while`, and `for` are out of scope after statement ends:
```C++
while (int i = get_num())
	cout << i << endl;
i = 0; // error: i not accessible outside loop
```

If we want to access such a variable, we must define it outside of the statement.
```C++
// find the first negative element
auto beg = v.begin();
while (beg != v.end() && *beg >= 0)
	++beg;
if (beg == v.end())
	// we know all elements in v are >= 0
```

## 5.3 Conditonal Statements
### 5.3.1 The `if` Statement
`if` and `if else` statements:
```C++
if (condition)
	statement

if (condition)
	statement1
else
	statement2
```

Condition must be in parentheses!

#### Using an `if else` statement
```C++
const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

string lettergrade;
if (grade < 60)
	lettergrade = scores[0];
else
	lettergrade = scores[(grade - 50)/10];
```

#### Nested `if` Statements
```C++
// add + or -
if (grade % 10 > 7)
	lettergrade += '+';
else if (grade % 10 < 3)
	lettergrade += '-';
```

```C++
string lettergrade;
if (grade < 60)
	lettergrade = scores[0];
else {
	lettergrade = scores[(grade - 50)/10];
	if (grade != 100)
		if (grade % 10 > 7)
			lettergrade += '+';
		else if (grade % 10 < 3)
			lettergrade += '-';
}

```

Watch your braces!! plus or minus added unconditionally:
```C++
string lettergrade;
if (grade < 60)
	lettergrade = scores[0];
else 
	lettergrade = scores[(grade - 50)/10];
	if (grade != 100)
		if (grade % 10 > 7)
			lettergrade += '+';
		else if (grade % 10 < 3)
			lettergrade += '-';
```

Good idea may be to always curly braces.

#### Dangling `else`
![](misc/dangling_elsa.jpeg)

No not a dangling Elsa. A dangling `else` happens when you have more `if`s than `else`s. For example:
```C++
// dangling else
// execution does not match indentation
if (grade % 10 >= 3)
	if (grade % 10 > 7)
		lettergrade += '+';
else
	lettergrade += '-';
```

in this program, grades ending in 3, 4, 5, 6, or 7 get a `-`. In C++ dangling `else`s are handled by matching them with the closest preceding unmatched `if`.
```C++
// dangling else
// this is actually what's happening:
if (grade % 10 >= 3)
	if (grade % 10 > 7)
		lettergrade += '+';
	else
		lettergrade += '-';
```

#### Controlling the Execution Path with Braces
Name says it all... to clear up ambiguity, we can use braces:
```C++
// no more dangling else
if (grade % 10 >= 3) {
	if (grade % 10 > 7)
		lettergrade += '+';
} else
		lettergrade += '-';
```

### 5.3.2 The `switch` Statement
Select among a (possibly large) number of fixed alternative.
For example, suppose we want to count how often each vowel appears in a segment of text.

```C++
unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
char ch;
while (cin >> ch) {
	switch (ch) {
		case 'a':
			++aCnt;
			break;
		case 'e':
			++eCnt;
			break;
		case 'i':
			++iCnt;
			break;
		case 'o':
			++oCnt;
			break;
		case 'u':
			++uCnt;
			break;
	}
}
```

`switch` executes by evaluating the parenthesized expression, then comparing the result with the value of each *case label*.
If it matches, execution starts with first line after case.
Note, execution continues until the end of the `switch` or a `break` statement!

Case labels must be integral constant expressions, and no two case labels can have the same value.

```C++
char ch = getVal();
int ival = 42;
switch(ch) {
	case 3.14: // error
	case ival: // error: non const
	//
}
```

#### Control Flow within a `switch`
We can let the program "fall through" multiple case labels by omitting break statements.
```C++
unsigned vowelCnt = 0;
// ...
switch(ch) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		++vowelCnt;
		break;
}
```
Alternatively:
```C++
unsigned vowelCnt = 0;
// ...
switch(ch) {
	case 'a': case 'e': case 'i': case 'o': case 'u':
		++vowelCnt;
		break;
}
```

#### Forgetting a `break` is a common source of bugs
Name pretty much says it all. 

#### The `default` label
When no case label matches, statements following the *default label* are executed:
```C++
// if ch is a vowel increment the appropriate counter
switch (ch) {
	case 'a': case 'e': case 'i': case 'o': case 'u':
		++vowelCnt;
		break;
	default:
		++otherCnt;
		break;
}
```

You can define a `default` label even if it's empty, just put a null statement or empty block.

#### Variable Definitions inside the Body of a `switch`
> Illegal to jump over an initialization if the initialized variable is in scope at the point to which control transfers.

Basically, if you have to define and initialize a variable within a particular case of a `switch`, put it inside a block, so that it's not in the scope of the rest of the `switch`.

## 5.4 Iterative Statements
Repeated execution until a condition is true.

### 5.4.1 The `while` statement
... there's not much to add here. Variables defined in a `while` condition or `while` body are created and destroyed on each iteration.

### 5.4.2 Traditional `for` statement
...not much new to say here either.

#### Execution Flow in a Traditional `for` Loop
...not much new to say.

#### Multiple Definitions in the `for` Header
Can define multiple objects in the init-statement:
```C++
for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i)
	v.push_back(v[i]);
```

#### Omitting Parts of the `for` Header
```C++
auto beg = v.begin();
for ( /* null */ ; beg != v.end() && *beg >= 0; ++beg)
	; // no work to do
```

Can omit the condition too, but must have some way to break out of the loop.

Can omit the expression, but should advance the iteration in the loop body.
```C++
vector<int> v;
for (int i; cin >> i; /* no expression */ )
	v.push_back(i);
```

### 5.4.3 Range `for` statement
Again, not much new to say, but we can see what a range `for` actually does:

```C++
vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8. 9};

for (auto &r : v)
	r *= 2;

// equivalently:
for (auto beg = v.begin(), end = v.end(); beg != end; ++beg) {
	auto &r = *beg;
	r *= 2;
}
```

Notice that the `end` is cached, and for this reason we can change the size of the sequence.

### 5.4.4 The `do while` statement
Basically, a `while` loop that is guaranteed to execute at least once:
```C++
do
	statement
while (condition); // <- note semicolon
```

The statement in `do` is executed *before* condition is evaluated.

## 5.5 Jump Statements
`break`, `continue`, `return` (Chapter 6), `goto` (we will skip)

### 5.5.1 The `break` Statement
A *break statement* terminates the nearest enclosing `while` `do while` `for`, or `switch` statement.
It can only appear inside one of these statements, and only terminates the nearest enclosing loop or switch.

```C++
while (cin >> word) {
	if (word == prev_word) {
		msg = word + " was repeated!";
		break;
	}
	prev_word = word;
}

cout << msg << endl;
```

### 5.5.2 The `continue` statement
A *continue statement* terminates the current iteration and continues to the next iteration of a `while`, `do while`, or `for` loop.
In a nested loop, it affects only the nearest enclosing loop.

```C++
string buf;
while (cin >> buf && !buf.empty()) {
	if (buf[0] != '_')
		continue; // get another input
	// still here?
	// the input starts with an underscore
	// process buf
}
```

### 5.5.3 The `goto` Statement
The book says don't use `goto` statements... we'll just look at what they are.

In the Legend of Zelda: Ocarina of Time (and probably some others) you can obtain a spell called Farore's Wind where you can set a point in a dungeon and automatically return to it... that's basically a `goto` statement.

![](misc/farores_wind.png)

```C++
begin:
	int sz = get_size();
	if (sz <= 0) {
		goto begin;
	}
```

We create a "labeled statement" using `begin:`, and then can jump to it. There's some intricacies where you can't jump *over* an initialized variable definition though, so jumping forward is harder.

## 5.6 `try` Blocks and Exception Handling
We're going to skip this section, but go ahead and take a read if you're interested.
Basically, *exceptions* are run-time anomalies.
When a part of a program runs into a problem it can't resolve itself, it can "throw" an exception, raising the issue with another part of the program responsible for "handing" exceptions.
This is done using a "try" block, which "catches" the exeptions.

So, you "try" to run the program, but have abilities to "catch" runtime anomalies.
The standard library also has several standard exceptions you can use.