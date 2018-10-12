//
//  main.cpp
//  RAII
//
//  Created by Luciano Almeida on 11/10/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>

void f();
void lock(std::mutex& m);
void raii(std::mutex& m);

int main(int argc, const char * argv[]) {
    std::mutex mutex;
    
    lock(mutex);
    raii(mutex);
    
    return 0;
}

void f() {
    
}

void lock(std::mutex& m) {
    m.lock();
    f();
    m.unlock();
}

void raii(std::mutex& m) {
    std::lock_guard<std::mutex> lock(m); // Uses RAII Resource Acquisition Is Initialization.
    f();
}
