#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int k; cin >> k; vector<ll> res;
		while (k != 0) {
			//Binary search
			int l;
			for (l = 0; l < k+2; ++l) {
				if (l*(l-1)/2 > k) {
					break;
				}
			}
			l--;
			k -= l*(l-1)/2;
			res.push_back(l);
			//cout << k << " " << l << "\n";
		}
		ll sum = 0;
		for (auto e : res) sum += e;
		cout << sum << "\n";
		int curr = 0;
		for (int i = 0; i < res.size(); ++i) {
			for (int j =0; j < res[i]; ++j) {
				cout << i << " " << curr + j << "\n";
			}
			curr = curr+res[i];
		}
	}
}
