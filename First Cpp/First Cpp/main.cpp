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

class C {
public:
  int m = 0;
  
  void f() const {
    // m = 2; error: Cannot assign to non-static data member within const member function 'f'
    int *p = const_cast<int *>(&m);
    *p = 2;
    // Cool!
    const_cast<C *>(this)->m = 11;
  }
};

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
  
  cout << "(Hello, world!\n)" << endl;
  
  float f = 1.1;
  
  if (f - 1.1 < 0.01) {
    cout << "Equals" << endl;
  } else {
    cout << "Not equal" << endl;
  }
  
  std::string s = "dasd";
  
  // Const cast
  
  const int ii = 0;
  
  int *pi = const_cast<int*>(&ii);
  // Removing const qualifier and assign.
  *pi = 10;
  
  std::cout << *pi << std::endl;
  
  
  C cc;
  cc.f();
  std::cout << cc.m << std::endl;
  
  return 0;
}
