//
//  Dog.hpp
//  Classes
//
//  Created by Luciano Almeida on 21/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#ifndef DOG_H_
#define DOG_H_
#include <iostream>

class Dog {
private:
    std::string name;
public:
    Dog(std::string name): name(name) {};
    void noise();
    
    std::string toString();
};


#endif /* DOG_H_ */
