#include <iostream>

using namespace std;

#define llu long long unsigned

int main() {
	int t; cin >> t;
	while (t--) {
		llu n, a, b, c; cin >> n >> a >> b >> c;
		int r = n % (a+b+c);
		int res = (r > 0) ? 1 : 0;
		if (r > a) {
			res += 1;
			if (r-a > b) {
				res += 1;
			}
		}
		res += (n / (a+b+c)) * 3;
		cout << res << "\n";
	}
}
