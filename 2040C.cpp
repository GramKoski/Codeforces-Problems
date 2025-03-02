#include <iostream>
#include <vector>

#define llu long long unsigned
#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		vector<int> a(n);
		llu pos = 1;
		llu swap_val = (llu)1 << ((n > 64) ? 62 : n-2);
		int i = 0;
		for (; n-i > 64; ++i) {
			a[i] = i+1;
		}
		int first = i;
		for (; i < n; ++i) {
			if (pos + swap_val <= k) {
				a[n-1- (i-first)] = i+1;
				pos += swap_val;
			} else {
				a[first] = i+1;
				first += 1;
			}
			swap_val /= 2;
		}	
		if (pos < k) {
			cout << -1;
		} else {
			for (auto c : a) cout << c << " ";
		}
		cout << "\n";
	}
}

