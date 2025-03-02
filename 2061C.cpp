#include <iostream>
#include <vector>

#define ll long long unsigned

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<ll> dp(n, 0);
		dp[0] = (a[0] == 0) ? 1 : 0;
		for (int i = 1; i < n; ++i) {
			if (a[i] == a[i-1] ) {
				dp[i] += dp[i-1];
			}
			if (i > 1) {
				dp[i] += (a[i] == a[i-2] + 1) ? dp[i-2] : 0;
			} else {
				dp[i] += (a[i] == 1) ? 1 : 0;
			}
			dp[i] %= 998244353;
		}
		ll res = (dp[n-1] + ((n > 1) ? dp[n-2] : 1)) % 998244353;
		cout << res << "\n";
	}
}

