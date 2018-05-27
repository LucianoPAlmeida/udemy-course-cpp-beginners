//
//  main.cpp
//  Classes
//
//  Created by Luciano Almeida on 21/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Cat.h"
#include "Dog.h"
#include "Mouse.h"

int main(int argc, const char * argv[]) {
    auto * jimmy = new Cat("Jimmy");
    Mouse * jerry = new Mouse("Jerry");
    
    Dog snoop("Snoop");
    jimmy->noise();
    snoop.noise();
    jimmy->setName("Jimmy II");
    jimmy->noise();
    jerry->noise();

    delete jimmy;
    delete jerry;
    int i = 435;
    std::stringstream ss;
    ss << "Number is : " << i;
    std::cout << ss.str() << std::endl;
    return 0;
}
