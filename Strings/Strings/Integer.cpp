//
//  Integer.cpp
//  Strings
//
//  Created by Luciano Almeida on 02/10/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include "Integer.hpp"

Integer::~Integer() {
}

Integer::Integer() {
}

Integer::Integer(int value) {
    this->value = value;
}

Integer::operator int() {
    return this->value;
}

int Integer::operator+=(Integer i) {
    return this->value+=i;
}
