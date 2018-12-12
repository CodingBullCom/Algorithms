// File: rotate_by_90_degree.cpp
// Created on: 12th Dec 2018
// Updated on: 12th Dec 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

#include <iostream>
#include <vector>

using namespace std;

void rotate_by_90_degree_anticlockwise(vector<vector<int>> &array) {
    int size = array.size();
    for (int layer = 0; layer < size/2; layer++) {
        int first = layer;
        int last = size - first - 1;
        for (int i = first; i < last; i++) {
           int offset = i - first;
           int temp = array[first][i];
           array[first][i] = array[i][last];
           array[i][last] = array[last][last-offset];
           array[last][last-offset] = array[last-offset][first];
           array[last-offset][first] = temp;
        }
    }
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

vector<vector<int>> test_array(int size) {
    vector<vector<int>> array(size);
    for(int i = 0; i < size; i++) {
      vector<int> temp(size);
      for(int j = 0; j < size; j++) {
        temp[j] = i*size + j;
      }
      array[i] = temp;
    }
    return array;
}

int main() {
     vector<vector<int>> array = test_array(5);
     cout << "Printing array before rotation" << endl;
     printArray(array);
     rotate_by_90_degree_anticlockwise(array);
     cout << "Printing array after rotation" << endl;
     printArray(array);
     return 0;
}
