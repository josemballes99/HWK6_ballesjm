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
    ArithmeticExpression(Expression input);

    ArithmeticExpression(char, Expression*, Expression*);
    
    ~ArithmeticExpression();
    
    Expression *left;
    Expression *right;
    
    char symbol;
    
    Expression *stringtoExpression(string);
    

    string evaluate (); //evaluate left expression and right expression
    
    void print(){}
    
    void release(){
        left->release();
        right->release();
        delete left;
        delete right;
    }
    
//    int addsub(string); //returns the index in which a bracket does not evaluate
//    int muldiv(string);
//    int bracket(string);

//    float convert (string); // Converts a string (as would be returned by evaluate) to a float
};


#endif /* ArithmeticExpression_h */
