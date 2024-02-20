//! Text Justification (Leetcode 68)

// Question Link:
// https://leetcode.com/problems/text-justification/

#include <bits/stdc++.h>
using namespace std;

string findLine(vector<string> &words, int maxWidth, int i, int j,
                int eachSpaceSlotLength, int extraSpaceSlotLength) {
  string line;
  for (int k = i; k < j; k++) {
    line += words[k];
    if (k == j - 1) {
      break;
    }
    for (int l = 1; l <= eachSpaceSlotLength; l++) {
      line += " ";
    }
    if (extraSpaceSlotLength > 0) {
      line += " ";
      extraSpaceSlotLength--;
    }
  }
  while (line.length() < maxWidth) {
    line += " ";
  }
  return line;
}

vector<string> fullJustify(vector<string> &words, int maxWidth) {
  int n = words.size();
  vector<string> result;
  int i = 0;
  while (i < n) {
    int lettersCount = words[i].size();
    int spaceSlot = 0;
    int j = i + 1;
    while (j < n &&
           words[j].size() + 1 + lettersCount + spaceSlot <= maxWidth) {
      lettersCount += words[j].size();
      spaceSlot++;
      j++;
    }
    int remainingSpace = maxWidth - lettersCount;
    int eachSpaceSlotLength = spaceSlot == 0 ? 0 : remainingSpace / spaceSlot;
    int extraSpaceSlotLength = spaceSlot == 0 ? 0 : remainingSpace % spaceSlot;
    if (j == n) {
      eachSpaceSlotLength = 1;
      extraSpaceSlotLength = 0;
    }
    string line = findLine(words, maxWidth, i, j, eachSpaceSlotLength,
                           extraSpaceSlotLength);
    i = j;
    result.push_back(line);
  }
  return result;
}

int main() {
  vector<string> words = {"This",          "is", "an", "example", "of", "text",
                          "justification."};
  int maxWidth = 16;
  vector<string> result = fullJustify(words, maxWidth);
  for (auto line : result) {
    cout << line << endl;
  }
  return 0;
}