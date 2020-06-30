/*
Exercise 6.44 on p. 238
Rewriting isShorter to be inline
*/
#ifndef EXERCISE_44_HPP
#define EXERCISE_44_HPP

#include <string>
using std::string;

inline bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

#endif