// File: matrix_spiral_print.cpp
// Created on: 13th Dec 2018
// Updated on: 12th Dec 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

#include <iostream>
#include <vector>

using namespace std;

void matrix_spiral_print(vector<vector<int>> array) {
  int rows = array.size();
  int cols = array[0].size();
  int i, k = 0, l = 0;
  while (k < rows && l < cols) {
     for (i = l; i < cols; i++)
        cout << array[k][i] << " ";
     k++;

     for ( i = k; i < rows; i++)
        cout << array[i][rows-1] << " ";
     cols--;

    if( k < rows) {
       for (i = cols-1; i >= l; i-- )
          cout << array[rows-1][i] << " ";
       rows--;
    }

    if( l < cols) {
       for (i = rows-1; i >= k; i-- )
          cout << array[i][l] << " ";
        l++;
     }
   }
   cout << endl;
}

void printArray(vector<vector<int>> array) {
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    for(row=array.begin(); row != array.end(); row++) {
        for(col=row->begin(); col != row->end(); col++) {
             cout << *col << " " ;
        }
        cout << endl;
    }
}

vector<vector<int>> test_array(int rows, int cols) {
    vector<vector<int>> array(rows);
    for(int i = 0; i < rows; i++) {
      vector<int> temp(cols);
      for(int j = 0; j < cols; j++) {
        temp[j] = i*cols + j;
      }
      array[i] = temp;
    }
    return array;
}

int main() {
     vector<vector<int>> array = test_array(5, 6);
     cout << "Printing array" << endl;
     printArray(array);
     cout << "Printing matric in spiral form" << endl;
     matrix_spiral_print(array);
     return 0;
}
