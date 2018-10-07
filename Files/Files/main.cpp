//
//  main.cpp
//  Files
//
//  Created by Luciano Almeida on 07/10/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
    
//    std::fstream f;
//    f.open("./text.txt", std::fstream::app);
//    if (f.is_open()) {
//        std::string in;
//        std::cin >> in;
//        f << in << std::endl;
//
//        f.close();
//    }
    
    
    std::fstream file;
    file.open("./text1.txt");
    if (file.is_open()) {
        std::string buff;
        
        do {
            file >> buff;
            std::cout << buff << std::endl;
        } while(!file.eof());
        
        std::cout << "rdstate: " << file.rdstate() << std::endl;
        std::cout << "eofbit & failbit: " << (std::ifstream::eofbit | std::ifstream::failbit) << std::endl;
        
        if (file.rdstate() == (std::ifstream::eofbit | std::ifstream::failbit)) {
            std::cout << "Error: eof() and fail()" << std::endl;
        }
        file.close();
    }
    
    return 0;
}
