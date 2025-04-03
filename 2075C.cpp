#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, m; cin >> n >> m;
		vector<ll> a(m);
		for (auto & e : a) cin >> e;
		sort(a.begin(), a.end());
		ll l = 0; ll r = m-1;
		ll g = a[m-1]; ll res = 0;
		for (ll i = max((ll)1, n-g); i <= n/2; ++i) {
			while (l < m-1 && a[l] < i) l += 1;
			while (r > 0 && a[r] >= n-i) r -= 1; 
			if (a[r] < n-i) r += 1;
			if (2*i != n) res += (m-l)*(m-r) - (m-r);
			//cout << i << " " << n-i << " " << l << " " << r << " " << res << "\n";
		}
		res *= 2;
		if (n % 2 == 0 && g >= n/2) {
			res += (m-l)*(m-l-1);
		}
		cout << res << "\n";
	}
}


