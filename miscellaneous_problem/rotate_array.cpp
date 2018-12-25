// File: rotate_array_left.cpp
// Created on: 25th Dec 2018
// Updated on: 25th Dec 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

// find odd number from numbers where all numbers are in pair except one
// Input:: arr = 1, 2, 3, 4, 5, 6, 7, 8, 9 d = 4
// Output:: 5, 6, 7, 8, 9, 1, 2, 3, 4

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
   return b == 0 ? a: gcd(b, a%b);
}

void left_rotate(vector<int> &arr, int d) {
  int n = arr.size();
   d = d % n;
   for (int i = 0; i < gcd(d, n); i++) {
     int j = i, k = 0, temp = arr[i];
       while(true) {
          k = j + d;
          if(k >= n) k -= n;
          if(k == i) break;
          arr[j] = arr[k];
          j = k;
       }
       arr[j] = temp;
   }
}

int main() {
    vector<int> arr {1, 2, 3, 4, 5, 6, 7, 8, 9};
    left_rotate(arr, 4);
    for(int temp: arr)
      cout <<  temp << " ";
    cout << endl;
    return 0;
}
