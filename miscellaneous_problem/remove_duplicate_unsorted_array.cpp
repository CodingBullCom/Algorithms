// File: remove_duplicate_unsorted_array.cpp
// Created on: 6th Jan 2019
// Updated on: 6th Jan 2019
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.
//
// Input: 1, 2, 5, 1, 7, 2, 4, 2
// Output: 1, 2, 5, 7, 4
// Desciption: Remove duplicate integers from an unsorted array containing integer values

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> remove_duplicate_map(vector<int> arr) {
    vector<int> return_values;
    unordered_map<int, int> map;
    for (int temp : arr) {
      if (map.find(temp) == map.end()) {
          //Not found in map
          return_values.push_back(temp);
          map[temp] = temp;
      }
    }
    return return_values;
}

vector<int> remove_duplicate_set(vector<int> arr) {
    vector<int> return_values;
    unordered_set<int> set;
    for (int temp : arr) {
      if (set.find(temp) == set.end()) {
          //Not found in map
          return_values.push_back(temp);
          set.insert(temp);
      }
    }
    return return_values;
}

void print_array(vector<int> arr) {

    for (int temp: arr) {
        cout << temp << " ";
    }
    cout << endl;
}

int main() {
     vector<int> value {1, 2, 5, 1, 7, 2, 4, 2};
     cout << "Remove dumplicate using unordered set" << endl;
     cout << "Original array:: ";
     print_array(value);
     vector unique_values = remove_duplicate_map(value);
     cout << "Duplicate removed:: ";
     print_array(unique_values);
     cout << "Remove dumplicate using unordered set" << endl;
     cout << "Original array:: ";
     print_array(value);
     unique_values = remove_duplicate_set(value);
     cout << "Duplicate removed:: ";
     print_array(unique_values);
}
