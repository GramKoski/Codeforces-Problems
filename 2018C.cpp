#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define llu long long unsigned
#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		ll sum = 0;
		vector<ll> a(n);
		ll max_card = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
			max_card = max(max_card, a[i]);
		}
		ll res = 1;
		ll groups;
		for (int d = 1; d <= n; ++d) {
			groups = (sum + d-1)/d;
			if (groups >= max_card) {
				if (groups*d-sum <= k) {
					res = d;
				}
			} else {
				if (d*(max_card-groups)+(groups*d-sum) <= k) {
					res = d;
				}
			}
		}
		cout << res << "\n";
	}
}
