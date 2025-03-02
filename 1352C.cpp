#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t, n, k, res, m, prev;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> k;
		res = k;
		prev = res;
		m = k/n;
		while (m > 0) {
			res += m;
			m = (prev % n + m) / n;
			prev = res;
		}
		cout << res << "\n";
	}
}
