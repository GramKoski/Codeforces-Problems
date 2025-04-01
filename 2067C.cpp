#include <iostream>

#define ll long long 

using namespace std;

int main() {
	int t; cin >> t; 
	while (t--) {
		int n; cin >> n;
		int res = (n >= 9) ? 7 : 9; int m;
		for (int k = 0; k < 10; ++k) {
			int n_cpy = n-k;
			while (n_cpy > 0) {
				m = ((7 - (n_cpy % 10) % 10));
				if (m < 0) {
					m += 10;
				}
				//cout << n_cpy << " " << m << " " << k << "\n";
				if (m <= k) {
					res = min(res, k);
					break;
				}
				n_cpy /= 10;
			}
		}
		cout << res << "\n";
	}
}


