#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		vector<int> res;
		int l = 0;
		int s = 1;
		if (m > n) {
			int t = n;
			n = m;
			m = t;
			l = 1; s = 0;
		}
		int n_cpy = n;
		int m_cpy = m;
		if (n-m == 0) {
			for (int i =0; i < m; ++i) {
				res.push_back(1);
				res.push_back(0);
			}
		} else {
			for (int i = 0; i < k; ++i) {
				res.push_back(l);
			}
			n -= k;
			while (m >= k) {
				for (int i = 0; i < k; ++i) {
					res.push_back(s);
				}
				for (int i =0; i < k; ++i) {
					res.push_back(l);
				}
				n -= k; 
				m -= k;
			}
			for (int i = 0; i < m; ++i) {
				res.push_back(s);
			}
			for (int i = 0; i < n; ++i) {
				res.push_back(l);
			}
		}
		if (k < n_cpy-m_cpy || (k > m_cpy && k > n_cpy)) {
			cout << -1 << "\n";
		} else {
			for (auto i : res) cout << i;
			cout << "\n";
		}
	}
}


