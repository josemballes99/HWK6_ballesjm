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
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

#include "Expression.h"

using namespace std;

<<<<<<< HEAD
//class ArithmeticExpression : public Expression {
//    Expression *left;
//    Expression *right;
//
//    string evaluate (){ //evaluate left expression and right expression
//        void print();
//    }
//
//    float convert (string s){ // Converts a string (as would be returned by evaluate) to a float
//
//    }
//};
=======
class ArithmeticExpression : public Expression {
public:
    //Constructor
    ArithmeticExpression(string);
    
    //destructor
    ~ArithmeticExpression();
    
    //Accessor Fuctions
    string getExpression() const;
    
    //Mutator Functions
    void setExpression(string);
    
    Expression *left;
    Expression *right;
    
    string evaluate (); //evaluate left expression and right expression
    
    float convert (string); // Converts a string (as would be returned by evaluate) to a float
private:
    string newExpression;
};
>>>>>>> origin/master

#endif /* ArithmeticExpression_h */
