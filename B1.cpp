#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n+1);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		// DP problem
		vector<int> dp(n+1);
		vector<int> m(n+1, 0);
		vector<int> v(n+1, 0);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			if (v[a[i]] > 0) {
				int j = v[a[i]];
				if (dp[j-1] + i - j + 1 > dp[m[a[i]]-1] + i-m[a[i]] + 1) m[a[i]] = j;
				dp[i] = max(dp[i-1], dp[m[a[i]]-1] + i-m[a[i]] + 1);
			} else {
				dp[i] = dp[i-1];
				m[a[i]] = i;
			}
			//cout << i << " " << dp[i] << " " << m[a[i]] << "\n";
			v[a[i]] = i;
		}

		cout << dp[n] << "\n";
	}
}

