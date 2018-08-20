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
Cat* giveMeACat() {
    return new Cat("A Cat");
}

void noiseMaker(Animal * animal) {
    animal->noise();
}

int main(int argc, const char * argv[]) {
    
    Cat * jimmy = new Cat("Jimmy");
    std::cout << sizeof(jimmy) << std::endl;
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

    // Copy constructor
    Cat c1("C1");
    Cat c2 = c1;
    c2.setName("C2");
    c1.noise();
    c2.noise();

    // Returning
    Cat* a = giveMeACat();
    a->noise();
    
    // Memory allocation
    Cat * cats = new Cat[10];
    char name = 'a';
    for (int i = 0; i < 10; i++) {
        cats[i].setName(std::string(1, name + i));
    }
    delete [] cats;
    
    // Inheritance
    Cat * garfield = new Cat("Garfield");
    Animal * animal = new Animal();
    noiseMaker(garfield);
    noiseMaker(animal);
    
    
    
    return 0;
}
