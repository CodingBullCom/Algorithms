// File: magic_numbers.cpp
// Created on: 27th Dec 2018
// Updated on: 27th Dec 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.
//
// Input: 2000
// Output: 1 10 12 121 123 1210 1212 1232 1234
// Desciption: A magic number is defined as xyz, where y ∈ {x-1, x+1}, z ∈ {y-1, y+1}

#include <iostream>
#include <vector>

using namespace std;

vector<int> magic_numbers(int lesser_then) {
   int index = 0;
   vector<int> arr;
   arr.push_back(1);

   while(1) {

      int k = arr[index] % 10;
      if ( k != 0) {
          int left = arr[index] * 10 + k - 1;
          int right = arr[index] * 10 + k + 1;
          if (left > lesser_then) break;
          arr.push_back(left);

          if (right > lesser_then) break;
          arr.push_back(right);
      }

      index++;
   }
   return arr;
}

int main() {
    vector<int> result = magic_numbers(2000);
    for(int temp: result)
        cout << temp << " ";
    cout << endl;
}
