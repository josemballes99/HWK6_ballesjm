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
#include <algorithm>
#include <iterator>
#include <cctype>

#include "Expression.h"
#include "Addition.h"
#include "ArithmeticExpression.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

using namespace std;

string insertBrackets(string input)
{

    /*
     CASE ONE --> '*' or '/' followed by a bracket
     */

    for(size_t i = 0; i < input.length(); i++) { //  loop through the string
        if((input.at(i) == '*') || (input.at(i) == '/')) {
            if(input.at(i+1) == '(') {  // finds the first open bracket if it is right beside it

                size_t j = i; // initalize j and k to have the same value in the string as i
                size_t k = i;

                while(input.at(j) != ')') { // looks for the closed brackets
                    j++;    //increases j by one
                }
                if(input.at(j) == ')') {    // inserts the closed bracket after the closed bracket
                    input.insert(j+1, 1, ')');
                }


                do {
                    k--;
                } while ((input.at(k) != '+') && (input.at(k) != '-') && (input.at(k) != '*') && (input.at(k) != '/') && (k != 0)); //this do while loop decrements the k value until it reaches the operator


                if (((input.at(k) == '+') || (input.at(k) == '-')|| (input.at(k) == '*') || (input.at(k) == '/')) && (input.at(k-1) != '(')) { //covers a case where it inserts the open bracket where there is a negative
                    input.insert(k+1,1,'(');
                    i++;
                }
                else if ((((input.at(k) == '+') || (input.at(k) == '-')|| (input.at(k) == '*') || (input.at(k) == '/')) && (input.at(k-1) == '('))) {   //covers case where there might be a bracket in the beginning
                    input.insert(k,1,'(');
                    i++;
                }
                else {
                    input.insert(0,1,'(');  //covers the case where a open bracket is needed in the beginning
                    i++;
                }
            }
        }
    }

    /*
     CASE TWO --> seperating additions and subtractions
     */


    for (int i = 0; i < input.length(); i++){
        if (((input.at(i) == '+') || (input.at(i) == '-')) && (input.at(i-1) != '(')) {
            input.insert(i+1,1,'(');
            input.insert(i,1,')');
            i++;
        }
    }

    input.insert(0,1,'(');
    input.insert(input.length(),1,')');

    for (int i = 0; i < input.length(); i++) {
        if (((input.at(i) == '*') || (input.at(i) == '/')) && (input.at(i-1) == ')')) {
            input.insert(i+1,1,'(');
            input.insert(i,1,')');
            i++;
        }
        else if (((input.at(i) == '*') || (input.at(i) == '/')) && (input.at(i+1) == '(')) {
            input.insert(i+1,1,'(');
            input.insert(i,1,')');
            i++;
        }
    }

    return input;
}

string stripSpace(string express)
{
    for(size_t i = 0; i < express.length(); i++)
    {
        if(express.at(i) == ' ')
        {
            express.erase(i,1);
            i--;
        }
    }
    return express;
}



