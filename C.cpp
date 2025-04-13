#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, t; cin >> n >> t;
	vector<int> a(t);
	for (int i = 0; i < t; ++i) {
		cin >> a[i];
		a[i] -= 1;
	}
	vector<vector<bool>> valid(n, vector<bool>(n, false));
	vector<vector<int>> r(n);
	vector<vector<int>> c(n);
	vector<int> d1;
	vector<int> d2;

	for (int i = 0; i < t; ++i) {
		valid[a[i]/n][a[i]%n] = true;
		r[a[i]/n].push_back(i);
		c[a[i]%n].push_back(i);
		if (a[i]/n == a[i]%n) d1.push_back(i);
		if (a[i]/n + a[i]%n == n-1) d2.push_back(i);
	}
	int res = 1e9;
	for (int i = 0; i < n; ++i) {
		int curr = 0;
		for (int j = 0; j < n; ++j) {
			if (valid[i][j]) curr += 1;
		}
		if (curr >= n) {
			res = min(res, r[i].back());
		}
	}
	for (int i = 0; i < n; ++i) {
		int curr = 0;
		for (int j = 0; j < n; ++j) {
			if (valid[j][i]) curr += 1;
		}
		if (curr >= n) {
			res = min(res,c[i].back());
		}
	}
	int curr = 0;
	for (int i = 0; i < n; ++i) {
		if (valid[i][i]) curr += 1;
	}
	if (curr >= n) res = min(res, d1.back());
	curr = 0;
	for (int j = n-1; j >= 0; --j) {
		if (valid[n-1-j][j]) curr += 1;
	}
	if (curr >= n) res = min(res, d2.back());
	cout << ((res != 1e9) ? res+1 : -1) << "\n";
}

