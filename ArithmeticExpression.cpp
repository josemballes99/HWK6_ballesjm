//
//  ArithmeticExpression.cpp
//  HWK6_ballesjm
//
//  Created by Jose Miguel Ballesteros on 2015-12-02.
//
//

#include "ArithmeticExpression.h"

ArithmeticExpression::ArithmeticExpression(string exp){
    newExpression = exp;
}
ArithmeticExpression::~ArithmeticExpression(){
    
}

string ArithmeticExpression::getExpression(){
    return newExpression;
}

void ArithmeticExpression::setExpression(string exp){
    newExpression = exp;
}