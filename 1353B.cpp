#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, k, x, n, p, sum, g;
  vector<int> a;
  vector<int> b;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    a.clear();
    b.clear();
    cin >> n >> k;

    for (int j = 0; j < n; ++j) {
      cin >> x;
      a.push_back(x);
    }
    for (int j = 0; j < n; ++j) {
      cin >> x;
      b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    sum = 0;
    p = 0;
    g = 0;
    while (p < n) {
      if (b[p] > a[p] && g < k) {
        sum += b[p];
        g += 1;
      } else {
        sum += a[p];
      }
      p += 1;
    }
    cout << sum << "\n";
  }
}