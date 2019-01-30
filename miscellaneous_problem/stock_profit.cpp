// File: stock_profit.cpp
// Created on: 30th Jan 2019
// Updated on: 30th Jan 2019
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
// The cost of a stock on each day is given in an array, find the max profit
// that you can make by buying and selling in those days. For example, if the
// given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can
// earned by buying on day 0, selling on day 3. Again buy on day 4 and sell on
// day 6. If the given array of prices is sorted in decreasing order, then
// profit cannot be earned at all.
// input = {100, 180, 260, 310, 40, 535, 695}
// output = 1205

#include <iostream>
#include <vector>

using namespace std;

long stock_profit(vector<int> prices) {
    long profit = 0;
    long max_so_far = 0;
    long next_day_price = prices.back();
    for(vector<int>::iterator itr = prices.end()-1; itr >= prices.begin(); --itr) {
      if ( *itr >= max_so_far || *itr > next_day_price) {
         max_so_far = *itr;
      }
      next_day_price = *itr;
      profit += max_so_far - *itr;
    }
    return profit;
}

int main() {
   cout << stock_profit(vector<int>({1,2,3,4,5})) << endl;
   cout << stock_profit(vector<int>({100, 180, 260, 310, 40, 535, 695})) << endl;
}
