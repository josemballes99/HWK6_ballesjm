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


//string ArithmeticExpression::evaluate(){                          //evaluate method of arithmetic expression
//    
//    int checkindexPM=addsub(newExpression);                       // calls the method addsub to find a + or minus sign
//    if (checkindexPM!=-1){                                        // the above method returns -1 if no + or - was found
//          
//        string leftside = "";                                     //sets leftside string to empty
//        for (int i = 0; i<checkindexPM; i++) {                    //loop to extract all the characters before the sign was encountered
//            leftside.insert(i,1,newExpression.at(i));             // edits the leftside string to contain the characters extracted
//        }                                                         //end of for
//          
//        string rightside = "";                                    //creates a string right side to store the characters on the right of the sign
          int c=0;                                                      //counter for the characters
//        for(int i=checkindexPM+1;i<newExpression.length();i++){           //loops through all the characters after the sign
//                                                         
//            rightside.insert(c,1,newExpression.at(i));                    //adds to the rightside string the values extracted from the right of the input
//            c++;                                                          //increases the counter
//        }                                                                 //end of for
//      
//        
//        ArithmeticExpression ls(leftside);                                //creates an object of type arithmetic expression with the rightside
//        ArithmeticExpression rs(rightside);                               //creates an object of type arithmetic expression with the leftside
//        
//        Expression *left = &ls;                                           //sets *left pointer to the reference of ls
//        Expression *right = &rs;                                          //sets *right to the reference of rs
//        
//        string a=left->evaluate();                                        //calls evaluate recursively using the pointer
//        string b=right->evaluate();                                       //calls evaluate recursively using the pointer
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
