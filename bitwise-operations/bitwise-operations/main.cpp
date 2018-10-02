//
//  main.cpp
//  bitwise-operations
//
//  Created by Luciano Almeida on 21/08/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>

int tail_recursive_function(int n) {
    if (n == 0) return n;
    return tail_recursive_function(n - 1);
}

template <typename T> T const& max(T const& i, T const& j ) {
    return i < j ? j: i;
}

int main(int argc, const char * argv[]) {
    std::cout << "10 and 2" << std::endl;
    std::cout << "AND" << (10 & 2) << std::endl;  // "AND"
    std::cout << "OR" << (10 | 2) << std::endl;  // "OR"
    std::cout << "XOR" << (10 ^ 2) << std::endl;  // "XOR"
    
    std::cout << "NOT 10" << (~10) << std::endl;  // "NOT"
    std::cout << "NOT 10 << 2: " << (10 << 2) << std::endl;  // "bit shift left"
    std::cout << "NOT 10 >> 1: " << (10 >> 1) << std::endl;  // "bit shift right"

    std::cout << tail_recursive_function(4) << std::endl;
    
    int m = max(130, 30);
    double md = max(20.1, 25.5);
    
    std::cout << "Max: " << m << std::endl;
    std::cout << "Max Float: " << md << std::endl;
    
    
    // Bit representation
    int8_t value = 1;
    
    for(int i = sizeof(value) * 8; i >= 0; i--) {
        std::cout << ((value >> i) & 0x00000001);
    }
    std::cout << std::endl;
    
    return 0;
}


