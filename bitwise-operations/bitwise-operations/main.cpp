//
//  main.cpp
//  bitwise-operations
//
//  Created by Luciano Almeida on 21/08/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << "10 and 2" << std::endl;
    std::cout << "AND" << (10 & 2) << std::endl;  // "AND"
    std::cout << "OR" << (10 | 2) << std::endl;  // "OR"
    std::cout << "XOR" << (10 ^ 2) << std::endl;  // "XOR"
    
    std::cout << "NOT 10" << (~10) << std::endl;  // "NOT"
    std::cout << "NOT 10 << 2: " << (10 << 2) << std::endl;  // "bit shift left"
    std::cout << "NOT 10 >> 1: " << (10 >> 1) << std::endl;  // "bit shift right"

    return 0;
}
