//
//  main.cpp
//  Strings
//
//  Created by Luciano Almeida on 27/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include "Integer.hpp"

void reverseChar(char * cArray, int lenght);

int main(int argc, const char * argv[]) {

    std::string str = "Hello, World!";
    std::string* reversed = new std::string();
    reversed->resize(str.length());
    std::reverse_copy(str.begin(), str.end(), reversed->begin());
    std::cout << str << ": " << *reversed << std::endl;
    
    // Manual
    char array[] = "Hello, World!u";
    std::cout << array << ": " << std::flush;
    reverseChar(array, sizeof(array));
    std::cout << array << std::endl;
    
    delete reversed;
    
    Integer interger = 1;
    
    int v = interger;
    
    std::cout << "Value: " << interger << std::endl;
    std::cout << "Primitive: " << v << std::endl;
    
    interger+= 3;
    std::cout << "Pe: " << interger << std::endl;

    
    return 0;
}

void reverseChar(char * cArray, int lenght) {
    
    for (int i = 0; i < lenght/2; i++) {
        char aux = cArray[i];
        cArray[i] = cArray[lenght - i - 2];
        cArray[lenght - i - 2] = aux;
    }
    
}
