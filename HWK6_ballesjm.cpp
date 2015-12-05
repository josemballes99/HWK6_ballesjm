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

#include "Expression.h"
#include "Addition.h"
#include "ArithmeticExpression.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

using namespace std;

int main(){
    string input;
    
    while (1<2) {       //lol deadmau5
        cout << "Please Enter an expression: ";
        cin >> input;
        
        if ((input == "#")) {
            break;
        }
    
        ArithmeticExpression userInput(input);
    
        cout << "\n" << userInput.getExpression() << " = " << " ??? " << endl;
    }
    return 0;
}
