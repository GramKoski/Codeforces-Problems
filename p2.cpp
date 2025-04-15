#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int, int>> a;
	int m; int l; int r;
	for (int i = 0; i < n; ++i) {
		cin >> m; 
		for (int j = 0; j < m; ++j) {
			cin >> l >> r;
			a.push_back({l, r});
		}
	}
	int f = 0;
	int num_seconds = 0;
	for (int i = 0; i <= 86400; ++i) {
		int curr = 0;
		for (auto e : a) {
			if (e.first <= i && e.second >= i) {
				curr += 1;
			}
		}
		if (curr > f) {
			f = curr;
			num_seconds = 1;
		} else if (curr == f) {
			num_seconds += 1;
		}
	}
	cout << f << "\n" << num_seconds << "\n";
}
