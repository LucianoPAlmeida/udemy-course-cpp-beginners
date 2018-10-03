//
//  Integer.hpp
//  Strings
//
//  Created by Luciano Almeida on 02/10/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#ifndef Integer_hpp
#define Integer_hpp

#include <stdio.h>

class Integer {
  
    private:
    int value;
    public:
    Integer();
    Integer(int);
    operator int();
    int operator +=(Integer);
    virtual ~Integer();
};

#endif /* Integer_hpp */
