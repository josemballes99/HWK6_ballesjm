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



int main(){
    string input;
    bool check =true;
    int openbrack=0;
    int closebrack=0;
    cout << "Please Enter an expression: ";
    getline(cin,input);


    // checks if all the characters are valid characters including spaces
    if (check==true){
            for (int i=0; i<input.length();i++){
                    if ((int(input[i]) < 40 && int(input[i])!= 32) || int(input[i]) > 57 || int(input[i])==44 || int(input[i])==46){
                        check=false;
                    }
            }

    }



    if (check==true){
    bool spacecheck=false;
    int whiteindex=0;
    char l;

        for (int i=0;i<input.length();i++){         //checks if the string has any whitespaces
            if (int(input[i])==32){
                spacecheck=true;
            }
        }

        if (spacecheck==true && (int(input[0])==32 || int(input[input.length()]==32))){  // if there are white spaces then makes sure they are not first and last characters
            check=false;
        }


        //checks to see white space only exists between operands and operators
        if (check==true&&spacecheck==true){                     //only runs if the string given has any white spaces
            check=false;                                        //presets check to false

            for (int i=0; i<input.length(); i++){               //goes through all the values
                cout << "loop" << endl;
                if(int(input[i])!=32&&whiteindex==0){           //if a value is found that is not empty and the whiteindex is 0
                    int c=i;
                    if (input[i]==')'){
                        while(int(input[c])<48||int(input[c])>57){
                            c--;
                        }
                    }
                    l=input[c];                                 // then this becomes the left side character
                    cout << "leftside"<<endl;
                }

                if (int(input[i])==32){                         //when a white space is encountered the whiteindex is made a non zero value
                    whiteindex=i;
                    cout << "whitespace" << endl;
                }

                if(int(input[i])!=32&&whiteindex!=0){           //if the white index is not zero and the next number is not empty
                    cout << "its in" << endl;
                    int l;
                    if (((l >= 48) && (l <= 57)) && ((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')||(input[i]==')'))){      //then check if the last character before a white space was a number and the new character is an operand
                        int j=i;
                        cout << l << endl;
                        if (input[i]==')'){
                            while(input[j]!='+'||input[j]!='-'||input[j]!='*'||input[j]!='/'){
                                j=j+1;
                            }
                        }
                        check=true;                                                                                     // this is valid so check=true now
                        whiteindex=0;                                                                               //reset whitespace
                        l=input[j];
                    }
                    else if((l=='+'||l=='-'||l=='*'||l=='/')&&((int(input[i])>=48&&int(input[i])<=57)||(input[i]=='('))){         // or the other way around
                        int j=i;
                        if (input[i]=='('){
                                while (int(input[j])<48||int(input[j])>57){
                                    j=j+1;
                                }
                        }

                        check=true;                                                                         //check is true now
                        whiteindex=0;
                        l=input[j];                                                                               //reset whitespace
                    }

                    else{
                        check=false;
                        break;
                    }
                }
            }
        }
    }



    //checks if the number of brackets are correct
    if (check==true){

        for (int i=0; i<input.length();i++){

            if (input[i]=='('){
                    openbrack=openbrack+1;
                }
            else if (input [i]==')'){

                closebrack=closebrack+1;
            }

        }

        if (openbrack != closebrack){
            check=false;
            cout << "tag1" <<endl;  //test
        }



    }





    // checks if the first character is valid.
    if (check==true){
        if (input[0]=='+' || input[0]=='-'  || input[0]=='/'  || input[0]=='*' || input[0]==')' || input[input.length()-1]=='('){
            check=false;
        }
    }

    if (check==true){

        if (input[input.length()-1]=='+'||input[input.length()-1]=='-'||input[input.length()-1]=='*'||input[input.length()-1]=='/'){
            check=false;
        }

    }

    if (check==true){
        bool signcheck=false;
        bool numcheck=false;
        for (int i=0; i<input.length(); i++){
            if (input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i] == '/'){
                signcheck=true;
                for(int j=i; j<input.length();j++){

                    if((int(input[j])>=48 && int (input[j])<=57)){
                        numcheck=true;
                    }

                }
            }


        }
        if (signcheck!=numcheck){
            check=false;
            cout << "tag2" <<endl; //test
        }


    }




    //checks that the expression doesnt have  " )( " and that it doesnt have a '3('
    if (check==true){

        for (int i=0; i<input.length(); i++){
            if (i!=input.length()-1){
                if (input [i]==')' && input[i+1]=='('){
                    check=false;
                }

                else if ((int(input[i])>=48 && int (input[i])<=57)&& input[i+1]=='('){
                    check=false;
                }
                else if ((int(input[i+1])>=48 && int (input[i+1])<=57)&& input[i]==')'){
                    check=false;
                }

                else if ((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')&&(input[i+1]=='+'||input[i+1]=='-'||input[i+1]=='*'||input[i+1]=='/')){
                    check=false;
                }
                else if ((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')&&(input[i+1]==')')){
                    check=false;
                }
            }
        }
    }

    // checks if there is at least 1 number
    if (check==true){
        check=false;
        for (int i=0;i<input.length();i++){
            if (int(input[i])>=48 && int(input[i])<=57){
                check=true;
            }
        }
    }



   if (check==true){
        for (int i=0; i<input.length(); i++){
            if (input[i]=='/'||input[i]=='*'){
                check=false;
                for (int j=i; j>0;j--){
                    if (int(input[j-1])>=48 && int(input[j-1])<=57){
                        check=true;
                        cout << "tag5" <<endl;  //test
                        break;
                    }
                    else if (input[j-1]=='+'||input[j-1]=='-'||input[j-1]=='*'||input[j-1]=='/'){
                        check=false;
                        break;
                    }
                }
            }
        }

    }






    if (check==true){

        input = insertBrackets(input);

        ArithmeticExpression userInput(input);            // sends the input to Arithmetic expression


        cout << "\n" << userInput.newExpression << endl;

        //userInput.stringtoExpression(input);

        //cout << "\n" << userInput.newExpression << endl;


        //ArithmeticExpression bracketinput(userInput);
    }
    return 0;
}
