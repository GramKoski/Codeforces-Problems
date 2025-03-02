#include <vector>
#include <iostream>
#include <unordered_set>
#include <cmath>

#define ll long long
#define llu long long unsigned

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_set<int> used;
		vector<int> res(n);
		if (n == 1) {
			res[0] = 1;
			cout << "0" << "\n";
		} else if (n == 2) {
			res[0] = 1;
			res[2] = 2;
			cout << 2 << "\n";
		} else if (n == 3 || n == 4) {
			for (int i = 0; i < n; ++i) res[i] = i;
			cout << ((n == 3) ? 2 : 6) << "\n";
		} else {
			int i; int lsb = 0; int max = 0;
			for (i = 1; i <= n; i <<=1) {
				if (lsb == 0 && ((n & i) == i)) {
					lsb = i;
				}
				max |= i;
			}
			i = i >> 1;
			int border;
			if (n == i) {
				int smb = i >> 1;
				res[n-5] = smb; res[n-4] = smb+1; res[n-3] = smb-1; res[n-2] = n-1; res[n-1] = n;
				used.insert(smb); used.insert(smb+1); used.insert(smb-1); used.insert(n-1); used.insert(n);
				border = 6;
				cout << max << "\n";
			} else if (n % 2 == 0) {
				res[n-3] = n; res[n-2] = n-1; res[n-1] = i-1;
				used.insert(n); used.insert(n-1); used.insert(i-1);
				border = 4;
				cout << max << "\n";
			} else {
				res[n-4] = lsb; res[n-3] = lsb + ((lsb == 1) ? 2 : 1); res[n-2] = n-lsb; res[n-1] = n;
				used.insert(lsb); used.insert(lsb + ((lsb == 1) ? 2 : 1)); used.insert(n-lsb); used.insert(n);
				border = 5;
				cout << n << "\n";
			}
			int a = 1;
			for (int i = 0; i <= n-border; ++i) {
				while (used.find(a) != used.end()) {
					++a;
				}
				res[i] = a;
				++a;
			}
		}
		for (auto a : res) cout << a << " ";
		cout << "\n";
	}
}

		
