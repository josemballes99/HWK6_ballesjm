//
//  ArithmeticExpression.hpp
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
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

#include "Expression.h"

using namespace std;

class ArithmeticExpression : public Expression {
public:
    //Constructor
    ArithmeticExpression(string);
    
    //destructor
    ~ArithmeticExpression();
    
    //Accessor Fuctions
    string getExpression();
    
    //Mutator Functions
    void setExpression(string);
    
    Expression *left;
    Expression *right;
    
//    string evaluate (){ //evaluate left expression and right expression
//        void print();
//    }
//    
//    float convert (string s){ // Converts a string (as would be returned by evaluate) to a float
//        
//    }
private:
    string newExpression;
};

#endif /* ArithmeticExpression_h */
