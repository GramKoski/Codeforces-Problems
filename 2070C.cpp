#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int solve(string &p, vector<int> &a, int x) {
	int res = 0;
	char prev = 'R';
	for (int i =0; i < a.size(); ++i) {
		if (a[i] > x) {
			if (p[i] == 'B' && prev == 'R') {
				res += 1;
			}
			prev = p[i];
		}
	}
	//cout << x << " " << res << "\n";
	return res;
}


int main() {
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n; cin >> k;
		string p; cin >> p;
		vector<int> a(n); int m = 0;
		for (int i =0; i < n; ++i) {
			cin >> a[i];
			m = max(m, a[i]);
		}
		int l = -1;
		int r = m+1; int mid; int res;
		while (l < r-1) {
			mid = (l+r)/2;
			res = solve(p, a, mid);
			if (res > k) {
				l = mid;
			} else {
				r = mid;
			}
		}
		cout << r << "\n";
	}
}




