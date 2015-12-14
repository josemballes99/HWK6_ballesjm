//
//  ArithmeticExpression.cpp
//  HWK6_ballesjm
//
//  Created by Jose Miguel Ballesteros on 2015-12-02.
//
//

#include "ArithmeticExpression.h"

ArithmeticExpression::ArithmeticExpression(Expression input){
    this->newExpression = input.newExpression;
    
}

ArithmeticExpression::~ArithmeticExpression(){}


//string ArithmeticExpression::evaluate(){
//    
//    int checkindexPM=addsub(newExpression);
//    if (checkindexPM!=-1){
//        
//        string leftside = "";
//        for (int i = 0; i<checkindexPM; i++) {
//            leftside.insert(i,1,newExpression.at(i));
//        }
//        
//        string rightside = "";
//        for(int i=checkindexPM+1;i<newExpression.length();i++){
//            int c=0;
//            rightside.insert(c,1,newExpression.at(i));
//            c++;
//        }
//      
//        
//        ArithmeticExpression ls(leftside);
//        ArithmeticExpression rs(rightside);
//        
//        Expression *left = &ls;
//        Expression *right = &rs;
//        
//        string a=left->evaluate();
//        string b=right->evaluate();
//        
//        if (newExpression[checkindexPM] == '+') {
//            Addition addstr(a,b);
//            
//            Addition newls(a);
//            Addition newrs(b);
//            
//            ArithmeticExpression *newleftside = &newls;
//            ArithmeticExpression *newrightside= &newrs;
//            
//            string newa = newleftside->evaluate();
//            string newb = newrightside->evaluate();
//            for(int i=0; i<newa.length();i++){
//                if(newa[i]=='+'|| newa[i]=='-'){
//                    
//                }
//                else if (<#condition#>){
//                    
//                }
//                else {
//                    
//                }
//            }
//            
//        }
//        else if (newExpression[checkindexPM] == '-'){
//            
//            //Subtraction addstr(a,b);
//            
//            //Subtraction newls(a);
//            //Subtraction newrs(b);
//            
//            //ArithmeticExpression *newleftside = &newls;
//            //ArithmeticExpression *newrightside= &newrs;
//            
//            string newa = newleftside->evaluate();
//            string newb = newrightside->evaluate();
//                        for(int i=0; i<newa.length();i++){
//                            if(newa[i]=='+'|| newa[i]=='-'){
//            
//                            }
//                            else if (<#condition#>){
//            
//                            }
//                            else {
//                                
//                            }
//                        }
//        }
//        
//    }
//    int checkindexMD=addsub(newExpression);
//    if (checkindexMD!=-1){
//        
//        string leftside = "";
//        for (int i = 0; i<checkindexMD; i++) {
//            leftside.insert(i,1,newExpression.at(i));
//        }
//        
//        string rightside = "";
//        for(int i=checkindexMD+1;i<newExpression.length();i++){
//            int c=0;
//            rightside.insert(c,1,newExpression.at(i));
//            c++;
//        }
//        
//        
//        ArithmeticExpression ls(leftside);
//        ArithmeticExpression rs(rightside);
//        
//        Expression *left = &ls;
//        Expression *right = &rs;
//        
//        string a=left->evaluate();
//        string b=right->evaluate();
//        
//        if (newExpression[checkindexMD] == '*') {
//            Multiplication addstr(a,b);
//            
//            Multiplication newls(a);
//            Multiplication newrs(b);
//            
//            ArithmeticExpression *newleftside = &newls;
//            ArithmeticExpression *newrightside= &newrs;
//            
//            string newa = newleftside->evaluate();
//            string newb = newrightside->evaluate();
//                        for(int i=0; i<newa.length();i++){
//                            if(newa[i]=='+'|| newa[i]=='-'){
//            
//                            }
//                            else if (<#condition#>){
//            
//                            }
//                            else {
//                            }
//                        }
//            
//        }
//        else if (newExpression[checkindexMD] == '/'){
//            
//            Division addstr(a,b);
//            
//            Division newls(a);
//            Division newrs(b);
//            
//            ArithmeticExpression *newleftside = &newls;
//            ArithmeticExpression *newrightside= &newrs;
//            
//            string newa = newleftside->evaluate();
//            string newb = newrightside->evaluate();
//                        for(int i=0; i<newa.length();i++){
//                            if(newa[i]=='+'|| newa[i]=='-'){
//            
//                            }
//                            else if (<#condition#>){
//            
//                            }
//                            else {
//                                
//                            }
//                        }
//        }
//        
//    }
//
//}
//
//
//int addsub(string input){
//    int braccount=0;
//    for (int i=0;i < input.length(); i++){
//        if (input[i]=='('){
//            braccount++;
//        }
//        else if(input[i]==')'){
//            braccount--;
//        }
//        
//        else if (((input[i]=='+') || (input[i]=='-'))&&(braccount==0)){
//            return i;
//        }
//    }
//    return -1;
//}
//
//int muldiv(string input){
//    int braccount=0;
//    for (int i=0;i < input.length(); i++){
//        if (input[i]=='('){
//            braccount++;
//        }
//        else if(input[i]==')'){
//            braccount--;
//        }
//        
//        else if (((input[i]=='*') || (input[i]=='/'))&&(braccount==0)){
//            return i;
//        }
//    }
//    return -1;
//}