#include <iostream>
#include <vector>

using namespace std;

int main() {
  int x;
  cin >> x;
  if (x > 2 && x % 2 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}