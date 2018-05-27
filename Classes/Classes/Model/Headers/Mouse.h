//
//  Mouse.hpp
//  Classes
//
//  Created by Luciano Almeida on 27/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#ifndef MOUSE_H_
#define MOUSE_H_

#include <iostream>

class Mouse {

private:
    std::string name;
public:
    Mouse(std::string name): name(name) {};
    void noise() const;
    ~Mouse();
};

#endif /* Mouse_hpp */
