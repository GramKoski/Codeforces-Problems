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
		if (k < n_cpy-m_cpy || (k > max(n_cpy, m_cpy))) {
			cout << -1 << "\n";
		} else { 
			for (int i = 0; i < k; ++i) {
					res.push_back(l);
			}
			n -= k;
			for (int i = 0; i < n; ++i) {
				res.push_back(s);
				res.push_back(l);
				m -= 1;
			}
			for (int i = 0; i < m; ++i) {
				res.push_back(s);
			}
			for (auto i : res) cout << i;
			cout << "\n";
		}
	}
}


