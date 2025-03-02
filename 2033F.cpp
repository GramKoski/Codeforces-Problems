#include <iostream>

#define llu long long unsigned

using namespace std;

int main() {
	int t;
	llu n, k;
	llu mod = 1e9 + 7;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		n = n % mod;
		llu n1 = 1;
		llu n2 = 0;
		int res = 1;
		int temp;
		while (n1 % k != 0) {
			temp = n1;
			n1 = n1+n2;
			n2 = temp;
			res += 1;
		}

		cout << res << " " <<  (res*n) % mod<< "\n";
	}
}
