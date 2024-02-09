//! Gas Station(Leetcode 134)

// Question Link:
// https://leetcode.com/problems/gas-station/

#include <iostream>
#include <vector>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  int n = gas.size();
  int curr_delta = 0;
  int starting_point = 0;
  int total_delta = 0;
  for (int i = 0; i < n; i++) {
    int delta = gas[i] - cost[i];
    curr_delta = curr_delta + delta;
    total_delta = total_delta + delta;
    if (curr_delta < 0) {
      starting_point = i + 1;
      curr_delta = 0;
    }
  }
  // If the total delta is negative, it means there is no valid starting
  // station
  if (total_delta < 0) {
    return -1;
  } else {
    return starting_point;
  }
}
int main() {
  cout << "Enter the number of elements in the gas array: ";
  int n;
  cin >> n;
  vector<int> gas(n);
  cout << "Enter the elements of the gas array: ";
  for (int i = 0; i < n; i++) {
    cin >> gas[i];
  }
  cout << "Enter the number of elements in the cost array: ";
  cin >> n;
  vector<int> cost(n);
  cout << "Enter the elements of the cost array: ";
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  cout << canCompleteCircuit(gas, cost);
  return 0;
}