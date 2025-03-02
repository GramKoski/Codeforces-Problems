#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define val(m) (((2)*(m+1)-n)*(k) + (m)*(m+1) - ((n)*(n-1))/(2))

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		//Binary search
		ll l = 0; ll r = n-1; ll m; ll val;
		while (l <= r) {
			m = (l+r)/2;
			val = val(m);
			if (val < 0) {
				l = m+1;
			} else if (val > 0) {
				r = m-1;
			} else {
				break;
			}
		}
		ll temp = m;
		if (m > 0 && abs(val(m-1)) < abs(val)) {
			temp = m-1;
			val = val(m-1);
		}
		if (m < n-1 && abs(val(m+1)) < abs(val)) {
			temp = m+1;
		}
		m = temp;
		cout << abs(val(m)) << "\n";
	}
}
