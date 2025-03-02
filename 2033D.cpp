#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define ll long long

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n;
		ll a;
		cin >> n;
		vector<ll> pre;
		unordered_map<ll, int> index;
		pre.push_back(0);
		index[0] = 0;
		vector<int> dp;
		dp.push_back(0);
		//pre[i] = sum of 0 to i-1
		//index[sum] = index of last occurence of some sum
		//dp[i] = max number of intervals that end at arr[i-1]
		for (int i = 1; i < n+1; ++i) {
			cin >> a;
			pre.push_back(pre[i-1] + a);
			dp.push_back(dp[i-1]);
			if (index.find(pre[i]) != index.end()) {
				dp[i] = max(dp[i], (a > 0) ? dp[index[pre[i]] - 1] + 1 : 1 + dp[i]);
			}
			index[pre[i]] = i;
		}
		cout << dp[n] << "\n";
	}
}

