#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, x, y; cin >> x >> y >> a;
		int e = (a) % (x+y);
		if (e < x) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}

