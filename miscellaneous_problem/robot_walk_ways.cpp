// File: robot_walk_ways.cpp
// Created on: 27th Dec 2018
// Updated on: 27th Dec 2018
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.
//
// There is a matrix of size mxn. Every cell is having a value either 0 or 1.
// Robot starts walking from cell (0,0) and want to go to cell (m-1, n-1).
// Robot can walk only one cell to right or down. Find number of ways robot
// can reach to its destination. Robot is not allowed to go to cell having value 0.

#include <iostream>
#define ROWS 5
#define COLS 4

using namespace std;

int ways_util(int arr[ROWS][COLS], int ways_arr[ROWS][COLS], int x, int y) {
    if (x < 0 || y < 0 || arr[x][y] == 0) return 0;
    if (x == 0 && y == 0) return 1;
    if (ways_arr[x][y] != -1) return ways_arr[x][y];
    int way_count = ways_util(arr, ways_arr, x-1, y) + ways_util(arr, ways_arr, x, y-1);
    ways_arr[x][y] = way_count;
    return way_count;
}

int ways(int arr[ROWS][COLS]) {

  int ways_arr[ROWS][COLS];
  for(int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
       ways_arr[i][j] = -1;
  return ways_util(arr, ways_arr, ROWS-1, COLS-1);
}

int main() {
    int arr[ROWS][COLS] = {{1, 0, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    cout << ways(arr) << endl;
}
