#include <iostream>

#define ll long long 

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, b, c; cin >> n >> b >> c;
		ll res;
		if (b == 0) {
			if (c < n-2) {
				res = -1;
			} else {
				res = (c==n-1 || c == n-2) ? n-1 : n;
			}
		} else if (c >= n) {
			res = n;
		} else {
			res = n - ((n-1-c)/b+1);
		}
		cout << res << "\n";
	}
}

