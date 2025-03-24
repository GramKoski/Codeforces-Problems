#include <iostream>
#include <set>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, m, k, d;
		cin >> n >> m >> k >> d;
		vector<vector<ll>> a(n, vector<ll>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}
		vector<ll> cost(n, 0);
		for (int i =0; i < n; ++i) {
			multiset<ll> pre;
			vector<ll> dp(m);
			pre.insert(1);
			dp[0] = 1;
			for (int j = 1; j <= d+1 && j < m; ++j) {
				dp[j] = a[i][j] + 2;
				pre.insert(a[i][j] + 2);
			}
			for (int j = d+2; j < m; ++j) {
				pre.erase(pre.find(dp[j-(d+2)]));
				dp[j] = a[i][j] + *pre.begin() + 1;
				pre.insert(dp[j]);
			}
			cost[i] = dp[m-1];

		}
		for (int i = 1; i < n; ++i) cost[i] += cost[i-1];
		ll res = cost[k-1];
		for (int i = k; i < n; ++i) {
			res = min(res, cost[i] - cost[i-k]);
		}
		cout << res << "\n";
	}
}
