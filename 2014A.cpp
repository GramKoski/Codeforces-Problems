#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k, a, res;
		cin >> n >> k;
		int curr = 0;
		res = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			if (a >= k) {
				curr += a;
			} else if (a == 0 && curr > 0) {
				res += 1;
				curr -= 1;
			}
		}
		cout << res <<  "\n";
	}
}
