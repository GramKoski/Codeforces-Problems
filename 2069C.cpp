#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t; 
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		ll m = 998244353;
		for (int i = 0; i < n; ++i) cin >> a[i];
		vector<vector<ll>> dp(n, vector<ll>(3));
		ll res = 0;
		if (a[0] == 1) dp[0][0] = 1;
		dp[0][2] = 0;
		dp[0][1] = 0;
		for (int i = 1; i < n; ++i) {
			dp[i][0] = (a[i] == 1) ? (dp[i-1][0] + 1) % m: dp[i-1][0];
			dp[i][1] = (a[i] == 2) ? (dp[i-1][1]*2 + dp[i-1][0]) % m : dp[i-1][1];
			if (a[i] == 3) {
				res += dp[i][1];
				res %= m;
			}
		}
		cout << res % m << "\n";
	}
}
						
