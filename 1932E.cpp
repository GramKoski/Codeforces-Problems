#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>


#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		string s; cin >> s;
		vector<int> pre(n);
		pre[0] = (int)(s[0] - '0');
		for (int i = 1; i < n; ++i) {
			pre[i] = (int)(s[i] - '0') + pre[i-1];
		}
		//Use clever carrying algo to calculate the actual sum from the prefix sum
		reverse(pre.begin(), pre.end());
		string res;
		int c = 0;
		for (int i = 0; i < n; ++i) {
			c += pre[i];
			res += (char)(c%10 + '0');
			c /= 10;
		}
		while (c != 0) {
			res += (char)(c%10+'0');
			c /= 10;
		}
		//Remove leading zeros
		int l = res.length();
		for (int i = l - 1; res[i] == '0' && i >= 0; --i) {
			res.pop_back();
		}
		reverse(res.begin(), res.end());
		cout << res << "\n";
	}
}


