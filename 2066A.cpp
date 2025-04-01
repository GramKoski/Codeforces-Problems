#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n+1);
		map<int, int> x;
		bool is_permutation = true;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (x.find(a[i]) == x.end()) {
				x[a[i]] = i;
			} else {
				is_permutation = false;
			}
		}
		if (is_permutation) {
			cout << "? " << x[1] << " " << x[n] << "\n";
			cout.flush();
			int l; cin >> l;
			if (l < n-1) {
				cout << "! A\n";
				cout.flush();
			} else {
				cout << "? " << x[n] << " " << x[1] << "\n";
				cout.flush();
				int l2; cin >> l2;
				if (l2 < n-1 || l2 != l) {
					cout << "! A\n";
					cout.flush();
				} else {
					cout << "! B\n";
					cout.flush();
				}
			}
		} else {
			int missing;
			for (int i = 1; i <= n; ++i) {
				if (x.find(i) == x.end()) {
					missing = i;
				}
			}
			int o = (missing == 1) ? 2 : 1;
			cout << "? " << missing << " " << o << "\n";
			cout.flush();
			int l; cin >> l;
			if (l > 0) {
				cout << "! B\n";
			} else {
				cout << "! A\n";
			}
			cout.flush();
		}
	}
}
					
