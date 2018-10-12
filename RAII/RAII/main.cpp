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

void test(const std::function<bool (int)>& f);

int main(int argc, const char * argv[]) {
    std::mutex mutex;
    
    lock(mutex);
    raii(mutex);
    
    int j = 0;
    const std::string* s = new std::string("Brasília, Brasil");
    
    auto f = [=, &s](const int i) {
        std::cout << *s << std::endl;
        if (i < j) {
            return false;
        }
        if (i == 4) {
            return true;
        }
        return false;
    };
    
    test(f);
    
    delete s;
    
    return 0;
}

void test(const std::function<bool (int)>& f) {
    std::cout << f(4) << std::endl;
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
