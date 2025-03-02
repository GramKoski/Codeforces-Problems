#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define inf 1e9

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> dp(3, 0);
		int maxO, maxE;
		maxO = maxE = 0;
		vector<char> maxC(2);
		vector<int> charsE(26, 0);
		vector<int> charsO(26, 0);
		for (int i = 0; i < n; ++i) {
			if (i%2 == 0) {
				charsE[s[i]-'a'] += 1;
				if (maxE <= charsE[s[i]-'a']) {
					maxE = charsE[s[i]-'a'];
					maxC[0] = s[i];
				}
			} else {
				charsO[s[i]-'a'] += 1;
				if (maxO <= charsO[s[i]-'a']) {
					maxO = charsO[s[i]-'a'];
					maxC[1] = s[i];
				}
			}
		}
		dp[0] = (s[0] != maxC[0]);
		dp[1] = 1;
		if (n > 1) {
			dp[2] = (s[0] != maxC[1]);
		}
		for (int i = 1; i < n; ++i) {
			dp[1] = (min(1+dp[0], dp[1] + ((s[i] == maxC[(i)%2]) ? 0 : 1)));
			dp[0] += ((s[i] == maxC[i%2]) ? 0 : 1);
			dp[2] += ((s[i] == maxC[(i-1)%2]) ? 0 : 1);
		}
		cout << ((n%2 == 0) ? dp[0]: dp[1]) << "\n";
	}
}
