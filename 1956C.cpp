#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		ll res = 0;
		string p = "";
		for (ll i = 1; i <= n; ++i) {
			res += i*(2*i-1);
			p += " " + to_string(i);
		}
		cout << res << " " << 2*n << "\n";
		for (int i = n; i >= 1; --i) {
			cout << 1 << " " << i << p << "\n";
			cout << 2 << " " << i << p << "\n";
		}
	}
}
		
