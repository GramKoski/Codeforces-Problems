#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll r; cin >> r;
		ll x = 0;
		ll y = r;
		ll res = 0;
		for ( ; x <= r; ++x) {
			if (y <= 0) break;
			if (x*x+y*y >= r*r && x*x+y*y < (r+1)*(r+1)) {
				res += 1;
			}
			while ((y-1)*(y-1) + x*x >= r*r && y > 0) {
				y -= 1;
				res += 1;
			}
		}
		cout << res * 4-4 << "\n";
	}
}

