#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int>v;

  map<int, int> m;
  for (int i = 1; i <= 5; i++)
    m[i] = 0;

  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    m[x]++;  
  }

  int res = 1;
  for (int i = 2; i <= 5; i++) {
    if (m[i] > m[res]) res = i;
    else if (m[i] == m[res]) {
      if (i < res) res = i;
    }
  }
  cout << res << '\n';

  return 0;
}