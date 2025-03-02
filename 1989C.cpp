#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		int s;
		int ll, a, b, dd;
		ll = 0; a = 0; b = 0; dd = 0;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			if (s == -1) {
				if (arr[i] == -1) {
					dd += 1;
				} else if (arr[i] == 1) {
					a += 1;
				}
			} else if (s == 1) {
				if (arr[i] == 1) {
					ll += 1;
				} else {
					b += 1;
				} 
			} else if (s == 0) {
				if (arr[i] == 1) {
					a += 1;
				}
			}
		}
		int temp;
		if (b > a) {
			temp = a;
			a = b;
			b = temp;
		}
		while (ll > 0 && a-b > 0) {
			b += 1;
			ll -= 1;
		}
		while (a > b && dd > 0) {
			a -= 1;
			dd -= 1;
		}
		b += ll/2; a += ll/2;
		b -= dd/2; a -= dd/2;
		if (a == b && dd%2 && !(ll%2)) {
			b -= 1;
		}
		cout << b << "\n";

	}
}
