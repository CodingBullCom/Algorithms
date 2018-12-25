// File: odd_man_out.cpp
// Created on: 25th Dec 2018
// Updated on: 25th Dec 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

// find odd number from numbers where all numbers are in pair except one
// Input:: 7, 3, 9, 3, 1, 7, 2, 9, 2 output:: 1

#include <iostream>
#include <vector>

using namespace std;

int odd_man_out(vector<int> arr) {
    int result = 0;
    for(int temp: arr) {
       result ^= temp;
    }
    return result;
}

int main() {
   vector<int> arr{7, 3, 9, 3, 1, 7, 2, 9, 2};
   cout << odd_man_out(arr) <<endl;
   return 0;
}
