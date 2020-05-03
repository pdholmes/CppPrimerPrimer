# Lecture 01 -- Getting Started
## 0.1 Introduction
Hello everyone! Thanks for joining me on this tour of the C++ Primer.

### 0.1.1 Why C++
What is C++ useful for? I don't really know the answer myself... I guess it depends what you want to do with it!

For me, it'd probably be good if I wanted to use it for using ROS (Robot Operating System) or for y'know trying to get a job. But as I've learned more and more it's honestly just kind of fun to know on it's own, and I'm kind of interested in trying to program a simple video game with it.

What about you? Do you have any particular goal you're working towards by learning C++? Or do you think it'd just be a good thing to know?

I searched the internet for "what is C++ used for" and found this site: https://www.educba.com/uses-of-c-plus-plus/ ... seems like a lot of stuff was created (at least partially) using C++, such as:

- Applications (i.e. Adobe Illustrator)
- Games (modern game engines like Unity 3D use it)
- Web Browsers (i.e. Google Chrome)
- Operating Systems (i.e. Windows)

so basically anything. We can also look at a pro/con list:

**Pros**

- Popularity (lots of help online, and many libraries available)
- Portability (can run on basically any platform)
- Speed (code is compiled beforehand, so it runs fast)
- Scalability (low-level control of resources allows for potentially large, complicated programs)

**Cons**

- Complicated (complex syntax can make it difficult to learn, pointers can be tricky)
- Low-level management (also a pro... programmer responsible for memory allocation, not accessing invalid elements in for loops, etc.)

### 0.1.2 What is C++
According to Wikipedia:

>C++ (/ˌsiːˌplʌsˈplʌs/) is a high-level, general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes". The language has expanded significantly over time, and modern C++ now has object-oriented, generic, and functional features in addition to facilities for low-level memory manipulation. It is almost always implemented as a compiled language, and many vendors provide C++ compilers, including the Free Software Foundation, LLVM, Microsoft, Intel, Oracle, and IBM, so it is available on many platforms.

So there you have it! That Bjarne Stroustrup guy comes up pretty often, and is still active in writing books about the language.

Let's go into a little more depth on each point. I don't know much about C, but "classes" will let us define our own objects with the ability to store data and write our own functions to manipulate that object. This is basically what "object-oriented programming" means. 

C++ is "generic", meaning algorithms are implemented in such a way that they don't depend on the type of object we're operating on. For example, we might iterate through a list of numbers {1, 2, 3, 4, 5} or strings of characters {"no", "this", "is", "patrick"} in the same way.

C++ has "functional features", which I think just mean we can write and call functions to perform operations on our objects.

Finally, C++ has facilities for "low-level memory manipulation", meaning we'll be responsible for telling the compiler what each object is, and how much memory to set aside for it.

C++ is a "compiled language", meaning the "source code" we write is translated into "machine code" that a computer can understand before we can run our programs.

C++ got its name from starting out as sort of an iteration of the C language. The postfix (++) operator is used in the language to increment an object, hence C++ is sort of the next step after C.

Interestingly, C++ is standardized by the ISO (International Organization for Standardization), and every three years they come out with a new standard of the language, with "big" updates every 6 years. The current standard is C++17, but C++20 is due out later this year!