int main(){                     // start of main
    string input;               //var to hold the input from the user
    bool check =true;           //boolean to check if the input is valid
    int openbrack=0;            //var to count the number of open brackets
    int closebrack=0;           //var to count the number of closed brackets
    cout << "Please Enter an expression: ";         // prompt to user
    getline(cin,input);                             //gets the user input and stres in the var input


    // checks if all the characters are valid characters including spaces
    if (check==true){                               //start of if structure if check is set to true
            for (int i=0; i<input.length();i++){            //loops through all the values in the input string
                    if ((int(input[i]) < 40 && int(input[i])!= 32) || int(input[i]) > 57 || int(input[i])==44 || int(input[i])==46){            //checks if the input string contains the valid characters by comparing with ascii values
                        check=false;                //sets check to false if an improper character is encountered
                    }                           //end of if
            }                                   //end of for

    }                                           //end of if



    if (check==true){                           //executes the next validation check only if the check variable is still set to true
    bool spacecheck=false;                      // var set to true if a space is encountered
    int whiteindex=0;                           //var to hold the index of the white space
    char l;                                     // variable char l to hold the left character before the operand

        for (int i=0;i<input.length();i++){         //checks if the string has any whitespaces
            if (int(input[i])==32){                 //checks if the ascii value matches the ascii value of a space
                spacecheck=true;                    //sets to spacecheck to true
            }                                       //end of if
        }                                           //end of for

        if (spacecheck==true && (int(input[0])==32 || int(input[input.length()]==32))){  // if there are white spaces then makes sure they are not first and last characters
            check=false;                                                                //sets check to false
        }                                                                               //end of if


        //checks to see white space only exists between operands and operators
        if (check==true&&spacecheck==true){                     //only runs if the string given has any white spaces
            check=false;                                        //presets check to false

            for (int i=0; i<input.length(); i++){               //goes through all the values
                if(int(input[i])!=32&&whiteindex==0){           //if a value is found that is not empty and the whiteindex is 0
                    int c=i;                                    // sets counter var c to the index i (so the value of i is not chenged when counting back)
                    if (input[i]==')'){                         //checks if the input is an closed bracket
                        while(int(input[c])<48||int(input[c])>57){          //while loop counts back till it encounters a number
                            c--;                                // reduces the counter c each time
                        }                                       //end of while
                    }                                           //end of if
                    l=input[c];                                 // then this becomes the left side character
                }                                               // end of if

                if (int(input[i])==32){                         //when a white space is encountered the whiteindex is made a non zero value
                    whiteindex=i;                               //white index value is set
                }                                               //end of if

                if(int(input[i])!=32&&whiteindex!=0){           //if the white index is not zero and the next number is not empty
                    if (((l >= 48) && (l <= 57)) && ((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')||(input[i]==')'))){      //then check if the last character before a white space was a number and the new character is an operand
                        int j=i;                        //sets j to i
                        if (input[i]==')'){             // checks if closed bracket is encountered
                            while(input[j]!='+'||input[j]!='-'||input[j]!='*'||input[j]!='/'){  //runs while loop while characters represent a number
                                j=j+1;                  //increases the j count by 1, as long as a number is encountered
                            }                           //end of while
                        }                               //end of if
                        check=true;                                                                 // this is valid so check=true now
                        whiteindex=0;                                                             //reset whitespace index to 0
                        l=input[j];                                                             //sets l character to the value at j in the input string
                    }                                                                           //end of if
                    else if((l=='+'||l=='-'||l=='*'||l=='/')&&((int(input[i])>=48&&int(input[i])<=57)||(input[i]=='('))){   // or the other way around
                        int j=i;                            //sets the value of j to to i so i does not change
                        if (input[i]=='('){                 //checks if the value is a open index
                                while (int(input[j])<48||int(input[j])>57){         //while loop checks if the character is not a number
                                    j=j+1;                                          //increases j counter
                                }                                   // end of while
                        }                                           //end of if

                        check=true;                              //check is true now
                        whiteindex=0;                           //reset whitespace
                        l=input[j];                             //resets the l character to the one at the jth index in the input
                    }                                           //end of if

                    else{                                       //if neither of the above are satisfied
                        check=false;                            //sets check to false
                        break;                                  //breaks the check loop as no more checks are required
                    }                                           // end of if
                }                                               //end of if
            }                                                   //end of for
        }                                                       //end of if
    }                                                           //end of if



    //checks if the number of brackets are correct
    if (check==true){                                           //only starts if the other checks have passed

        for (int i=0; i<input.length();i++){                    //loops through all characters in input

            if (input[i]=='('){                                 //checks if an open bracket is found
                    openbrack=openbrack+1;                      //increases open bracket counter
                }                                               //end of if
            else if (input [i]==')'){                           //checks if closed bracket is found

                closebrack=closebrack+1;                        //increases closebracket count
            }                                                   //end of if
    
        }                                                       //end of for

        if (openbrack != closebrack){                           //checks if the open and close bracket counts are equal
            check=false;                                        //if not equal then sets check to false
        }                                                       //end of if



    }                                                           // end of if





    // checks if the first character is valid.
    if (check==true){                                           // runs if the previous checks are satisfied
        if (input[0]=='+' || input[0]=='-'  || input[0]=='/'  || input[0]=='*' || input[0]==')' || input[input.length()-1]=='('){  //sees if one of these characters is encountered first in the input
            check=false;                                            //sets check to false
        }                                                           //end of if
    }                                                               //end of if

    //checks if the last character is valid
    if (check==true){                                               //runs if the previous checks are satisfied

        if (input[input.length()-1]=='+'||input[input.length()-1]=='-'||input[input.length()-1]=='*'||input[input.length()-1]=='/'){ //checks if one of these is found as the last character
            check=false;                                //sets the check to false
        }                                               //end of if

    }                                                   //end of if

    // checks if there is a number followed by all signs
    if (check==true){                                   //runs if the previous checks are satisfied
        bool signcheck=false;                           //var to check if an operator is encountered
        bool numcheck=false;                            //var to check if a number is encountered
        for (int i=0; i<input.length(); i++){           //loops through all the values in the input
            if (input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i] == '/'){      //checks if an operator is encountered
                signcheck=true;                             //sets sign to true
                for(int j=i; j<input.length();j++){         //loops from where i leaves off to find a number

                    if((int(input[j])>=48 && int (input[j])<=57)){      // checks if the character is a number
                        numcheck=true;                                  //sets numcheck to true if number is found
                    }                                                   // end of if

                }                                                       //end of for
            }                                                           // end of if


        }                                                               //end of for
        if (signcheck!=numcheck){                                       //checks if the sign check is equal to numcheck
            check=false;                                                //sets check to false
        }                                                               // end of if


    }                                                                   //end of if




    //checks that the expression doesnt have  " )( " and that it doesnt have a '3('
    if (check==true){                                       //runs if the previous checks were true

        for (int i=0; i<input.length(); i++){               //loops through all the values
            if (i!=input.length()-1){                       //checks if i is at the last index
                if (input [i]==')' && input[i+1]=='('){     //checks if the character is a closed bracket and the next one is a open bracket
                    check=false;                            //sets the check to false
                }                                           //end of if

                else if ((int(input[i])>=48 && int (input[i])<=57)&& input[i+1]=='('){          //checks if a number if followed by a openbracket
                    check=false;                                            //sets check to false
                }                                                           // end of if
                else if ((int(input[i+1])>=48 && int (input[i+1])<=57)&& input[i]==')'){        //checks if a closed bracket is followed by a number
                    check=false;                                                                //sets check to false
                }                                                                               //end of if

                else if ((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')&&(input[i+1]=='+'||input[i+1]=='-'||input[i+1]=='*'||input[i+1]=='/')){       //checks if two operators are beside eachother
                    check=false;                          //  sets the check to false
                }                                           //end of if
                else if ((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')&&(input[i+1]==')')){  //checks if operator is followed by a open bracket
                    check=false;                                                                            //sets check to false
                }                           //end of if
            }                               //end of if
        }                                   //end of for
    }                                       //end of if

    // checks if there is at least 1 number
    if (check==true){                                   //runs if previous checks are true
        check=false;                                    //presets check to false
        for (int i=0;i<input.length();i++){             //loops through all the characters
            if (int(input[i])>=48 && int(input[i])<=57){            //checks if there is a number
                check=true;                                         //sets check to true
            }                                                       //end of if
        }                                                           //end of for
    }                                                               //end of if


    //checks if div and mul operators are preceded by a number    
   if (check==true){                                                    //runs if the previous checks are true
        for (int i=0; i<input.length(); i++){                           //loops through all the characters
            if (input[i]=='/'||input[i]=='*'){                          //looks for multiplycation of division
                check=false;                                            //presets check tofalse
                for (int j=i; j>0;j--){                                 //counts back to find a number
                    if (int(input[j-1])>=48 && int(input[j-1])<=57){                //if a number if found
                        check=true;                                         //sets check to true
                        break;                                          //breaks the loop
                    }                                                   //end of if
                    else if (input[j-1]=='+'||input[j-1]=='-'||input[j-1]=='*'||input[j-1]=='/'){       //if another operator is found
                        check=false;            //sets check to false
                        break;                  //breaks the loop
                    }                           //end of if
                }                               //end of for
            }                                   //end of if
        }                                       //end of for

    }                                           //end of if






    if (check==true){                       //creates the objects to parse into the tree if the previous checks are valid

        input = insertBrackets(input);              //calls the brackets method to add brackets

        ArithmeticExpression userInput(input);            // creates object of type arithmetic expression by sending in the input string


        cout << "\n" << userInput.newExpression << endl;            // outputs the string entered by the user

<<<<<<< HEAD
        userInput.stringtoExpression(input);

        //cout << "\n" << userInput.newExpression << endl;

=======
>>>>>>> origin/master

       
    }                                       //end of if
    return 0;                               //return 
}                                           //end of main
