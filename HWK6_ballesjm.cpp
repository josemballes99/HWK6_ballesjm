/*
 Name: Sarthak Desai, Jose Miguel Ballesteros, Rehan Theiveehathasan
 MacID: desaisa3, ballesjm, theivers
 Student Number: 1423055, 1411748, 1416031
 Description: [This file contains the foundations of the BEDMASS program by performing sanity checks and breaking down the string by adding brackets]
*/

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

//Function inser brackets at proper position and then return the expression
 string insertBrackets(string input)
 {

    /*
     CASE ONE --> '*' or '/' followed by a bracket
     */

     for(size_t i = 0; i < input.length(); i++) { 
        if((input.at(i) == '*') || (input.at(i) == '/')) {
            if(input.at(i+1) == '(') {  // finds the first open bracket if it is right beside it

                size_t j = i;
                size_t k = i;

                while(input.at(j) != ')') { // looks for the closed brackets
                    j++; 
                }
                if(input.at(j) == ')') {    // inserts the closed bracket after the closed bracket
                    input.insert(j+1, 1, ')');
                }

                //this do while loop decrements the k value until it reaches the operator
                do {
                    k--;
                } while ((input.at(k) != '+') && (input.at(k) != '-') && (input.at(k) != '*') && (input.at(k) != '/') && (k != 0)); 


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
        if (((input.at(i) == '+') || (input.at(i) == '-')) && (input.at(i-1) != '(')) { // check for + and - where negatives are not present
            //insert proper brackets at proper location
            input.insert(i+1,1,'(');   
                input.insert(i,1,')');     
                i++;
            }
        }
    //inser brackets at beginning and the end
        input.insert(0,1,'(');  
            input.insert(input.length(),1,')'); 

            for (int i = 0; i < input.length(); i++) {
        //look for multiplication or division signs where a  closed bracket is not present behind it
        //and then insert brackets properly
                if (((input.at(i) == '*') || (input.at(i) == '/')) && (input.at(i-1) == ')')) { 

                    input.insert(i+1,1,'(');
                        input.insert(i,1,')'); 
                        i++;
                    }
        //same as the upper one but with a open bracket infront of it and then insert brackets properly
                    else if (((input.at(i) == '*') || (input.at(i) == '/')) && (input.at(i+1) == '(')) {  
                        input.insert(i+1,1,'(');        
                            input.insert(i,1,')');          
                            i++;
                        }
                    }

                    return input;
                }
//Eliminate spaces in input expression
                string stripSpace(string express)   
                {
    //loop through the expression and delete space if there is any
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
    //infinitily run the program
                    while (1<2) {               
    string input;               //var to hold the input from the user
    bool check =true;           //boolean to check if the input is valid
    int openbrack=0;            //var to count the number of open brackets
    int closebrack=0;           //var to count the number of closed brackets

    //get user input and terminate by entering a "#"
    cout << "Please Enter an expression: ";         
    getline(cin,input);                             
    if (input == "#") {
        break;      
    }


    // checks if all the characters are valid characters including spaces
    if (check==true){                               
        for (int i=0; i<input.length();i++){   
            //checks if the input string contains the valid characters by comparing with ascii values         
            if ((int(input[i]) < 40 && int(input[i])!= 32) || int(input[i]) > 57 || int(input[i])==44 || int(input[i])==46){            
                        check=false;                
                    }                           
            }                                   

    }                                           


    //executes the next validation check only if the check variable is still set to true
    if (check==true){                           
    bool spacecheck=false;                      // var set to true if a space is encountered
    int whiteindex=0;                           //var to hold the index of the white space
    char l;                                     // variable char l to hold the left character before the operand
         //checks if the string has any whitespaces
        for (int i=0;i<input.length();i++){        
            if (int(input[i])==32){                
                spacecheck=true;                    
            }                                      
        }                                           

        if (spacecheck==true && (int(input[0])==32 || int(input[input.length()]==32))){  // if there are white spaces then makes sure they are not first and last characters
            check=false;                                                                //sets check to false
        }                                                                               //end of if


        //checks to see white space only exists between operands and operators
        if (check==true&&spacecheck==true){                     //only runs if the string given has any white spaces
            check=false;                                        

            for (int i=0; i<input.length(); i++){               
                if(int(input[i])!=32&&whiteindex==0){           //if a value is found that is not empty and the whiteindex is 0
                    int c=i;                                    // sets counter var c to the index i (so the value of i is not chenged when counting back)
                    if (input[i]==')'){                         //checks if the input is an closed bracket
                        while(int(input[c])<48||int(input[c])>57){          //while loop counts back till it encounters a number
                            c--;                               
                        }                                      
                    }                                           
                    l=input[c];                                 // then this becomes the left side character
                }                                               

                if (int(input[i])==32){                         //when a white space is encountered the whiteindex is made a non zero value
                    whiteindex=i;                               //white index value is set
                }                                               

                if(int(input[i])!=32&&whiteindex!=0){           //if the white index is not zero and the next number is not empty
                    //then check if the last character before a white space was a number and the new character is an operand
                    if (((l >= 48) && (l <= 57)) && ((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')||(input[i]==')'))){      
                        int j=i;                        
                        if (input[i]==')'){             // checks if closed bracket is encountered
                            while(input[j]!='+'||input[j]!='-'||input[j]!='*'||input[j]!='/'){  //runs while loop while characters represent a number
                                j=j+1;                  //increases the j count by 1, as long as a number is encountered
                            }                           
                        }                               
                        check=true;                                                                 
                        whiteindex=0;                                                             
                        l=input[j];                                                             
                    }                                                                           
                    else if((l=='+'||l=='-'||l=='*'||l=='/')&&((int(input[i])>=48&&int(input[i])<=57)||(input[i]=='('))){
                        int j=i;                            //sets the value of j to to i so i does not change
                        if (input[i]=='('){                 //checks if the value is a open index
                                while (int(input[j])<48||int(input[j])>57){         //while loop checks if the character is not a number
                                    j=j+1;                                          
                                }                                   
                        }                                          

                        check=true;                              
                        whiteindex=0;                           
                        l=input[j];                             //resets the l character to the one at the jth index in the input
                    }                                           

                    else{                                       //if neither of the above are satisfied
                        check=false;                            //sets check to false
                        break;                                  //breaks the check loop as no more checks are required
                    }                                           
                }                                               
            }                                                   
        }                                                       
    }                                                           



    //checks if the number of brackets are correct
    if (check==true){                                           //only starts if the other checks have passed

        for (int i=0; i<input.length();i++){                    

            if (input[i]=='('){                                 //checks if an open bracket is found
                    openbrack=openbrack+1;                      //increases open bracket counter
                }                                               
            else if (input [i]==')'){                           //checks if closed bracket is found

                closebrack=closebrack+1;                        //increases closebracket count
            }                                                   

        }                                                       

        if (openbrack != closebrack){                           //checks if the open and close bracket counts are equal
            check=false;                                        //if not equal then sets check to false
        }                                                       



    }                                                           





    // checks if the first character is valid.
    if (check==true){                                           // runs if the previous checks are satisfied
        //sees if one of these characters is encountered first in the input
        if (input[0]=='+' || input[0]=='-'  || input[0]=='/'  || input[0]=='*' || input[0]==')' || input[input.length()-1]=='('){  
            check=false;                                            
        }                                                           
    }                                                               

    //checks if the last character is valid
    if (check==true){                                    //runs if the previous checks are satisfied
        //checks if one of these is found as the last character
        if (input[input.length()-1]=='+'||input[input.length()-1]=='-'||input[input.length()-1]=='*'||input[input.length()-1]=='/'){ 
            check=false;                                
        }                                               

    }                                                   

    // checks if there is a number followed by all signs
    if (check==true){                                   //runs if the previous checks are satisfied
        bool signcheck=false;                           //var to check if an operator is encountered
        bool numcheck=false;                            //var to check if a number is encountered
        for (int i=0; i<input.length(); i++){           
            if (input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i] == '/'){      //checks if an operator is encountered
                signcheck=true;                             //sets sign to true
                for(int j=i; j<input.length();j++){         

                    if((int(input[j])>=48 && int (input[j])<=57)){      // checks if the character is a number
                        numcheck=true;                                  //sets numcheck to true if number is found
                    }                                                   

                }                                                       
            }                                                           


        }                                                               
        if (signcheck!=numcheck){                                       //checks if the sign check is equal to numcheck
            check=false;                                                //sets check to false
        }                                                              


    }                                                                   




    //checks that the expression doesnt have  " )( " and that it doesnt have a '3('
    if (check==true){                                       //runs if the previous checks were true

        for (int i=0; i<input.length(); i++){               
            if (i!=input.length()-1){                       //checks if i is at the last index
                if (input [i]==')' && input[i+1]=='('){     //checks if the character is a closed bracket and the next one is a open bracket
                    check=false;                            
                }                                           

                else if ((int(input[i])>=48 && int (input[i])<=57)&& input[i+1]=='('){          //checks if a number if followed by a openbracket
                    check=false;                                            
                }                                                           
                else if ((int(input[i+1])>=48 && int (input[i+1])<=57)&& input[i]==')'){        //checks if a closed bracket is followed by a number
                    check=false;                                                               
                }                                                                               

                else if ((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')&&(input[i+1]=='+'||input[i+1]=='-'||input[i+1]=='*'||input[i+1]=='/')){       //checks if two operators are beside eachother
                    check=false;                          
                }                                           
                else if ((input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/')&&(input[i+1]==')')){  //checks if operator is followed by a open bracket
                    check=false;                                                                            
                }                           
            }                               
        }                                   
    }                                       

    // checks if there is at least 1 number
    if (check==true){                                   //runs if previous checks are true
        check=false;                                    
        for (int i=0;i<input.length();i++){             
            if (int(input[i])>=48 && int(input[i])<=57){            //checks if there is a number
                check=true;                                         
            }                                                      
        }                                                           
    }                                                               


    //checks if div and mul operators are preceded by a number    
   if (check==true){                                                    //runs if the previous checks are true
        for (int i=0; i<input.length(); i++){                           
            if (input[i]=='/'||input[i]=='*'){                          //looks for multiplycation of division
                check=false;                                            
                for (int j=i; j>0;j--){                                 //counts back to find a number
                    if (int(input[j-1])>=48 && int(input[j-1])<=57){                //if a number if found
                        check=true;                                         
                        break;                                          
                    }                                                   
                    else if (input[j-1]=='+'||input[j-1]=='-'||input[j-1]=='*'||input[j-1]=='/'){       //if another operator is found
                        check=false;            
                        break;                  
                    }                           
                }                               
            }                                   
        }                                       

    }                                           






    if (check==true){                       //creates the objects to parse into the tree if the previous checks are valid

        input = insertBrackets(input);              //calls the brackets method to add brackets

        ArithmeticExpression userInput(input);            // creates object of type arithmetic expression by sending in the input string


        cout << "\n" << userInput.newExpression << " = " << "???" << endl;            // outputs the string entered by the user



    }
}
    return 0;                               
}                                           
