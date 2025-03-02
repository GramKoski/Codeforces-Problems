#include <iostream>
#include <vector>
#include <unordered_map>

#define llu long long unsigned

using namespace std;
const int MOD = 1e9+7;
int main() {
	int t; cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		vector<int> pre(n+1, 0);
		unordered_map<int, llu> prev;
		prev[0] = {1};
		llu res = 0;
		for (int i = 1; i <= n; ++i) {
			pre[i] = pre[i-1] + ((s[i-1] == '0') ? -1 : 1);
			res += prev[pre[i]]*(n-i+1) % MOD;
			if (prev.find(pre[i]) != prev.end()) {
				prev[pre[i]] += i+1;
			} else {
				prev[pre[i]] = i+1;
			}
		}	
		cout << res % MOD<< "\n";
	}
}

