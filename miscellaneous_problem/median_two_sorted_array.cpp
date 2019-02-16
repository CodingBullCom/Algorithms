// File: median_two_sorted_array.cpp
// Created on: 14th Jan 2019
// Updated on: 16th Feb 2019
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.
//
// Input: arr1 = {90, 100} arr2 = {5, 8, 10, 20} Output: 15
// Output: arr1 = {90, 100} arr2 = {5, 8, 10} Output: 10
// Desciption: Median is the middle number in a sorted array. If size of array is even then
// median is average of both the middle numbers.

#include <iostream>
using namespace std;

int get_median_by_iterative_comparison(int ar1[], int ar2[], int m, int n)
{
  int i = 0; /* Current index of input array ar1[] */
  int j = 0; /* Current index of input array ar2[] */
  int count;
  int m1 = -1, m2 = -1;

  for (count = 0; count <= (m + n)/2; count++) {
    m2 = m1;
    if(i != m && j != n) {
      m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
    } else if(i < m){
      m1 = ar1[i++];
    } else {
      // for case when j<m,
      m1 = ar1[j++];
    }
  }
  if((m + n) % 2 == 1) {
    return m1;
  } else {
    return (m1 + m2)/2;
  }
}

int get_median_by_binary_partition(int arr1[], int arr2[], int m, int n) {
  if (m > n)
     return get_median_by_binary_partition(arr2, arr1, n , m);

  int low = 0, high = m;
  while ( low <= high ) {

    int partition_x = (low + high) / 2;
    int partition_y = (m + n + 1) / 2 - partition_x;
    int max_left_x = partition_x == 0 ? INT_MIN : arr1[partition_x - 1];
    int min_right_x = partition_x == m ? INT_MAX : arr1[partition_x];

    int max_left_y = partition_y == 0 ? INT_MIN : arr2[partition_y - 1];
    int min_right_y = partition_y == n ? INT_MAX : arr2[partition_y];

    if (max_left_x <= min_right_y && max_left_y <= min_right_x) {
      if (( m + n) % 2 == 0 ) {
        return (max(max_left_x, max_left_y) + min(min_right_x, min_right_y))/2;
      } else {
        return max(max_left_x, max_left_y);
      }
    } else if (max_left_x > min_right_y) {
      high = partition_x - 1;
    } else {
      low = partition_x + 1;
    }
  }
  return 0;
}

int main()
{
  int ar1[] = {90};
  int ar2[] = {5, 8, 10, 20};

  int n1 = sizeof(ar1)/sizeof(ar1[0]);
  int n2 = sizeof(ar2)/sizeof(ar2[0]);
  printf("%d", get_median_by_iterative_comparison(ar1, ar2, n1, n2));
  printf("\n%d", get_median_by_binary_partition(ar1, ar2, n1, n2));
  int arr1[] = {90, 100};
  int arr2[] = {5, 8, 10, 20};
  n1 = sizeof(arr1)/sizeof(arr1[0]);
  n2 = sizeof(arr2)/sizeof(arr2[0]);
  printf("\n%d", get_median_by_iterative_comparison(arr1, arr2, n1, n2));
  printf("\n%d", get_median_by_binary_partition(arr1, arr2, n1, n2));
  cout << endl;
  return 0;
}
