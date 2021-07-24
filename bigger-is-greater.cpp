#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool next_permutation(string &x) {
  if (x.length() <= 1) return false;

  auto i = x.end() - 1, j = x.begin();
  while (i != x.begin() && *(i - 1) >= *i) i--;
  
  if (i == x.begin()) return false; // max permutation
  
  j = i; i--;
  while (j != x.end() - 1 && *j > *i) {
    if (*(j + 1) <= *i) break;
    j++;
  }

  std::swap(*i, *j); // implicit swap = string::swap

  reverse(++i, x.end());

  return true;
}

int main() {
  int n; cin >> n;

  vector<string> res; cin >> ws;
  for (int i = 0; i < n; i++) {
    string x; getline(cin, x);
    // cin.ignore();

    if (next_permutation(x)) res.push_back(x);
    else res.push_back("no answer");
  }

  for (auto x : res) {
    cout << x << '\n';
  }

  return 0;
}