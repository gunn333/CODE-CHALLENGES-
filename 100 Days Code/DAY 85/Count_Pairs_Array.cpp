//! Count Pairs in an Array (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1

#include <bits/stdc++.h>
using namespace std;

int countPairs(int arr[], int n) {
  // Brute Force
  /*
int count_pairs = 0;
for (int i = 0; i < n; i++) {
  for (int j = i + 1; j < n; j++) {
    if (i * arr[i] > j * arr[j]) {
      count_pairs++;
    }
  }
}
return count_pairs;
*/
  // b -> i * arr[i]
  // s -> sorted b
  vector<int> b, s;
  // Traverse the array and store i * arr[i] in b
  for (int i = 0; i < n; i++) {
    b.push_back(i * arr[i]);
    // Store the values in s of b for sorting
    s.push_back(b[i]);
  }
  // Sort the s vector
  sort(s.begin(), s.end());
  int ans = 0;
  // Traverse the b vector
  for (int i = 0; i < n; i++) {
    // Find the index of the element in s
    // basically lower_bound is used to find the index of the element in the
    // sorted array s which is greater than or equal to the element in b
    // lower_bound(s.begin(), s.end(), b[i]) means find the index of the element
    // b[i] in the sorted array s from s.begin() to s.end() -s.begin() is done
    // to get the index of the element
    // Subtracting s.begin() from the index gives the index of the element in
    // the 0 based index
    int index = lower_bound(s.begin(), s.end(), b[i]) - s.begin();
    // Add the index to the answer
    ans += index;
    // This is done to remove the element from the sorted array s so that we can
    // get the next greater element in the next iteration
    // This will remove the possibility of counting the same element again
    s.erase(s.begin() + index);
  }
  return ans;
}

int main() {
  // Test Cases
  // Example 1
  int arr1[] = {3, 5, 6, 2};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << countPairs(arr1, n1) << endl;
  // Example 2
  int arr2[] = {10, 19, 18};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << countPairs(arr2, n2) << endl;
  return 0;
}