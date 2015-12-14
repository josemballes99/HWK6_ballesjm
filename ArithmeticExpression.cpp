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

ArithmeticExpression::ArithmeticExpression(char sym, Expression* le, Expression* re){
    symbol = sym;
    left = le;
    right = re;
}

ArithmeticExpression::~ArithmeticExpression(){}

Expression* stringtoExpression(string &str){
    int level = 0;//inside parentheses check
    //case + or -
    //most right '+' or '-' (but not inside '()') search and split
    for(int i = (str.size()-1);i>=0;--i) {
        char c = str[i];
        if(c == ')'){
            ++level;
            continue;
        }
        if(c == '('){
            --level;
            continue;
        }
        if(level>0) continue;
        if((c == '+' || c == '-') && i!=0 ){//if i==0 then s[0] is sign
            string L(str.substr(0,i));
            string R(str.substr(i+1));
            return new ArithmeticExpression(c, stringtoExpression(L), stringtoExpression(R));
        }
    }
    //case * or /
    //most right '*' or '/' (but not inside '()') search and split
    for(int i = (str.size()-1); i>=0; --i){
        char c = str[i];
        if(c == ')'){
            ++level;
            continue;
        }
        if(c == '('){
            --level;
            continue;
        }
        if(level>0) continue;
        if(c == '*' || c == '/'){
            string L(str.substr(0,i));
            string R(str.substr(i+1));
            return new ArithmeticExpression(c, stringtoExpression(L), stringtoExpression(R));
        }
    }
    if(str[0]=='('){
        //case ()
        //pull out inside and to strToExp
        for(int i=0;i<str.size();++i){
            if(str[i]=='('){
                ++level;
                continue;
            }
            if(str[i]==')'){
                --level;
                if(level==0){
                    string exp(str.substr(1, i-1));
                    return stringtoExpression(exp);
                }
                continue;
            }
        }
    } else
        //case value
        return new Term(str);
    cerr << "Error:never execute point" << endl;
    return NULL;//never
}

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
////            for(int i=0; i<newa.length();i++){
////                if(newa[i]=='+'|| newa[i]=='-'){
////                    
////                }
////                else if (<#condition#>){
////                    
////                }
////                else {                                                        //TODO: Figure shit out
////                    
////                }
////            }
//            
//        }
//        else if (newExpression[checkindexPM] == '-'){
//            
//            Subtraction addstr(a,b);
//            
//            Subtraction newls(a);
//            Subtraction newrs(b);
//            
//            ArithmeticExpression *newleftside = &newls;
//            ArithmeticExpression *newrightside= &newrs;
//            
//            string newa = newleftside->evaluate();
//            string newb = newrightside->evaluate();
//            //            for(int i=0; i<newa.length();i++){
//            //                if(newa[i]=='+'|| newa[i]=='-'){
//            //
//            //                }
//            //                else if (<#condition#>){
//            //
//            //                }
//            //                else {                                                        //TODO: Figure shit out
//            //                    
//            //                }
//            //            }
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
//            //            for(int i=0; i<newa.length();i++){
//            //                if(newa[i]=='+'|| newa[i]=='-'){
//            //
//            //                }
//            //                else if (<#condition#>){
//            //
//            //                }
//            //                else {                                                        //TODO: Figure shit out
//            //
//            //                }
//            //            }
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
//            //            for(int i=0; i<newa.length();i++){
//            //                if(newa[i]=='+'|| newa[i]=='-'){
//            //
//            //                }
//            //                else if (<#condition#>){
//            //
//            //                }
//            //                else {                                                        //TODO: Figure shit out
//            //                    
//            //                }
//            //            }
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
