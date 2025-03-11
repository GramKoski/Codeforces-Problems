#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll k, x, a; cin >> k >> x >> a;
		ll b = (a+k-1)/k;
		ll res = b;
		for (int i = x; i >= 1; --i) {
			b = (a-b+k-1)/k;
			res += b;
		}
		cout << res << "\n";
		if (res <= a) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}
