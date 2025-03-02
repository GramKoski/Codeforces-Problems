#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  int n, l;
  double d;
  cin >> n >> l;
  // Note the array of static size declaration.
  int lamps[n];
  for (int i = 0; i < n; ++i) {
    cin >> lamps[i];
  }
  // Sorting an array. Different than sorting a vector.
  sort(lamps, lamps + n);
  double maxDist = 0;
  int prev = lamps[0];
  for (int i = 0; i < n; ++i) {
    d = (lamps[i] - prev) / 2.0;
    if (d > maxDist) {
      maxDist = d;
    }
    prev = lamps[i];
  }
  // Edge cases
  if (l - lamps[n - 1] > maxDist) {
    maxDist = l - lamps[n - 1];
  }
  if (lamps[0] > maxDist) {
    maxDist = lamps[0];
  }


  cout << setprecision(10) << maxDist;
}
