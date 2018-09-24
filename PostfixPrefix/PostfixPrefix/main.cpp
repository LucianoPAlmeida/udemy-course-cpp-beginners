//
//  main.cpp
//  PostfixPrefix
//
//  Created by Luciano Almeida on 24/09/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int value1 = 10;
    int value2 = 10;

    std::cout << "Postfix = " << value1++ << std::endl;
    std::cout << "Prefix = " << ++value2 << std::endl;

    return 0;
}
