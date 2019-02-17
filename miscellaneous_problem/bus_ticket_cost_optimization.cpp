// File: bus_ticket_cost_optimization.cpp
// Created on: 17th Feb 2019
// Updated on: 17th Feb 2019
// Author: Pawan Kumar Singh [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.
//
// Input: {1,7,8,9,10,15,16,17,18,21,25}
// Output: 18
// Input: {1,3,4,5,11,12,23,24,30}
// Output: 17
// Desciption: There're 3 kinds of bus ticket. 1: ticket 1 cost 2 and can be used for a day.
// 2: ticket 2 cost 7 and can be used for a consecutive 7 days. 3: ticket 3 cost 25 can be
// used for a month. Assume month here means 30 consecutive days.
#include <iostream>
#include <vector>

using namespace std;

class bus_ticket_cost_optimization {
private:
   int get_prev_date_index(int ith_date, int jth_validity);
public:
   vector<int> travel_dates;
   vector<pair<int, int>> ticket_cost_pair;

   bus_ticket_cost_optimization(vector<int> travel_dates, vector<pair<int, int>> ticket_cost_pair);
   int min_cost();
};

bus_ticket_cost_optimization :: bus_ticket_cost_optimization(vector<int> travel_dates, vector<pair<int, int>> ticket_cost_pair) {
  this->travel_dates = travel_dates;
  this->ticket_cost_pair = ticket_cost_pair;
}

int bus_ticket_cost_optimization :: get_prev_date_index(int ith_date, int jth_validity) {
    int prev_date_index = travel_dates[ith_date] - ticket_cost_pair[jth_validity].first;
    if (prev_date_index < 1){
        return -1;
    }
    for (int k = ith_date-1; k >= 0; k--) {
        if (travel_dates[k] <= prev_date_index){
            return k;
        }
    }
    return -1;
}

int bus_ticket_cost_optimization :: min_cost() {

  int dp[travel_dates.size()][ticket_cost_pair.size()];

  for (int i = 0; i < travel_dates.size(); i++) {
      for (int j = 0; j < ticket_cost_pair.size(); j++) {

          int prev_date_index = get_prev_date_index(i, j);
          int prev_cost = prev_date_index >= 0 ? dp[prev_date_index][ticket_cost_pair.size()-1] : 0;
          int curr_cost = prev_cost + ticket_cost_pair[j].second;
          if ( j-1 >= 0 ) {
              curr_cost = min(curr_cost, dp[i][j-1]);
          }
          dp[i][j] = curr_cost;
      }
  }
  return dp[travel_dates.size()-1][ticket_cost_pair.size()-1];
}

int main() {
  vector<int> travel_dates = {1,7,8,9,10,15,16,17,18,21,25};
  vector<pair<int, int>> ticket_cost_pair = {{1, 2}, {7, 7}, {30, 25}};
  bus_ticket_cost_optimization btco(travel_dates, ticket_cost_pair);
  cout << btco.min_cost() << endl;
  btco.travel_dates = {1,3,4,5,11,12,23,24,30};
  cout << btco.min_cost() << endl;
}
