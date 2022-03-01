/*
    Author: Edison Cacers Alejo
    Date: 3/1/2022
    This program takes in a sentence, word, or value of no more than 25 characters, and recognizes wether it is or is not a polindrome.
*/
#include <iostream>
#include <string>
using namespace std;

char stackPushed[25];
unsigned int stackPtr = 0;
char pop();
void push(char);

int main(){
    string userInput; //stores the original user input
    string userInputPushed; //stores the pushed values from the stack
    string userInputPoped; //stores the popped values from the stack
    int userInputSize = 0; //stores the amount of characters or digits the input has
    
    cout<<"Enter a sentence, word, or value -> ";
    getline(cin, userInput);
    
    for(int i = 0; userInput[i] != '\0'; ++i){
        if(isalpha(userInput[i]) or isdigit(userInput[i]) and !isspace(userInput[i])){
            push(tolower(userInput[i]));
            userInputSize++;
        }
        if(userInputSize > 25){
            cout<<"This sentence, word, or value is greater than 25 characters"<<endl;
            return 0;
        }
    }
    
    for(int i = 0; i < userInputSize; ++i){
        userInputPoped += pop();
    }
    
    for(int i = 0; i < userInputSize; ++i){
        userInputPushed += stackPushed[i];
    }

    if(userInputPoped == userInputPushed){
        cout<<userInput<<" is a polindrome"<<endl;
    }
    else{
        cout<<userInput<<" is not a polidrome"<<endl;
    }
    return 0;
}

//This function pushes a character into a stack array, and arranges the stack pointer to point to an open spot
void push(char letterOrDigit){
    stackPushed[stackPtr] = letterOrDigit;
    stackPtr++;
}

//This function pops a character from the stack array, and arranges the stack pointer to point to an open spot
char pop(){
    stackPtr--;
    return stackPushed[stackPtr];
}