//
//  main.c
//  Reverse Order String
//
//  Created by Ahmed Almansor on 4/4/17.
//  Copyright © 2017 . All rights reserved.
//

#include <stdio.h>     // I/O library
#include <string.h>   //string library
#include <stdbool.h>  //boolean library
#include <ctype.h>  // C library

char* ReverseWords (char s[]){
    // this function will get the string and split the words in the string and then reverse the string order.
			 // the algorithms used is by using a forloop, if-statments, and basic math.
			 // create a ptr for char new Order to return.
    char* RStr;          // This is a pointer of a type char to point to the new ordered string
    char newOrder[512];    // A string that will hold the new string
    bool isWordFound = true;   // boolean varible that will used to find each word
    unsigned long int sizeOfS = strlen(s)-1; // int that hold the string size
    int wordCount =0;           // this int will be used as letter counter to find each word
    int newSS =0;              // to hold the new string size value
    bool isWordCpy = false;    // this boolean variable will turn true if the word is copyed into the new string.
    unsigned long int Position =0;           // this will be used to point to the position of the first letter when the word found inorder to copy it to the new string.
    // for-loop to find each word and reverse its order
    for (unsigned long int i = sizeOfS; i > 0; i--){
        if (isWordFound){     // word found & begin copying
            if (isspace(s[i])){
                if(i == sizeOfS){
                    // This block is used as safty if the last char is a space so it does not copy it!
                    //do nothing!
                }
                else{
                    if(i == 0){  // is the space 1st one?
                        Position  = i;
                        isWordFound = false;    // word found!
                        isWordCpy = true;      // go to next condition of copying the word into the new string.
                    }
                    else{                 // Space in between words.
                        Position  = i+1;
                        isWordFound = false;
                        isWordCpy = true;
                    }
                }
            }
            else{
                if (i == 0){      // last word copying if there is no space. This block is for safty reason.
                    Position  = i;
                    isWordFound = false;
                    isWordCpy = true;
                    wordCount++;
                }
                else{        // counting the letters in the orignal string.
                    wordCount++;
                }
            }
        }
        if (isWordCpy){        // code block that will copy the word in the new string.
            for (int j= 0; j < wordCount; j++){   // for-loop determined by size of the word to copy the word.
                newOrder[newSS] = s[Position];
                Position++;
                newSS++;
            }
            newOrder[newSS] = ' ';   // creating space between the words in the new string
            newSS++;
            wordCount = 0; // just for safty!
            isWordFound = true;     // word copyed look for the next one
            isWordCpy = false;       // turn off the word copying
            wordCount = 0;          // set letter counter to zero.
        }
        
    }
    RStr = newOrder;    // copy the new string to a pointer of type char
    
    return RStr;   // return the reversed string.
    
}

int main(){
    char   c[512]; 					//a string to store string inputted
    
    printf("Write the desired sentence: \n");   // Statment will be displayed for the user asking for prompt.
    gets(c);                           // get string from the terminal until user hit "Enter".
  
    printf("%s \n", ReverseWords (c));  // print funtion for Reverse Order String  #2
    
    
    return 0;
}
