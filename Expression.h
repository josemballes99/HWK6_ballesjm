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
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

class Expression {
public:
    //Constructor
    Expression(string);

    //destructor
    ~Expression();

    //Accessor
    string getExpression();

protected:
    string newExpression;
};

#endif /* Expression_h */
