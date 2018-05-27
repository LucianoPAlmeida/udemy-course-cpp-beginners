//
//  main.cpp
//  Pointers
//
//  Created by Luciano Almeida on 27/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
// Reference variable
void mutateRef(int &ref) {
    ref = 123;
}

void aritimetics1() {
    int raw = 435635;
    
    int hours, minutes, seconds;
    hours = raw/3600;
    minutes = (raw%3600)/60;
    seconds = (raw%3600)%60;
    
    std::cout << hours << " : " << minutes << " : " << seconds << std::endl;
}

void aritmetics2() {
    for (int i = 0; i <= 10000; i++) {
        if (i%100 == 0) {
            std::cout << "i = " << i << " ..." << std::endl;
        }
    }
}

void pointerIteration() {
    std::string texts[] = {"One", "Two", "Three"};
    std::string* pTexts = texts;
    
    for (int i = 0; i < 3; i++) {
        std::cout << i << " = " << *(pTexts + i) << std::endl;
    }
}

void charArray() {
    char text[] = "hello world";
    
    for (int i = 0; i < sizeof(text); i++) {
        std::cout << text[i] << " " << std::flush;
    }
    std::cout << std::endl;
    int aux = 0;
    do {
        std::cout << text[aux] << " " << std::flush;
        aux++;
    } while(text[aux]);
    std::cout << std::endl;
}

void refereces() {
    int value1 = 10;
    int &rValue = value1;
    
    rValue = 15;
    std::cout << "Reference: " << value1 << std::endl;
}

int main(int argc, const char * argv[]) {
    
    int value = 6;
    mutateRef(value);
    std::cout << value << std::endl;
    
    double dValue = (double)7/2;
    std::cout << "Double Division: " << dValue << std::endl;
    
    int iValue = 9;
    std::cout << "Int Double: " << iValue << std::endl;
    
    aritimetics1();
    aritmetics2();
    
    pointerIteration();
    
    charArray();
    
    refereces();
    return 0;
}




