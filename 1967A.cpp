#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> freq(n, 0);
		int a;
		for (int i = 0; i < n; ++i) {
			cin >> freq[i];
		}
		sort(freq.begin(), freq.end());
		int i = 1; int res = 0;
		int curr = freq[0];
		res += curr*n;
		while (i < n) {
			if (freq[i] > curr) {
				res += min(k, (i)*(freq[i]-curr));
				k -= (i)*(freq[i]-curr);
				res += (n-i);
				curr = freq[i];
			}
			i += 1;
			if (k < 0) break;
		}
		cout << res + max(0, k) << "\n";
	}
}

