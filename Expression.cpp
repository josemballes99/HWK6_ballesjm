//
//  Expression.cpp
//  HWK6_ballesjm
//
//  Created by Jose Miguel Ballesteros on 2015-12-02.
//
//

#include "Expression.h"

Expression::Expression(string exp){
    newExpression = exp;
}
Expression::~Expression(){
    
}

string Expression::getExpression(){
    return newExpression;
}

void Expression::setExpression(string exp){
    newExpression = exp;
}

