// File: two_missing_numbers.cpp
// Created on: 2nd Feb 2019
// Updated on: 3rd Feb 2019
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

// find two missing numbers from numbers starting from 1 and having maximum number as n.
// Input:: 7, 3, 4, 5, 9, 11, 6, 1, 10, 2, 13 output:: 12, 8

#include <iostream>
#include <vector>

using namespace std;

void two_missing_numbers_xor(vector<int> arr, vector<int> &missing_numbers) {
    int n = arr.size()+2;
    int xor_number = arr[0];

    for(vector<int>:: iterator itr = arr.begin()+1 ; itr != arr.end(); itr++) {
       xor_number ^= *itr;
    }

    for(int i = 1; i <= n; i++) {
       xor_number ^= i;
    }

    int set_bit_number = xor_number & ~(xor_number - 1);
    int first_number = 0, second_number = 0;
    for(int temp: arr) {
       if (temp & set_bit_number)
           first_number ^= temp;
       else
           second_number ^= temp;
    }
    for(int i = 1; i <= n; i++) {
       if( i & set_bit_number )
          first_number ^= i;
       else
          second_number ^= i;
    }

    if (first_number < second_number) {
       missing_numbers[0] = first_number;
       missing_numbers[1] = second_number;
    } else {
       missing_numbers[0] = second_number;
       missing_numbers[1] = first_number;
    }
}

void two_missing_numbers(vector<int> arr, vector<int> &missing_numbers) {
     int n = arr.size() + 2;
     int sum_n = (n * ( n + 1 ) ) / 2;
     int sum_arr_items = 0;
     for (int temp : arr) {
        sum_arr_items += temp;
     }
     int avg = (sum_n - sum_arr_items)/2;
     int first_number = 0, second_number = 0;
     for (int temp : arr) {
         if (temp <= avg)
            first_number += temp;
         else
            second_number += temp;
     }
     first_number = avg * ( avg + 1 ) / 2 - first_number;
     second_number = sum_n - second_number - avg * ( avg + 1 ) / 2;
     missing_numbers[0] = first_number;
     missing_numbers[1] = second_number;
}

void print_arr(vector<int> arr) {
   if (arr.empty()) {
      cout << "No item found";
      return;
    }

    for( int temp: arr )
        cout << temp << " ";
    cout << endl;
}

int main() {
    vector<int> test_arr({7, 3, 4, 5, 9, 11, 6, 1, 10, 2, 13});
    cout << "Input :: ";
    print_arr(test_arr);
    vector<int> missing_numbers({-1, -1});

    cout << "Output :: Using sum of n natural numbers technique" << endl;
    two_missing_numbers(test_arr, missing_numbers);
    print_arr(missing_numbers);

    cout << "Output :: Using xor of numbers technique" << endl;
    two_missing_numbers_xor(test_arr, missing_numbers);
    print_arr(missing_numbers);

}
