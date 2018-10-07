//
//  main.cpp
//  Templates
//
//  Created by Luciano Almeida on 06/10/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include "Point.hpp"

class A {
    
};

class C: public A {
    
};

class B: public A {
public:
    int a;
};

template <typename A, typename B, typename T>
T add(A x, B y) {
    return x + y;
}
typedef Point<int> PointI;

int main(int argc, const char * argv[]) {
    int r = add<double, double, int>(3.0, 2.5);
    std::cout <<  r << std::endl;
    A * c = new C();
    A * i = reinterpret_cast<A*>(c);
    std::cout <<  i << std::endl;
    
    Point<int> * p = new PointI();
    p->x = 20;
    p->y = 30;
    
    delete p;
    
    return 0;
}
