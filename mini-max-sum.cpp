#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<long> _find_set(vector<int> &arr, int limit, int idx = 0, int count = 0, long sum_cache = 0) {
  if (count >= limit) {
    return vector<long>(1, sum_cache);
  }
  if (idx >= arr.size())
    return vector<long>();

  vector<long> res;
  for (int i = idx; i < arr.size(); i++) {
    vector<long> v;
    if (count == 0)
      v = _find_set(arr, limit, i + 1, count + 1, arr[i]);
    else v = _find_set(arr, limit, i + 1, count + 1, sum_cache + arr[i]);

    res.insert(res.end(), v.begin(), v.end());
  }

  return res;
}

int main() {
  vector<int> arr;

  for (int i = 0; i < 5; i++) {
    int x; cin >> x;
    arr.push_back(x);
  }
  vector<long> res = _find_set(arr, 4);
  cout << *min_element(res.begin(), res.end()) << " " << *max_element(res.begin(), res.end()) << '\n';

  return 0;
}