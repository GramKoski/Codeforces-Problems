#include <iostream>

using namespace std;
#define llu long long unsigned

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		//Suppose c is 0. That gives max b = n/a for each a from 1 to n
		//Iterate through each
		llu res = 0;
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n/a and b <= n-a; ++b) {
				int c = min(((n-a*b)/(a+b) > 0) ? (n-a*b)/(a+b) : 0, (x-a-b > 0) ? x-a-b : 0);
				res += c;
			}
		}
		cout << res << "\n";
	}
}
