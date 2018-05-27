//
//  Cat.cpp
//  Classes
//
//  Created by Luciano Almeida on 21/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include "Cat.h"

void Cat::setName(std::string name) {
    this->name = name;
}

std::string Cat::getName() {
    return name;
}

Cat::~Cat() {
    std::cout << "Cat is Dead." << std::endl;
}

void Cat::noise() const {
    std::cout << name <<" says Meouww!" << std::endl;
}

