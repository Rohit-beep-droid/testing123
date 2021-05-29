//
// Created by DELL on 3/30/2021.
//

#ifndef LAB0801_RECURSION_H
#define LAB0801_RECURSION_H
#include <string>


/*
Given a non-negative int n, return the count of the occurrences of 7 as a digit, so for example 717 yields 2. (no loops).
Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
count7(717) → 2
count7(7) → 1
count7(123) → 0
*/
unsigned int count7( unsigned int n );

/*
Given a non-negative int n, return the product of each digit, so for example 717 yields 49 (7*1*7). (no loops).
Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
product(0) → 0
product(717) → 49
product(7) → 7
product(123) → 6
*/

unsigned int product( unsigned int n );
/*
Given a string, return true if it is a nesting of zero or more pairs of parenthesis, like
"(())" or "((()))". Suggestion: check the first and last chars, and then recur on what's
inside them.
nestParen("(())") → true
nestParen("((()))") → true
nestParen("(((x))") → false
*/

bool nestParen(std::string s);
/*
Similar to nestParen except it ignores all characters other then ( and ). For example, (4+5)/2 should be accepted.
Basically this returns true if there is a closing paren for every opening paren.
Likewise, all closing parens have a matching opening paren. You may assume that the parens will NOT nest more than twice, ie: ((())).
*/


bool balancedParens( std::string s );

/*
Return the binary representation of an integer to sout.
A binary number is a number of ONLY 0 a'snd 1's. To convert from decimal to binary is basically the repetition of div by 2 and mod 2.
SEE the first two minutes of: https://www.youtube.com/watch?v=UvCZQ5CaWx0
The weird part here is my usage of ostream, something you may not have seen yet.
For now, just assume that std::cout is used when calling
integerToBinary( std::cout,2);
This will OUTPUT the value "10" to the standard output stream (cout).
When implementing integerToBinary() you would have:
sout << "10";
if you wanted to send "10" to the output stream, in example above sout points to cout,
therefore, it would go to the screen.
*/

void integerToBinary( std::ostream& sout,unsigned int i );




#endif //LAB0801_RECURSION_H
