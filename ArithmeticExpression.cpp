/*
 Name: Sarthak Desai, Jose Miguel Ballesteros, Rehan Theiveehathasan
 MacID: desaisa3, ballesjm, theivers
 Student Number: 1423055, 1411748, 1416031
 Description: [This is file breaks the appart the string by recursively sending the objects on the left and right side to their respective calculations]
 */

#include "ArithmeticExpression.h"

//ArithmeticExpression::ArithmeticExpression(Expression input)

//ArithmeticExpression::~ArithmeticExpression(){}


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
          //int c=0;                                                      //counter for the characters
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
//        if (newExpression[checkindexPM] == '+') {                 //if index is and addition
//            Addition addstr(a,b);                                 //Create addition object
//            
//            Addition newls(a);                            // create leftside pointer object in Addition
//            Addition newrs(b);                            // create rightside pointer object in Addition
//            
//            ArithmeticExpression *newleftside = &newls;   // create leftside pointer object in ArithmeticExpression
//            ArithmeticExpression *newrightside= &newrs;   // create rightside pointer object in ArithmeticExpression
//            
//            string newa = newleftside->evaluate();        //evaluate leftside
//            string newb = newrightside->evaluate();       //evaluate rightside
//            for(int i=0; i<newa.length();i++){
//
//            }
//            
//        }
//        else if (newExpression[checkindexPM] == '-'){ //if index is and subtraction
//            
//            //Subtraction addstr(a,b);    //Create subtraction object
//            
//            //Subtraction newls(a);        // create leftside pointer object in Subtraction
//            //Subtraction newrs(b);          // create rightside pointer object in Subtraction
//            
//            //ArithmeticExpression *newleftside = &newls; // create leftside pointer object in ArithmeticExpression
//            //ArithmeticExpression *newrightside= &newrs; // create rightside pointer object in ArithmeticExpression
//            
//            string newa = newleftside->evaluate();    //evaluate leftside
//            string newb = newrightside->evaluate();   //evaluate rightside
//                        for(int i=0; i<newa.length();i++){
//
//                        }
//        }
//        
//    }
//    int checkindexMD=addsub(newExpression);   //run function to look for the index where addition or subtraction occurs
//    if (checkindexMD!=-1){        // the above method returns -1 if no * or / was found
//        
//        string leftside = "";     //sets leftside string to empty
//        for (int i = 0; i<checkindexMD; i++) {    //loop to extract all the characters before the sign was encountered
//            leftside.insert(i,1,newExpression.at(i)); // edits the leftside string to contain the characters extracted
//        }
//        
//        string rightside = "";                                    //creates a string right side to store the characters on the right of the sign
//        int c=0;          //counter for the characters
//        for(int i=checkindexMD+1;i<newExpression.length();i++){
//
//            rightside.insert(c,1,newExpression.at(i));            //loops through all the characters after the sign
//            c++;
//        }
//        
//        
//        ArithmeticExpression ls(leftside);                //creates an object of type arithmetic expression with the rightside
//        ArithmeticExpression rs(rightside);               //creates an object of type arithmetic expression with the leftside
//        
//        Expression *left = &ls;                       //sets *left pointer to the reference of ls
//        Expression *right = &rs;                      //sets *right to the reference of rs
//        
//        string a=left->evaluate();                 //calls evaluate recursively using the pointer
//        string b=right->evaluate();                   //calls evaluate recursively using the pointer
//        
//        if (newExpression[checkindexMD] == '*') {      //if index is and multiplication
//            Multiplication addstr(a,b);                  //Create addition object
//            
//            Multiplication newls(a);                  // create leftside pointer object in Multiplication
//            Multiplication newrs(b);                  // create rightside pointer object in Multiplication
//            
//            ArithmeticExpression *newleftside = &newls;       // create leftside pointer object in ArithmeticExpression
//            ArithmeticExpression *newrightside= &newrs;       // create rightside pointer object in ArithmeticExpression
//            
//            string newa = newleftside->evaluate();            //evaluate leftside
//            string newb = newrightside->evaluate();           //evaluate rightside
//
//            
//        }
//        else if (newExpression[checkindexMD] == '/'){         //if index is and division
//            
//            Division addstr(a,b);                         //Create addition object
//            
//            Division newls(a);                        // create leftside pointer object in Division
//            Division newrs(b);                        // create rightside pointer object in Division
//            
//            ArithmeticExpression *newleftside = &newls;       // create leftside pointer object in ArithmeticExpression
//            ArithmeticExpression *newrightside= &newrs;       // create rightside pointer object in ArithmeticExpression
//            
//            string newa = newleftside->evaluate();        //evaluate leftside
//            string newb = newrightside->evaluate();       //evaluate rightside
//
//        }
//        
//    }
//
//}
//
//
//int addsub(string input){     //this function returns the index where addition or subtraction occurs
//    int braccount=0;          //initialize braccount
//    for (int i=0;i < input.length(); i++){    //for the length of the string
//        if (input[i]=='('){           //if input is a open bracket
//            braccount++;          //incremant braccount
//        }
//        else if(input[i]==')'){       //if input is a closed bracket
//            braccount--;          //decrement braccount
//        }
//        
//        else if (((input[i]=='+') || (input[i]=='-'))&&(braccount==0)){       //if input is an addition or subtraction and braccount is 0
//            return i;         //return the index
//        }
//    }
//    return -1;        //if nothing is found return -1
//}
//
//int muldiv(string input){     //this function returns the index where multiplication or division occurs
//    int braccount=0;  //initialize braccount
//    for (int i=0;i < input.length(); i++){        //for the length of the string
//        if (input[i]=='('){       //if input is a open bracket
//            braccount++;          //incremant braccount
//        }
//        else if(input[i]==')'){       //if input is a closed bracket
//            braccount--;              //decrement braccount
//        }
//        
//        else if (((input[i]=='*') || (input[i]=='/'))&&(braccount==0)){       //if input is an addition or subtraction and braccount is 0
//            return i;             //return the index
//        }
//    }
//    return -1;        //if nothing is found return -1
//}
