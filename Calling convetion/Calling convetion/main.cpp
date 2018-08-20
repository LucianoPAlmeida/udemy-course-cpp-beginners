//
//  main.cpp
//  Calling convetion
//
//  Created by Luciano Almeida on 7/17/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
int __cdecl add(int x, int y) {
    return x + y;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string * s;
    std::cout << "Hello, World!\n";
    
    std::cout << add(2, 3) << std::endl;
    
    std::cout << sizeof(s) <<std::endl;
    return 0;
}


