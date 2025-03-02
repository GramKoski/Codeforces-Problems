#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int l = 1;
		int r = 1000;
		int m; int res;
		while (l < r-1) {
			m = (l+r)/2;
			cout << "? " << 1 << " " << m << "\n"; fflush(stdout);
			cin >> res;
			if (m == res) {
				l = m;
			} else {
				r = m;
			}
		}
		cout << "! " << r << "\n"; fflush(stdout);
	}
}

