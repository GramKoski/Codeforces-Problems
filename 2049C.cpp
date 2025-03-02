#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x, y; cin >> n >> x >> y;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			a[(i+x-1) % n] = i % 2;
		}
		if (abs(x-y) > 1 && abs(x+n-y) > 1 && abs(y+n-x) > 1 && (x-y) % 2 == 0) {
			a[x-1] = 2;
		}
		if (n%2 == 1) {
			a[x-1] = 2;
		}
		for (auto c : a) cout << c << " ";
		cout << "\n";
	}
}
