//
//  main.cpp
//  PThread
//
//  Created by Luciano Almeida on 7/23/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>


int main(int argc, const char * argv[]) {

    pthread_mutex_t mutex = pthread_mutex_t();
    
    pthread_mutex_init(&mutex, NULL);
    
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    
    pthread_mutex_init(&mutex, &attr);
    
    pthread_mutex_lock(&mutex);

    std::cout << "Hello world \\o/" << std::endl;
    
    pthread_mutex_unlock(&mutex);
    
    return 0;
}
