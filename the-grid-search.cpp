#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string checkPattern(vector<string> &matrix, vector<string> &pattern) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (matrix[i][j] == pattern[0][0]) {
        bool checkFlag = true;
        for (int m = 0; m < pattern.size(); m++) {
          if (!checkFlag) break;
          for (int n = 0; n < pattern[m].size(); n++) {
            if (
                i + m >= matrix.size() || j + n >= matrix[i].size()) {
              checkFlag = checkFlag & false;
              break;
            }
            if (matrix[i + m][j + n] != pattern[m][n]) {
              checkFlag = checkFlag & false;
              break;
            }
          }
        }
        if (checkFlag)
          return "YES";
      }
    }
  }
  return "NO";
}

int main() {
  vector<string> result;

  int t;
  cin >> t;
  for (int z = 0; z < t; z++) {
    int G, C;
    cin >> G >> C;

    vector<string> matrix, pattern;
    for (int i = 0; i < G; i++) {
      string te;
      cin >> te;
      matrix.push_back(te);
    }

    int g, c;
    cin >> g >> c;
    for (int i = 0; i < g; i++) {
      string te;
      cin >> te;
      pattern.push_back(te);
    }

    result.push_back(checkPattern(matrix, pattern));
  }

  for (auto x : result)
    cout << x << '\n';

  return 0;
}