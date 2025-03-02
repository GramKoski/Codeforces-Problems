#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		vector<int> arr(n);
		vector<ll> pre(n+1);
		pre[0] = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			pre[i+1] = pre[i] + arr[i];
		}
		vector<ll> dp(n, 0); int l, r, m;
		ll res = 0;
		for (int i = n-1; i >= 0; --i) {
		//binary search
			l = -1;
			r = n;
			while (l+1 != r) {
				m = (l+r) / 2;
				if (pre[m+1]-pre[i] > x) {
					r = m;
				} else {
					l = m;
				}
			}
			dp[i] = r-i + ((r < n-1) ? dp[r+1] : 0);	
			//cout << "i = " << i << " r = " << r << " dp[i] = " << dp[i] << "\n";
			res += dp[i];
		}
		cout << res << "\n";
	}
}
