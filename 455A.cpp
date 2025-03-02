#include <iostream>
#include <vector>
#include <algorithm>

#define llu long long unsigned
using namespace std;

int main() {
	int n, a;
	cin >> n;
	int m = 0;
	int count[100001] = {0};
	for (int i = 0; i < n; ++i) {
		cin >> a;
		count[a] += 1;
		m = max(a, m);
	}

	llu dp[m+1];
	dp[0] = 0;
	dp[1] = count[1];
	for (llu i = 2; i <= m; ++i) {
		dp[i] = max(dp[i-1], dp[i-2] + i*count[i]);
	}
	cout << dp[m] << "\n";
}
	
