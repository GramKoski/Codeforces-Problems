#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int _ = 0; _ < t; ++_) {
		int n;
		cin >> n;
		int prev = 0;
		int q;
		string res;
		for (int r = 2; r <= n; ++r) {
			cout << "? " << 1 << " " << r << endl;
			cin >> q;

			if (prev == 0 && q >0) {
				int k = q - prev;
				for (int i = 0; i < r-1-k; ++i) {
					res.append("1");
				}
				for (int i = 0; i < k; ++i) {
					res.append("0");
				}
			}

			if (prev < q) {
				res.append("1");
			}
			if (prev > 0 && q == prev) {
				res.append("0");
			}
			
			prev = q;
		}
		if (prev == 0) {
			cout << "! IMPOSSIBLE" << endl;
		} else {
			cout << "! " << res << endl;
		}
	}
}

		

