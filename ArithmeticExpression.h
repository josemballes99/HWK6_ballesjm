//
//  ArithmeticExpression.h
//  HWK6_ballesjm
//
//  Created by Jose Miguel Ballesteros on 2015-12-02.
//
//

#ifndef ArithmeticExpression_h
#define ArithmeticExpression_h

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

#include "Expression.h"

using namespace std;


class ArithmeticExpression : public Expression {
public:
    ArithmeticExpression(Expression input){
    this->newExpression = input.newExpression;   
	}
    
    ~ArithmeticExpression(){}
    
    Expression *left;
    Expression *right;

    string evaluate (); //evaluate left expression and right expression
    
    void print(){}
    
    int addsub(string); //returns the index in which a bracket does not evaluate
    int muldiv(string);
    int bracket(string);

    float convert (string); // Converts a string (as would be returned by evaluate) to a float
};


#endif /* ArithmeticExpression_h */
