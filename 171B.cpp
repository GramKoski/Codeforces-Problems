#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int r = 0;
	int sum = 0;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		while(r < n && sum + a[r] <= t) {
			sum += a[r];
			r++;
		}

		res = max(res, r-i);
		sum -= a[i];
	}
	cout << res << "\n";
}
