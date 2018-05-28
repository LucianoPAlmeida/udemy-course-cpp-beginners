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

Cat::Cat(const Cat& other) {
    this->name = other.name;
    std::cout << "Copy constructor" << std::endl;
}

std::string Cat::getName() {
    return name;
}

Cat::~Cat() {
    std::cout << "Cat " << name << " dealocated." << std::endl;
}

void Cat::noise() const {
    super::noise();
    std::cout << name <<" says Meouww!" << std::endl;
}

