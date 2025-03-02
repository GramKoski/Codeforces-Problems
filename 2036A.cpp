#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t, n, valid;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int a, prev;
		cin >> n;
		cin >> prev;
		valid = 1;
		for (int i = 1; i < n; ++i) {
			cin >> a;
			if (abs(prev-a) != 5 && abs(prev-a) != 7) {
				//cout << prev << " " << a << " " << abs(prev-a) << "\n";
				valid = 0;
			}			
			prev = a;
		}
		if (valid) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
