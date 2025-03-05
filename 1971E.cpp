#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k, q; cin >> n >> k >> q;
		vector<ll> a(k+1);
		vector<ll> b(k+1);
		a[0] = 0; b[0] = 0;
		for (int i = 1; i <= k; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= k; ++i) {
			cin >> b[i];
		}
		ll d;
		while (q--) {
			cin >> d;
			ll r = k+1;
			ll l = 0;
			ll m;
			while (l < r-1) {
				m = (l+r)/2;
				if (a[m] <= d) {
					l = m;
				} else {
					r = m;
				}
			}
			if (d == n) {
				cout << b[l];
			} else {
				cout << b[l] + ((d-a[l])*(b[l+1]-b[l]))/(a[l+1]-a[l]);

			}
			cout << " ";
		}
		cout << "\n";
	}
}
