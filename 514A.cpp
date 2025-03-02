#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long x, res, f;
  int xi;
  cin >> x;
  f = 1;
  res = 0;
  while (x) {
    xi = x % 10;
    if (xi >= 5) {
      xi = 9 - xi;
    }
    res += xi * f;
    f *= 10;
    x /= 10;
    if (xi == 0 && x == 0) {
      res += 9 * (f / 10);
    }
  }
  cout << res;
}