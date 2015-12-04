//
//  HWK6_ballesjm.cpp
//  HWK6_ballesjm
//
//  Created by Jose Miguel Ballesteros on 2015-11-27.
//
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

#include "Expression.hpp"
#include "Addition.hpp"
#include "ArithmeticExpression.hpp"
#include "Subtraction.hpp"
#include "Multiplication.hpp"
#include "Division.hpp"

using namespace std;

int main(){
    string input;
    
    cout << "Please Enter an expression: ";
    cin >> input;
    
    Expression userInput(input);
    
    cout << "\n" << userInput.getExpression() << " = " << " ??? " << endl;
    
    return 0;
}
