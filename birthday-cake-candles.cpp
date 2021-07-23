#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  vector<int> arr;

  int n; cin >> n;
  int max, count = 1;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    arr.push_back(x);

    if (arr.size() == 1) {
      max = x;
    } else {
      if (x > max) {
        max = x;
        count = 1;
      } else if (x == max) {
        count++;
      }
    }
  }
  cout << count << '\n'; 
  return 0;
}