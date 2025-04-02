#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll x, y; cin >> x >> y;
		ll g = x;
		if (y > x) {
			g = y;
		}
		ll val = 1;
		while (g > 0) {
			val *= 2;
			val += 1;
			g /= 2;
		}
		ll x_cpy = x; ll y_cpy = y; ll v = 1;
		while (x != y && !(x_cpy % 2 == 0 ^ y_cpy % 2 == 0)) {
			val -= v;
			v *= 2;
			x_cpy /= 2;
			y_cpy /= 2;
		}

		if (x == y) {
			cout << -1 << "\n";
		} else {
			//cout << "v = " << val << "\n";
			cout << (val - x - y)/2 << "\n";
		}
	}
}

