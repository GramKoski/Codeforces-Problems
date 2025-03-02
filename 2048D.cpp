#include <iostream>
#include <vector>
#include <algorithm>

#define llu long long unsigned

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, kevin, maxa; cin >> n >> m;
		maxa = 0;
		vector<int> a(n);
		vector<int> b(m);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i) {
			cin >> b[i];
		}
		kevin = a[0];
		sort(a.begin(), a.end()); 
		maxa = a[n-1];
		vector<int> q(m, 1);
		for (int i = 0; i < m; ++i) {
			//binary search
			if (b[i] > maxa || b[i] <= kevin) {
				continue;
			}
			int l, r, mid;
			l = -1; r = n;
			while (l != r-1) {
				mid = (l+r)/2;
				//cout << "i = " << i << " mid = " << mid << "\n";
				if (a[mid] >= b[i]) {
					r = mid;
				} else {
					l = mid;
				}
			}
			q[i] = n-r + 1;
		}
		sort(q.begin(), q.end());
		/*
		for (auto i : q) { cout << i << " "; } 
		cout << "\n";
		*/
		//perform queries
		for (int k = 1; k <= m; ++k) {
			llu res = 0;
			for (int i = k-1; i < m; i+=k) {
				res += q[i];
			}
			cout << res << " ";
		}
		cout << "\n";
	}
}
