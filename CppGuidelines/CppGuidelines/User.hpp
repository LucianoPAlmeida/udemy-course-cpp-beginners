//
//  User.hpp
//  CppGuidelines
//
//  Created by Luciano Almeida on 30/07/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>
#endif /* User_hpp */

class User {
private:
    std::string * name;
public:
    std::string* getName();
    User(std::string * name): name(name) {};
    ~User();
};
