#include <iostream>
#include <vector>
#include <algorithm>

#define llu long long unsigned

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		llu n, a;
		llu sum = 0;
		cin >> n;
		vector<llu> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> a;
			arr[i] = a;
			sum += a;
		}
		if (n <= 2) {
			cout << -1 << "\n";
			continue;
		}
		sort(arr.begin(), arr.end());
		llu mid = arr[n/2];
		if (sum > 2*n*mid) {
			cout << 0 << "\n";
		} else {
			cout << 2*n*mid - sum + 1 << "\n";
		}
	}
}
