#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n, k, count = 0; cin >> n >> k;

  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    v.push_back(x);
  }

  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if ( (v[i] + v[j]) % k == 0) {
        count++;
      }
    }
  }
  cout << count << '\n';

  return 0;
}
