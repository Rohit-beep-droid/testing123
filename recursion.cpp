#include "recursion.h"
#include <string>
#include "iostream"
unsigned int count7( unsigned int n ){
    int count = 0;
    if(n / 10 == 0){
        if(n == 7){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(n % 10 == 7){
        return 1 + count7(n /10);
    }
    else{
        return count7(n / 10);
    }

}


unsigned int product( unsigned int n ){
    if(n / 10 == 0){
        return n;
    } return product(n / 10) * product(n % 10);


}


bool nestParen(std::string s) {
    if (s.empty() || s == "()")
       return true;
    std::string s2 = s.substr(1);
    if(s.at(0) != ')'){
        bool isValid = nestParen(s2);
        if(isValid){
            std::string newStr = s.substr(0) + s.substr(0);
            return true;
        }
    }
    return false;
}
bool balancedParens(std::string s, int count){
    if (s.empty()){
        if(count == 0){
        return true;
        }
        return false;
    }
    if(s.at(0) == '('){
        return balancedParens(s.substr(1), count +1);
    } else if(s.at(0) == ')'){
        if(count == 0){
            return false;
        }
        return balancedParens(s.substr(1), count - 1);
    }
    else{
        return balancedParens(s.substr(1), count);
    }
}

bool balancedParens( std::string s ){
    return balancedParens(s, 0);
}
void integerToBinary( std::ostream& sout,unsigned int i ){
    i = 0;

}

