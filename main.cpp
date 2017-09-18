//
//  main.cpp
//  Lab 1
//
//  Created by Robert Bryce Michaud on 9/11/17.
//  Copyright © 2017 Robert Bryce Michaud. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// 'filesize()' function created with the help of Stack Overflow question
// https://stackoverflow.com/questions/5840148/how-can-i-get-a-files-size-in-c
// Question by Sofie Sperner:  https://stackoverflow.com/users/655860/sophie-sperner
// Answer by Spyros: https://stackoverflow.com/users/1580201/spyros

//gets the size of the file in bytes
std::ifstream::pos_type filesize(string filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}


int main(int argc, const char * argv[]) {
    
    
    //initialize
    fstream file; //read file
    
    string response;
    cout << "Which file do you want counted? (IntFile1.txt or IntFile2.txt) \n" << endl;
    cin >> response;
    
    string fileName = response;
    
    
    file.open(fileName);

    
    //checks if the file is open
    if(file.is_open()){
        
        //Initialize here in case the file isn't open. Save some CPU effort
        long long size = filesize(fileName); //calls 'get size' function
        
        int count = 0; //file counter, excludes spaces and tabs
        char ch; //character space

        //iterates through each element in the file
        for(int i = 0; i <= size; i++){
            
            file.seekg(i); //locates element in file at index 'i'
            file.get(ch); //gets the character at the index 'seekg()' is pointing to
            
            if(ch != '\t'){ //if the element isn't a tab, continue
                
                if(ch != ' '){ //if the element isn't a space, continue
                    
                    count++; //increment the count by one
                    
                    if(count == 1 || count == 2){
                        double num = double(ch-48); //converts 'ch' to a double (0 is assigned 48)
                        cout << "The first two: \n" << num << endl;
                        
                            
                    }
                    

                }
            }
            
        }
        
        cout << "The file is " << count << " number(s) long" << endl; //prints the count to the console
        
        file.close(); //closes file for good measure
        
    }else{
        
        cout << "The file isn't open or doesn't exist" << endl; //error if file isn't open
        
    }

    
    return 0;
}

