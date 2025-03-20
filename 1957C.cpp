#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		int r, c;
		for (int i = 0; i < k; ++i) {
			cin >> r >> c;
			if (r == c) {
				n -= 1;
			} else {
				n -= 2;
			}
		}
		ll m = 1e9 + 7;
		vector<ll> dp(n+1);
		if (n == 0) {
			cout << 1 << "\n";
		} else if (n==1) {
			cout << 1 << "\n";
		} else if (n==2) {
			cout << 3 << "\n";
		} else {
			dp[0] = 0; dp[1] = 1; dp[2] = 3;
			for (ll i = 3; i <= n; ++i) {
				dp[i] = (dp[i-1] + 2*(i-1)*dp[i-2])%m;
			}
			cout << dp[n]%m << "\n";
		}
	}
}

