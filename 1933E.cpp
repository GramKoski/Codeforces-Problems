#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		//Find the greatest r st a is max <= k. Also check r + 1 to see if it's better
		// Anything larger than r + 1 definetely won't be better
		
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i < n; ++i) a[i] += a[i-1];
		int q; cin >> q; vector<int> res;
		int l, u;
		while (q--) {
			cin >> l >> u;
			//Binary search
			int m;
			int li = l-1-1; int ri = n-1;
			while (li < ri -1) {
				m = (li+ri) / 2;
				//cout << "ri " << ri << " " << a[m]- ((l > 1) ? a[l-2] : 0) << "\n";
				if (a[m]- ((l > 1) ? a[l-2] : 0) >= u) {
					//cout << "m " << m << " " << a[m]- ((l > 1) ? a[l-2] : 0) << "\n";
					ri = m;
				} else {
					li = m;
				}
			}
			int sum = a[ri]-((l > 1) ? a[l-2] : 0);
			//cout << "ri, sum " << ri << " " << sum << "\n";
			if (ri > 0  && ri > l-1 && sum > u + 1) {
				int sum_left = a[ri-1] - ((l-1 > 0) ? a[l-2] : 0);
				if (u*(u+1)/2 - (sum - u -1)*(sum - u)/2 > (u*(u+1)/2 - (u-sum_left)*(u-sum_left+1)/2)) {
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

