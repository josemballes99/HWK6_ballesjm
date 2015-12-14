//
//  Expression.hpp
//  HWK6_ballesjm
//
//  Created by Jose Miguel Ballesteros on 2015-12-02.
//
//

#ifndef Expression_h
#define Expression_h

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std;

class Expression {
public:
    //variables
    string newExpression;
    string value;

    
    //Default Constructor
    Expression();
    
    //Overload Constructor
    Expression(string exp);

    //destructor
    ~Expression();
    
    //Functions
    string insertBrackets();
    
    //virtual string evaluate(); // evaluate expression and return string representation of the result.
    virtual void print(){};
    
};

#endif /* Expression_h */