### 0.1.3 Course Structure
We'll be using the C++ Primer 5th Edition as the backbone of this course. It's a good book! It can get pretty deep in technical details, but the devil (and many hard-to-catch bugs) is in the details, so I like that. I would recommend getting a physical copy of the book (if that's your thing), because you'll spend a lot of time reading it and flipping back and forth between writing code and looking at the book.

The C++ Primer 5th Edition is based on the C++11 standard. Though this standard is 9 years old now, it still covers the essentials you need to know about C++!

We'll be starting from scratch, so no programming experience is required or expected! All are welcome to join, so if you know of anyone else that wants to join us, feel free to invite them.

Right now, I'm expecting the course to last 12 weeks (Tuesday May 5th - Friday July 10th), but we can see where we get and reevaluate in a couple months.

We'll have two classes a week, with a Lecture at 4:00 PM on Tuesdays and and a Workshop/Discussion section at 4:00 PM on Fridays. The Lecture will mostly be me going through notes and presenting some examples live, while for the Workshop/Discussions we will choose some specific exercises to go over and talk about any topics that are confusing.

Ideally, we can get through a chapter a week, but some of the chapters are a lot longer and will require more time... at a minimum, I think if we get through Chapter 7 (which completes part 1 of the book) that will be a good introduction!

Also, I would recommend trying to do all the exercises in each chapter that we cover. Without that practice, the syntax (and common places to look for bugs) won't really stick! I'll post solutions to the exercises each week before the Friday Workshop. Keep in mind that these will be my own attempt at the answers (with some help from the Internet) so there could be errors! Bonus points for finding them.

### 0.1.4 Disclaimer
My experience with C++ is reading through Chapter 10 of this book... so we will be learning together! Also, I haven't really taught anything, let alone virtually through Zoom, so any feedback you have for me during this would be very helpful. For example, if my constant scrolling is making you motion sick, or I'm tabbing back and forth too much, let me know!


I think that's it for preliminaries... I'll take any questions before we dive in!

Oh right. I set up a course Github here: (**add a link!**) where these lectures and exercise solutions will be posted! Feel free to slack/email me with any questions that come up while you're working through the problems!

## 1.0 Chapter 1 -- Getting Started
The way to learn a new language is to write programs!

We'll need a few basic C++ features introduced in this chapter, and we'll also talk about compiling and running a program.

- Define variables
- Do input/output
- Use a data structure to hold data
- Test whether two books are the same
- Use a loop to process every record

### 1.1 Writing a Simple C++ Program
Every C++ program contains one or more functions, one of which **must** be named `main()`. The OS runs the program by calling `main`.

For example,
```C++
int main() {
	return 0;
}
```

Each function has four elements: a *return type* (`int`), a *function name* (`main`), a (possibly empty) *parameter list* enclosed by parentheses, and a *function body*. The `main` function is required to have a return type of `int`, which is a type that represents integers. Normally, a return value of `0` from `main` indicates success.

Now that we've written our simple program and saved it, we need to compile it and run it! (Cue switching screens.)

### 1.2 A First Look at Input/Output
C++ itself doesn't define any statements for input or output (IO). Instead, C++ includes a **standard library** that provides IO.

Most of the examples in this book use the `iostream` library, so we'll be using it all the time! In particular, two types called an `istream` and an `ostream`, for input and output, will be useful throughout.

In particular, we use the *standard input*, an object of type `istream` named **cin**, to read data from the command line.
We use the *standard output*, an `ostream` object, to write to the command line.

Let's look at an example of how to use these:
```C++
#include <iostream>
int main() {
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 << " and " << v2 << " is " <<
		v1 + v2 << std::endl;
	return 0;
}
```
Let's walk through each part of the program.

`#include <iostream>` tells the compiler we want to use the `iostream` library. The name inside the angle brackets refers to a **header**. If you want to use a library facility, you must include its header. Typically, the `#include` must appear outside any functions, and usually, we put all of them at the beginning of the source file.

The first statement of the function body, `	std::cout << "Enter two numbers:" << std::endl;
`, executes an **expression**. An expression yields a result and is composed of one or more "operands" and (usually) an opeartor. Here, we use the **output operator (`<<`)** to print a message to cout.

The left hand operand to `<<` must be an `ostream` object, and the right hand operand is a value to print. The result of the operator is its left hand operand, which allows us to chain outputs together!

`"Enter two numbers"` is a **string literal**, a sequence of characters enclosed in double quotation marks.

`std::endl` is called a **manipulator**, which ends the current line and "flushes" the buffer associated with the device.

The prefix `std::` indicates that certain names like `cout` and `endl` are defined inside the **namespace** named **std**. Namespaces will allow us to avoid inadvertent collisions between names.

The use the scope operator `::` to say we want to use a certain name within a namespace.

We defined two **variables** named v1 and v2 `int v1 = 0, v2 = 0;`. We define these variables as type `int`, and **initialize** them to 0.

Reading from the standard input is analagous to writing to it. We use the **input operator (`>>`)** to read the input and store it in our variables: `std::cin >> v1 >> v2;`

Finally, the last line uses the output operator to print the output. Note that the library defines versions of `<<` to handle different operands like string literals and `int` values.

### 1.3 A Word about Comments
Everybody loves comments!

The compiler ignores comments, so go nuts.

There's two kinds of comments in C++: single-line and paired.

```C++
// this is a single line comment

/*
this is a paired comment.
anything between the start and end is commented.
* It could be a good idea to start each line with an
* asterisk, but that's a stylistic choice.
Comment pairs do not nest, so /*    */ this is source code. */
*/
```

### 1.4 Flow of Control
Statements normally execute sequentially. **Flow-of-control** statements allow for more complicated executing paths.

#### The `while` Statement
A **`while` statement** repeatedly executes a section of code so long as a given condition is true.
```C++
#include <iostream>

int main() {
	int sum = 0, val = 1;
	while (val <= 10) {
		sum += val;
		++val;
	}
	std::cout << "Sum of 1 to 10 inclusive is "
		<< sum << std::endl;
	return 0;
}
```

Let's go over the new parts of this program.

A `while` has the form
```
while (condition)
	statement
```

A **condition** is an expression that yields a result that is either true or false.
So long as `condition` is true, statement is executed.
After executing `statement`, `condition` is tested again.

In this program, we use the condition `val <= 10` to compare the current value of `val` and `10`.
If `val <= 10`, we execute the following `{ sum += val; ++val; }`.

This is a **block** with two statements.
A block is a sequence of statements enclosed by curly braces `{}`.
We use the **compound assignment operator** `+=`, which is equivalent to writing `sum = sum + val;`.
We also use the **prefix increment operator** `++`, which adds to its operand.
So, `++val` is equivalent to `val = val + 1`.

When the condition becomes false, we exit the `while` loop and print the sum.
Note that if the condition is true indefinitely, the `while` loop will run forever!

#### The `for` Statement
In its simplest form, a `for` statement uses a variable in a condition, and increments that variable after each iteration.

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

Here, we define `val` as part of the `for` statement: `for (int val = 1; val <= 10; ++val)`.
This is called the header of the for statement, which is composed of three parts: an *init-statement*, a *condition*, and an *expression*.


The init-statment `int val = 1` defines an `int` object with value 1.
Note that `val` only exists *within* the for loop.

The condition `val <= 10` is checked each time through the for loop.

The expression `++val` is executed *after* the `for` body.
After executing the expression, the condition is checked.

#### Reading an Unknown Number of Inputs
```C++
#include <iostream>
int main() {
	int sum = 0, value = 0;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}
```

Evaluating the `while` condition executes the expression `std::cin >> value`.
That expression reads the next number from `cin`, and stores the nubmer in `value`.
It returns its left operand, so the condition tests `std::cin`.
This will evaluate to `true` so long as the stream is "valid"... if the stream hasn't encountered an error, it succeeds.
For example, if the stream reads a value that's not an `int`, or hits an **end-of-file**, it will become invalid.
On my Mac, I can enter an end-of-file using `ctrl + d`


#### The `if` Statement
C++ provides an **`if` statement** that supports conditional execution.
```C++
#include <iostream>

int main()
{
	// currVal is the number we're counting; we'll read new values into val
	int currVal = 0, val = 0;
	// read first number and ensure that we have data to process
	if (std::cin >> currVal) {
		int cnt = 1; 	// store the count for the current alue we're processing
		while (std::cin >> val) { 	// read the remaining numbers
			if (val == currVal) 		// if the values are the same
				++cnt; 					// add 1 to cnt
			else { 		// otherwise, print the count for the previous value
				std::cout << currVal << " occurs " << cnt << " times " << std::endl;
				currVal = val; 			// remember the new value
				cnt = 1;				// reset the counter
			}
		}	// while loop ends here
		// remember to print the count for the last value in the file
		std::cout << currVal << " occurs " << cnt << " times " << std::endl;
	} 	// outermost if statement ends here
	return 0;
}
```

The first `if`, `if (std::cin >> currVal)` ensures that the input is nonempty.
The `if` evaluates a condition.
If that condition is true, we execute the block that follows the condition.

The body of the `while` loop contains the second `if` condition: `if (val == currVal)`.
The condition uses the **equality operator** `==` to check if `val` is equal to `currVal`.
If the condition is false, we execute the statement following the `else`.

### 1.5 Introducing Classes
Say we want to write a program to solve a simple bookstore problem that stores transactions, which will contain 3 data elements:

`0-201-70353-X 4 24.99`

The first element is an ISBN (aka book number), the second is the number of copies sold, and the third is the price of each copy.

To do so, we define a **data structure** to represent our transactions.
In C++, we define our own data structures by defining a **class**.
A class defines a type, and a collection of operations related to that type.

Here, we won't define classes, but we will learn a little bit about using them.
To use a class, we need to know

- What is the class name?
- Where is it defined?
- What operations does it suport?

For now, we'll assume the class is named `Sales_item` and it is defined in a header called `Sales_item.h`. 

#### The `Sales_item` Class
As with built-in types, we can define a variable of a class type. For example, 
```C++
Sales_item item;
```
creates an object of type `Sales_item` or "a `Sales_item` object".
We won't get into the details of the `Sales_item` class, but we know that we can

- call a function called `isbn` to fetch the ISBN from a `Sales_item` object.
- use `>>` and `<<` to read and write `Sales_item` objects
- use `=` to assign one Sales_item object to another
- use `+` and `+=` to add two Sales_item objects... here we require both objects have the same ISBN, and add their units sold and price together.

Now, we can write programs that use the `Sales_item` class:
```C++
#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item book;
	std::cin >> book;
	std::cout << book << std::endl;
	return 0;
}
```

(Cue screen change!)
Note that we include the `"Sales_item.h"` header where the Sales_item class is defined.

A more interesting example adds two `Sales_item` objects:
```C++
#include <iostream>
#include "Sales_item.h"

int main() {
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	std::cout << item1 + item2 << std::endl;
	return 0;
}
```

The interesting thing about this program is that the concept of "sum" is defined by the `Sales_item` class.

#### A First Look at Member Functions
The previous program should check whether the objects have the same ISBN before adding them... we'll update this:
```C++
#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn()){
		std::cout << item1 + item2 << std::endl;
		return 0;
	}
	else {
		std::cerr << "Data must refer to the same ISBN" << std::endl;
		return -1;
	}
}
```
We'll only add `item1` and `item2` together if the condition inside `if (item1.isbn() == item2.isbn())` is true.
Here, we're calling a **member function** named `isbn`, which returns the ISBN of the object.
A member function is defined as part of a class, and are sometimes referred to as **methods**.
In `item1.isbn()`, we use the **dot operator (`.`)** to say that we want to call the `isbn` method of `item1`.
Additionally, we use the **call operator ( `()` )**
The parentheses are empty because we are not passing any **arguments**, which we will cover later.

### 1.6 The Bookstore Program
Putting everything together!

```C++
#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item total; // variable to hold the running sum
	// read the first transaction and ensure that there are data to process
	if (std::cin >> total){
		Sales_item trans; // variable to hold data for the next transaction
		// read and process the remaining transactions
		while (std::cin >> trans){
			// if we're still processing the same book
			if (total.isbn() == trans.isbn())
				total += trans; // update the running total
			else{
				// print results for the previous book
				std::cout << total << std::endl;
				total = trans; // total now refers to the next book
			}
		}
		std::cout << total << std::endl; // print the last transaction
	}
	else{
		// no input! warn the user
		std::cerr << "No data?!" << std::endl;
		return -1; // indicate failure
	}
}
```

This program is the most complicated we've seen, but it only uses things we've already seen.

And that sums it up for Chapter 1! Thanks everybody.