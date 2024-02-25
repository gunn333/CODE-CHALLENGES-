//! Insert Delete GetRandom O(1) (LeetCode 380)

// Question Link:
// https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class RandomizedSet {
public:
  unordered_set<int> s;
  vector<int> v;
  RandomizedSet() {}

  bool insert(int val) {
    if (s.find(val) == s.end()) {
      v.push_back(val);
      s.insert(val);
      return true;
    }
    return false;
  }

  bool remove(int val) {
    if (s.find(val) != s.end()) {
      v.erase(find(v.begin(), v.end(), val));
      s.erase(val);
      return true;
    }
    return false;
  }

  int getRandom() { return v[rand() % v.size()]; }
};

int main() {
  RandomizedSet *obj = new RandomizedSet();
  obj->insert(1);
  obj->remove(2);
  obj->insert(2);
  obj->getRandom();
  obj->remove(1);
  obj->insert(2);
  obj->getRandom();
  return 0;
}
