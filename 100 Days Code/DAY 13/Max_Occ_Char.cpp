//! Maximum Occurring Character in a String

// Question Link:
// https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Strings&sortBy=submissions

#include <iostream>
#include <string>
#include <vector>
using namespace std;
char getMaxOccuringChar(string str) {
  // ASCII characters (total 256 characters)
  int CHAR_COUNT = 256;

  // Array to store the count of each character
  vector<int> count(CHAR_COUNT, 0);

  int n = str.size();

  for (int i = 0; i < n; i++) {
    count[str[i]]++;
  }

  char maxChar = '\0';
  int maxCount = 0;

  // character with the maximum count
  for (int i = 0; i < CHAR_COUNT; i++) {
    if (count[i] > maxCount) {
      maxCount = count[i];
      maxChar = i;
    }
  }

  return maxChar;
}

int main() {
  string str;
  cin >> str;
  cout << getMaxOccuringChar(str);
  return 0;
}
/*
int maxCount=0;
        char result='\0';
        for(int i=0;i<str.length();i++){
            int count=1;
            for(int j=i+1;j<str.length();j++){
                if(str[i]==str[j]){
                    count++;
                }
            }
            if (count > maxCount || (count == maxCount && str[i] < result)) {
                maxCount = count;
                result = str[i];
            }
        }
        return result;
*/