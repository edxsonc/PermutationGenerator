/*
    Author: Edison Caceres Alejo
    Date: 3/1/2022
    This program recursively generates all the permutations of any given n characters. 
*/

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N_VALUE = 6;
void generatePermutations(string, int, int, ofstream&);
int main(){
    int n; //stores the amount of characters user wants to permute
    char inputCharacter; //used to read in a character
    ofstream permutations; //initalizes a file for output
    string outputFile = "permutations.txt"; //initalizes the output file name
    string userString; //stores the string the user wants to permute

    cout<<"Enter the number of characters you want to permute -> ";
    cin>>n;
    
    if(n > MAX_N_VALUE){
        cout<<"The number of characters cannot be greater than 6"<<endl;
        return 0;
    }
    else{
        cout<<"Enter "<<n<<" characters -> ";
        for(int i = 0; i < n; ++i){
            cin>>inputCharacter;
            userString += inputCharacter;
        }
    }
    permutations.open(outputFile);
    generatePermutations(userString, 0, n-1, permutations);

    cout<<"Your results are stored in the file: 'permutations.txt'"<<endl;

    permutations.close();
    return 0;
}

//this function recursively generates the permutations of a string and outputs it to a file
void generatePermutations(string userWord, int startingIndex, int endingIndex, ofstream& result){
    char placeHolder;
    if(startingIndex == endingIndex){
        result<<userWord<<endl;
    }
    else{
        for(int i = startingIndex; i <= endingIndex; i++){
            placeHolder = userWord[i];
            userWord[i] = userWord[startingIndex];
            userWord[startingIndex] = placeHolder;

            generatePermutations(userWord, startingIndex+1, endingIndex, result);

            placeHolder = userWord[i];
            userWord[i] = userWord[startingIndex];
            userWord[startingIndex] = placeHolder;
        }
    }
}
