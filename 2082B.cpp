#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll x, n, m; cin >> x >> n >> m;
		ll x_cpy = x; ll n_cpy = n; ll m_cpy = m;
		ll min = x; ll max = x;
		while (x > 0 && (n > 0 || m > 0)) {
			if (x != 1) {
				if (m > 0) {
					x = (x+1)/2; m -= 1;
				} else {
					x /= 2; n -= 1;
				}
			} else {
				if (n > 0) {
					x = 0;
				} else {
					m = 0;
				}
			}		
		}
		min = x;
		while (x_cpy > 0 && (n_cpy > 0 || m_cpy > 0)) {
			if (x_cpy != 1) {
				if (n_cpy > 0) {
					x_cpy /= 2; n_cpy -= 1;
				} else {
					x_cpy = (x_cpy+1)/2; m_cpy -= 1;
				}
			} else {
				if (n_cpy > 0) {
					x_cpy = 0;
				} else {
					m_cpy = 0;
				}
			}
		}
		max = x_cpy;
		cout << min << " " << max << "\n";
	}
}

