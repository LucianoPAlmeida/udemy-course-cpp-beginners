//
//  main.cpp
//  Sorting
//
//  Created by Luciano Almeida on 11/09/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <array>
#include <vector>
#include <chrono>
#include <ctime>

int main(int argc, const char * argv[]) {
    
    std::vector<int> numbers = {0, 2, 1, 4, 5, -2, 3};
    std::partial_sort(numbers.begin(), numbers.begin() + 4, numbers.end(), std::greater<int>());
    
    std::cout << "Descending: " << std::flush;
    for(auto i: numbers) {
        std::cout << i << " " << std::flush;
    }
    
    std::partial_sort(numbers.begin(), numbers.begin() + 4, numbers.end());

    std::cout << std::endl;
    std::cout << "Ascending: " << std::flush;
    for(auto i: numbers) {
        std::cout << i << " " << std::flush;
    }
    std::cout << std::endl;
    
    
    auto clock = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(clock);
    std::cout << std::ctime(&time) << std::endl;
    return 0;
}
