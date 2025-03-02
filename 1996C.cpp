#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n, q;
		string a, b;
		cin >> n >> q >> a >> b;
		vector<vector<int>>preA(n, vector<int>(26, 0));
		vector<vector<int>>preB(n, vector<int>(26, 0));
		preA[0][a[0]-'a'] = 1;
		preB[0][b[0]-'a'] = 1;
		for (int i = 1; i < n; ++i) {
			preA[i] = preA[i-1];
			preB[i] = preB[i-1];
			preA[i][a[i]-'a'] += 1;
			preB[i][b[i]-'a'] += 1;
		}
		while (q--) {
			int l, r;
			cin >> l >> r;
			int res = 0;
			l -= 1;
			r -= 1;
			for (int i = 0; i < 26; ++i) {
				vector<int>Al = (l > 0) ? preA[l-1] : vector<int>(26, 0);
				vector<int>Bl = (l > 0) ? preB[l-1] : vector<int>(26, 0);
				res += abs((preA[r][i]-Al[i]) - (preB[r][i] - Bl[i]));
			}
			cout << res/2 << "\n";
		}
	}
}
