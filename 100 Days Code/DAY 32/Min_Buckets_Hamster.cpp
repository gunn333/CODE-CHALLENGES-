// ! Minimum Number of Food Buckets to Feed the Hamster (leetcode 2086)

// Question Link :
// https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamster/

#include <bits/stdc++.h>
using namespace std;

int minimumBuckets(string hamsters) {
  int n = hamsters.size();
  //   Vector to store the feed status of each hamster
  vector<bool> feed(n, false);
  // Count of the number of buckets
  int num_buckets = 0;

  for (int i = 0; i < n; i++) {
    // Agar its a hamster
    if (hamsters[i] == 'H') {
      // if left of hamster is feeded (i.e. true) then skip and it will not
      // check for i = 0 because it will be out of bound
      if (i > 0 && feed[i - 1]) {
        continue;
      }
      //   If right of hamster is empty (i.e. '.') then feed it and increase the
      //   number of buckets and we will not check for i = n-1 because it will
      //   be out of bound
      else if (i < n - 1 && hamsters[i + 1] == '.') {
        feed[i + 1] = true;
        num_buckets++;
      }
      //   if left of hamster is empty (i.e. '.') then feed it and increase the
      //   number of buckets and we will not check for i = 0 because it will be
      //   out of bound
      else if (i > 0 && hamsters[i - 1] == '.') {
        feed[i - 1] = true;
        num_buckets++;
      }
      //   if hamster has hamster on both sides then return -1 as it can't be
      //   feeded
      else {
        return -1;
      }
    }
  }
  return num_buckets;
}

int main() {
  string hamsters;
  cin >> hamsters;
  cout << minimumBuckets(hamsters) << endl;
  return 0;
}