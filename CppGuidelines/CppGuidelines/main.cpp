//
//  main.cpp
//  CppGuidelines
//
//  Created by Luciano Almeida on 30/07/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include "User.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    User * user = new User(new std::string("Toin"));
    std::cout << *user->getName() << std::endl;
    delete user;
    return 0;
}
