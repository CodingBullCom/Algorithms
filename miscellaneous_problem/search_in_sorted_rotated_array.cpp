// File: search_in_sorted_rotated_array.cpp
// Created on: 16th Feb 2019
// Updated on: 16th Feb 2019
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.
//
// Input: arr = {7, 8, 9, 12, 3, 5, 6}, key = 3
// Output: 4
// Input: arr = {7, 8, 9, 12, 3, 5, 6}, key = 4
// Output: -1
// Desciption: a sorted array is rotated unknown number of time.
// We have to search for a given item in array.

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> arr, int key, int low, int high) {
   if (low > high) { return -1; }
   int mid = ( high + low ) / 2;
   if ( arr[mid] == key)
      return mid;
    //first half is sorted
   if(arr[low] < arr[mid]) {
       if (key >= arr[low] && key <= mid)
          return search(arr, key, low, mid-1);
       else
          return search(arr, key, mid+1, high);
   }

   //since left half is not sorted, so right part must be sorted
   if ( key >= arr[mid] && key <= arr[high] ) {
       return search(arr, key, mid+1, high);
   }
   //left half is not sorted, key is not present in right half
   //so key is in unsorted left half
   return search(arr, key, low, mid-1);
}

int main() {
   vector<int> temp({7, 8, 9, 12, 3, 5, 6});
   cout << search(temp, 3, 0, temp.size()) << endl;
   cout << search(temp, 4, 0, temp.size()) << endl;
}
