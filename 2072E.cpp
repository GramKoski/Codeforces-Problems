#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int k; cin >> k; vector<int> res;
		while (k != 0) {
			//Binary search
			int l = 0; int r = k+2; int mid;
			while (l < r -1) {
				mid = (l+r)/2;
				if (mid*(mid-1)/2 <= k) {
					l = mid;
				} else {
					r = mid;
				}
			}
			res.push_back(l);
			k -= l*(l-1)/2;
			cout << k << " " << l << "\n";
		}
		for (auto e : res) cout << e << " ";
		cout << "\n";
	}
}
