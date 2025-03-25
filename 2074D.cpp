#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<ll> r(n);
		vector<ll> x(n);
		for (ll &j : x) cin >> j;
		for (ll &i : r) cin >> i;
		map<ll, ll> count;
		ll h;
		for (int i = 0; i < n; ++i) {
			for (ll xx = x[i]-r[i]; xx <= x[i]+r[i]; ++xx) {
				h = 2*(ll)sqrt(r[i]*r[i] - (xx-x[i])*(xx-x[i]));
				h += 1;
				if (count.find(xx) == count.end()) {
					count[xx] = h;
				} else {
					//This works because there is only maximum of m x-axis point and the overlaps will be covered by the max() operation
					count[xx] = max(count[xx], h);
				}
			}
		}
		ll res = 0;
		for (auto a : count) res += a.second;
		cout << res << "\n";
	}
}

