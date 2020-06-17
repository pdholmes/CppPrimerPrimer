## Exercise 5.1
A null statement is just a semicolon ";", which is the simplest statement. You may want to use such a statement inside of a while loop, where the code requires a statement but you don't actually need it to do anything.

## Exercise 5.2
A block is what's within a pair of curly braces "{ }". This counts a single statement, though can contain multiple statements. Useful when the code requires a single statement, but you wanna do more things (i.e. in a while loop).

## Exercise 5.3
Check exercise_03.cpp, I believe it does improve readability some by making it more condensed.

## Exercise 5.4
(a) I believe the problem here is that iter is created but never initialized. To fix the code we can declare iter outside of the loop.
(b) the variable "status" is used outside of its scope. We could define it before the loop.

## Exercise 5.7
(a) missing semicolon in "ival1 = ival2"
(b) needs curly braces to make it a block
(c) I think the first if will always evaluate true... unless ival is initialized as zero. oops this is fine actually. the online guide points out you should use an "else" instead of a second "if" to keep ival in scope.
(d) this statement will never execute, because you're assigning ival = 0. the author probably meant ival == 0.

## Exercise 5.8
A dangling else occurs when there are multiple if statements before an else statement, so it's unclear which if the else belongs to. In C++, they are resolved by attaching them to the closest preceding unmatched if. You can use curly braces to reduce the ambiguity here.

## Exercise 5.13:
(a) there are no "break"s after case 'a' and case 'e', so these will both cause ioucnt to increment
(b) the variable "ix" is explicitly initialized in case 1, but accessed in the default case, which is not allowed.
(c) only one condition is allowed per case
(d) I believe the problem here is that the case labels are not necessarily constant.

## Exercise 5.15
(a) sz is not initialized, but i assume it is outside of the loop. the final if is unnecessary, because that condition must be false for the loop to have exited. oo also ix is out of scope here
(b) this needs a null statement for the "initializer"
(c) this loop will never end, because sz is increased with each iteration

## Exercise 5.16
ix = 0;
while (ix != sz) {
	\\ do something
	++ix
}

for (ix = 0; ix != sz; ++ix) {
	\\ do something
}

I would choose for loops, because I seem to like them better, but both have their uses.

## Exercise 5.18
(a) The do while loop attempts to accept two ints and add them together, reporting their value. However, the code is missing curly braces for the body of the do.
(b) You can't define a variable inside of the while condition.
(c) Variables used in the condition can't be defined in the body of the do while loop.