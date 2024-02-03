//! Watering Plants Problem geekforgeeks

#include <bits/stdc++.h>
using namespace std;
int wateringPlants(vector<int> &plants, int capacity) {
  int steps = 0;
  int container = capacity;
  int i = 0;
  while (i < plants.size()) {
    if (plants[i] <= container) {
      // Container se water nikal diya aur plants ko de dia
      container = container - plants[i];
    } else {
      // Container fulfill krne ke liye capacity ke paas le ge
      container = capacity;
      container = container - plants[i];
      // Container ke paas jana aur vapis fir element ke paas ana
      steps += (i * 2);
    }
    i++; // Next plant
    steps++;
  }
  return steps;
}
int main() {
  vector<int> plants;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    plants.push_back(x);
  }
  int capacity;
  cin >> capacity;
  cout << wateringPlants(plants, capacity);
  return 0;
}