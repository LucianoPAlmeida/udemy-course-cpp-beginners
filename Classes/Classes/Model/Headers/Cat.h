//
//  Cat.hpp
//  Classes
//
//  Created by Luciano Almeida on 21/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#ifndef CAT_H_
#define CAT_H_
#include <iostream>
#include "Animal.h"
class Cat: public Animal {
private:
    std::string name;
public:
    typedef Animal super;
    void setName(std::string name);
    std::string getName();
    
    void noise() const;
    Cat() {};
    Cat(std::string name): name(name) {};
    Cat(const Cat& other);
    ~Cat();
};

#endif /* Cat_hpp */
