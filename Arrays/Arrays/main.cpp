//
//  main.cpp
//  Arrays
//
//  Created by Luciano Almeida on 21/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include "utils.h"

using namespace std;

void show1(string* texts, int length) {
    for(int i = 0; i < length; i++) {
        cout << texts[i] << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    
    string animals[][2] = { {"hue", "hue1"} , {"das", "dasfss"} };
    
    cout << sizeof(animals)/sizeof(animals[0]) << endl;
    unsigned int rows = sizeof(animals)/sizeof(animals[0]);
    for (unsigned int i = 0; i < rows; i++) {
         for (unsigned int j = 0; j < sizeof(animals[i])/sizeof(string); j++) {
             cout << "String[" << i << "][" << j << "] = " << animals[i][j] << endl;
         }
    }
    
    doSomething();
    
    // Arrays and functions
    string texts[] = {"apple", "orange", "banana"};
    show1(texts, 3);
    
    return 0;
}

void doSomething() {
    cout << "Doing something :))" << endl;
}
