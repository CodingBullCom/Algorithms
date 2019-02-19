// File: magic_square.cpp
// Created on: 19th Feb 2019
// Updated on: 19th Feb 2019
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.
//
// Input: 3
// Output:
//         2  7  6
//         9  5  1
//         4  3  8
// Desciption: A magic square is defined as sum of all elements in every row are equal,
// sum of elements of all columns are equal, sum of elements of diagonals are equal
// To create magic square, there are simple three rules
// 1. The position of next number is calculated by decrementing row number of previous
//   number by 1, and incrementing the column number of previous number by 1. At any
//   time, if the calculated row position becomes -1, it will wrap around to n-1.
//   Similarly, if the calculated column position becomes n, it will wrap around to 0.

// 2. If the magic square already contains a number at the calculated position,
// calculated column position will be decremented by 2, and calculated row
// position will be incremented by 1.
//
// 3. If the calculated row position is -1 & calculated column position is n,
// the new position would be: (0, n-2).
// Ref: https://www.geeksforgeeks.org/magic-square/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class magic_square {
public:
    vector<vector<int>> generate(int n);
    bool is_valid(vector<vector<int>> array);
    void print(vector<vector<int>> array);
};

vector<vector<int>> magic_square :: generate(int n) {
    vector<vector<int>> array(n, vector<int> (n, 0));
    int i=n/2, j=n-1;
    for(int num = 1; num <= n*n; ) {
      if ( i == -1 && j == n ) {
          i = 0;
          j = n-2;
      } else {
        if ( j == n ) j = 0;
        if ( i < 0 ) i = n - 1;
      }
      if ( array[i][j] != 0) {
          j -= 2;
          i++;
          continue;
      } else {
        array[i][j] = num++;
      }
      i--;
      j++;
    }
    return array;
}

bool magic_square :: is_valid(vector<vector<int>> array) {
  int n = array.size();
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += array[0][i];
  }

  for(int i = 0; i < n; i++) {
      int temp_sum = 0;
      for(int j = 0; j < n; j++)
         temp_sum += array[i][j];
      if ( temp_sum != sum )
        return false;
  }
  return true;
}

void magic_square :: print(vector<vector<int>> array) {
    int n = array.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%3d ", array[i][j]);
        printf("\n");
    }
}

int main() {
    magic_square magic_square;
    vector<vector<int>> array = magic_square.generate(5);
    magic_square.print(array);
    string result = magic_square.is_valid(array) ? "Valid" : "Invalid";
    cout << result << endl;

    //Testing negative use case
    vector<vector<int>> vect({{9, 4, 22, 16, 15}, {2, 21, 20, 14, 8}, {25, 19, 23, 7, 1}, {18, 12, 6, 5, 24}, {11, 10, 3, 13, 17}});
    magic_square.print(vect);
    result = magic_square.is_valid(vect) ? "Valid" : "Invalid";
    cout << result << endl;
}
