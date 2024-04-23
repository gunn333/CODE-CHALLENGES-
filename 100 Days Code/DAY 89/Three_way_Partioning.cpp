//! Three Way Partitioning (GeeksForGeeks)

#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int> &array, int a, int b) {
  int n = array.size();
  vector<int> result;
  for (int i = 0; i < result.size(); i++) {
    if (array[i] < a) {
      result.push_back(array[i]);
    }
  }
  for (int i = 0; i < result.size(); i++) {
    if (array[i] >= a && array[i] <= b) {
      result.push_back(array[i]);
    }
  }
  for (int i = 0; i < result.size(); i++) {
    if (array[i] > b) {
      result.push_back(array[i]);
    }
  }
  array = result;
}

int main() {
  vector<int> array = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
  int a = 10, b = 20;
  threeWayPartition(array, a, b);
  for (int i = 0; i < array.size(); i++) {
    cout << array[i] << " ";
  }
  return 0;
}