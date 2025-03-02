#include <iostream>
#include <vector>

#define llu long long unsigned

using namespace std;

int main() {
	llu MOD = 1e9;
	int t;
	cin >> t;
	while (t--) {
		llu n, a;
		cin >> n;
		vector<llu> arr(n);
		vector<llu> pre(n);
		vector<llu> post(n);
		llu sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			arr[i] = a;
			sum += a;
			//sum %= MOD;
			pre[i] = sum;
		}
		sum = 0;
		for (int i = 1; i < n; ++i) {
			sum += pre[i-1]*arr[i];
			//sum %= MOD;
		}
		//cout << sum << "\n";
		llu Q = (n*(n-1))/2;
		cout << sum/Q % MOD << "\n";
	}
}
