#include <iostream>
#include <vector>

#define llu long long unsigned

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		llu b, c, d; cin >> b >> c >> d;
		if ((b & ~c & ~d) > 0 || (~b & c & d) > 0) {
			cout << -1 << "\n";
			continue;
		}
		cout << ((b & c & ~d) | (~b & ~c & d)) << "\n";
	}
}

