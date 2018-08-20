//
//  main.cpp
//  PThread
//
//  Created by Luciano Almeida on 7/23/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    pthread_mutex_t mutex = pthread_mutex_t();
    
    pthread_mutex_init(&mutex, NULL);
    
    pthread_mutex_lock(&mutex);
    
    
    
    pthread_mutex_unlock(&mutex);
    
    return 0;
}
