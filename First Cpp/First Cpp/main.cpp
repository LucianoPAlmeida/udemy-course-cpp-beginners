//
//  main.cpp
//  First Cpp
//
//  Created by Luciano Almeida on 14/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int i = 43984;
    char c = (char)i;
    cout << c << endl;
    cout << sizeof(wchar_t) << endl;
    
    
    string password = "hello";

    cout << "Enter the password > " << flush;
    string input;
    cin >> input;
    cout << "'" << input << "'" << ", count: " << input.size() << endl;

    if (input == password) {
        cout << "Matches" << endl;
    } else {
        cout << "Wrong" << endl;
    }


    float f = 1.1;
    
    if (f - 1.1 < 0.01) {
        cout << "Equals" << endl;
    } else {
        cout << "Not equal" << endl;
    }
    
    return 0;
}
