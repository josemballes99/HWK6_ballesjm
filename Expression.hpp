//
//  Expression.hpp
//  HWK6_ballesjm
//
//  Created by Jose Miguel Ballesteros on 2015-12-02.
//
//

#ifndef Expression_hpp
#define Expression_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

class Expression {
public:
    //constructor
    Expression(string);
    
    //destructor
    ~Expression();
    
    //Accessor Fuctions
    string getExpression();
    
    //Mutator Functions
    void setExpression(string);
    
    
    //virtual string evaluate(); // evaluate expression and return string representation of the result.
    //virtual void print();
    
private:
    string newExpression;    
};

#endif /* Expression_hpp */
