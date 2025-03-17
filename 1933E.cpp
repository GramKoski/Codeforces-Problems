#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		//Find the greatest r st presum is max <= k. Also check r + 1 to see if it's better
		// Anything larger than r + 1 definetely won't be better
		
		int n; cin >> n;
		vector<int> a(n);
		vector<int> presum(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		presum[0] = a[0];
		for (int i = 1; i < n; ++i) presum[i] += presum[i-1];
		int q; cin >> q; vector<int> res;
		int l, u;
		while (q--) {
			cin >> l >> u;
			//Binary search
			int m;
			int li = l-1-1; int ri = n-1;
			while (li < ri -1) {
				m = (li+ri) / 2;
				if (presum[m]- ((l > 1) ? presum[l-1] : 0) >= u) {
					ri = m;
				} else {
					li = m;
				}
			}
			int sum = presum[m]-((l > 1) ? presum[l-1] : 0);
			cout << "ri, sum " << ri << " " << sum << "\n";
			if (ri > 0 && sum > u + 1) {
				int sum_left = presum[ri-1] - ((l-1 > 0) ? presum[l-1] : 0);
				if (u*(u-1)/2 - (sum - u -1)*(sum - u - 2)/2 > sum_left) {
					res.push_back(ri+1);
				} else {
					res.push_back(ri);
				}
			} else {
				res.push_back(ri+1);
			}
		}
		for (auto r : res) cout << r << " ";
		cout << "\n";
	}
}

