#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		vector<int> a(n);
		map<int, int> b;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int val;
		for (int i = 0; i < m; ++i) {
			cin >> val;
			if (b.find(val) == b.end()) {
				b[val] = 1;
			} else {
				b[val] += 1;
			}
		}
		int matching = 0;
		map<int, int> c;
		for (int i = 0; i < m; ++i) {
			if (c.find(a[i]) == c.end()) {
				c[a[i]] = 1;
			} else {
				c[a[i]] += 1;
			}
			if (b.find(a[i]) != b.end() && b[a[i]] >= c[a[i]]) matching += 1;
		}
		int res = 0;
		if (matching >= k) res += 1;
		for (int i = m; i < n; ++i) {
			c[a[i-m]] -= 1;
			if (b.find(a[i-m]) != b.end() && b[a[i-m]] > c[a[i-m]]) {
				matching -= 1;
				//cout << "here " << i << " " << c[a[m-i]] << "\n"
			}
			if (c.find(a[i]) == c.end()) {
				c[a[i]] = 1;
			} else {
				c[a[i]] += 1;
			}
			if (b.find(a[i]) != b.end() && b[a[i]] >= c[a[i]]) {
				//cout << "here " << i << "\n";
				matching += 1;
			}
			if (matching >= k) {
				res += 1;
			}
		}
		cout << res << "\n";
	}
}

