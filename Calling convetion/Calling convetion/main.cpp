//
//  main.cpp
//  Calling convetion
//
//  Created by Luciano Almeida on 7/17/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

// Calling conventions: https://msdn.microsoft.com/en-us/library/zkwh89ks.aspx
// Registers: https://wiki.skullsecurity.org/index.php?title=Registers
#include <iostream>

// __cdecl is the default calling convention for C and C++ programs. The __cdecl calling convention requires each function to include stack cleanup code. It makes this generate executables larger than __stdcall.
int __cdecl add(int x, int y) {
    return x + y;
    
}
// __fastcall calling convetions is only aplied for x86 architectures. Is a calling convention that requires that the two first arguments are to be passed in the volatile registers ECX and EDX when possible.
int __fastcall sub(int x, int y) {
    return x - y;
}

//
int __stdcall mul(int x, int y) {
    return x * y;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string * s;
    std::cout << "Hello, World!\n";
    
    std::cout << "Add __cdecl: " << add(2, 3) << std::endl;
    std::cout << "Sub __fastcall: " << sub(2, 3) << std::endl;
    std::cout << "Mul __stdcall: " << mul(2, 3) << std::endl;

    
    std::cout << sizeof(s) <<std::endl;
    return 0;
}


