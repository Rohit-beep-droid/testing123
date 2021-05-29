#include <iostream>

//============================================================================
// Name        : lab_recursion.cpp
// Author      : S. Miller
//============================================================================


#include <string>
#include "testOutput.h"

using namespace std;


/*
Given a non-negative int n, return the count of the occurrences of 7 as a digit, so for example 717 yields 2. (no loops).
Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).

count7(717) â†’ 2
count7(7) â†’ 1
count7(123) â†’ 0

*/
unsigned int count7( unsigned int n );

/*
Given a non-negative int n, return the product of each digit, so for example 717 yields 49 (7*1*7). (no loops).
Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).

product(0) â†’ 0
product(717) â†’ 49
product(7) â†’ 7
product(123) â†’ 6

*/
unsigned int product( unsigned int n );


/*
Given a string, return true if it is a nesting of zero or more pairs of parenthesis, like "(())" or "((()))". Suggestion: check the first and last chars, and then recur on what's inside them.

nestParen("(())") â†’ true
nestParen("((()))") â†’ true
nestParen("(((x))") â†’ false
*/
bool nestParen( string s );

/*
Similar to nestParen except it ignores all characters other then ( and ).  For example, (4+5)/2 should be accepted.
Basically this returns true if there is a closing paren for every opening paren.  Likewise, all closing parens have a matching opening paren.
You may assume that the parens will NOT nest more than twice, ie: ((())).
*/
bool balancedParens( string s );

/*
Return the binary representation of an integer to sout.

A binary number is a number of ONLY 0 a'snd 1's.  To convert from decimal to binary is basically the repetition of div by 2 and mod 2.
SEE the first two minutes of: https://www.youtube.com/watch?v=UvCZQ5CaWx0

The weird part here is my usage of ostream, something you may not have seen yet.  For now, just assume that std::cout is used when calling

integerToBinary( std::cout,2);

This will OUTPUT the value "10" to the standard output stream (cout).

When implementing integerToBinary() you would have:

sout << "10";

if you wanted to send "10" to the output stream, in example above sout points to cout, therefore, it would go to the screen.

*/
void integerToBinary( std::ostream& sout,unsigned int i );



int main() {

    doTestOnInt("integerToBinary","0","0",&integerToBinary);
    doTestOnInt("integerToBinary","1","1",&integerToBinary);
    doTestOnInt("integerToBinary","2","10",&integerToBinary);
    doTestOnInt("integerToBinary","3","11",&integerToBinary);
    doTestOnInt("integerToBinary","4","100",&integerToBinary);
    doTestOnInt("integerToBinary","5","101",&integerToBinary);
    doTestOnInt("integerToBinary","6","110",&integerToBinary);
    doTestOnInt("integerToBinary","7","111",&integerToBinary);
    doTestOnInt("integerToBinary","8","1000",&integerToBinary);
    doTestOnInt("integerToBinary","9","1001",&integerToBinary);
    doTestOnInt("integerToBinary","17","10001",&integerToBinary);

    doTestOnInt("product","0",0,&product);
    doTestOnInt("product","717",49,&product);
    doTestOnInt("product","7",7,&product);
    doTestOnInt("product","123",6,&product);
    doTestOnInt("product","1203",0,&product);
    doTestOnInt("product","11111",1,&product);
    doTestOnInt("product","2179",126,&product);

    doTestOnInt("count7","717",2,&count7);
    doTestOnInt("count7","7",1,&count7);
    doTestOnInt("count7","123",0,&count7);
    doTestOnInt("count7","77",2,&count7);
    doTestOnInt("count7","7123",1,&count7);
    doTestOnInt("count7","771237",3,&count7);
    doTestOnInt("count7","771737",4,&count7);
    doTestOnInt("count7","47571",2,&count7);
    doTestOnInt("count7","777777",6,&count7);
    doTestOnInt("count7","70701277",4,&count7);
    doTestOnInt("count7","777576197",5,&count7);
    doTestOnInt("count7","99999",0,&count7);
    doTestOnInt("count7","99799",1,&count7);

    doTestOnString("nestParen","(())", true, &nestParen);
    doTestOnString("nestParen","((()))", true, &nestParen);
    doTestOnString("nestParen","(((x))", false, &nestParen);
    doTestOnString("nestParen","((())", false, &nestParen);
    doTestOnString("nestParen","((()()", false, &nestParen);
    doTestOnString("nestParen","()", true, &nestParen);
    doTestOnString("nestParen","", true, &nestParen);
    doTestOnString("nestParen","(yy)", false, &nestParen);
    doTestOnString("nestParen","(())", true, &nestParen);
    doTestOnString("nestParen","(((y))", false, &nestParen);
    doTestOnString("nestParen","((y)))", false, &nestParen);
    doTestOnString("nestParen","((()))", true, &nestParen);
    doTestOnString("nestParen","(())))", false, &nestParen);
    doTestOnString("nestParen","((yy())))", false, &nestParen);
    doTestOnString("nestParen","(((())))", true, &nestParen);

    doTestOnString("balancedParens","()(())", true, &balancedParens);
    doTestOnString("balancedParens","()a(a(s))", true, &balancedParens);
    doTestOnString("balancedParens","(5+4)/2", true, &balancedParens);
    doTestOnString("balancedParens","(())", true, &balancedParens);
    doTestOnString("balancedParens","((()))", true, &balancedParens);
    doTestOnString("balancedParens","(((x))", false, &balancedParens);
    doTestOnString("balancedParens","(((x)))", true, &balancedParens);
    doTestOnString("balancedParens","((())", false, &balancedParens);
    doTestOnString("balancedParens","((()()", false, &balancedParens);
    doTestOnString("balancedParens","()", true, &balancedParens);
    doTestOnString("balancedParens","", true, &balancedParens);
    doTestOnString("balancedParens","(yy)", true, &balancedParens);
    doTestOnString("balancedParens","(())", true, &balancedParens);
    doTestOnString("balancedParens","(((y))", false, &balancedParens);
    doTestOnString("balancedParens","((y)))", false, &balancedParens);
    doTestOnString("balancedParens","((()))", true, &balancedParens);
    doTestOnString("balancedParens","(())))", false, &balancedParens);
    doTestOnString("balancedParens","((yy())))", false, &balancedParens);
    doTestOnString("balancedParens","(((())))", true, &balancedParens);

    return 0;
}
