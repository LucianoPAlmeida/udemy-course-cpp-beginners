//
//  User.cpp
//  CppGuidelines
//
//  Created by Luciano Almeida on 30/07/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include "User.hpp"

User::~User() {
    delete this->name;
}

std::string* User::getName() {
    return this->name;
}
