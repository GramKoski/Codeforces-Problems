#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, m, a;
  cin >> n >> m >> a;
  long long res = ((m + a - 1) / a) * ((n + a - 1) / a);
  cout << res << "\n";
}