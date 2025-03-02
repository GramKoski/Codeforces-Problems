#include <iostream>

#define llu long long unsigned

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		llu esum = 0;
		llu osum = 0;
		int a;
		int i = n;
		while (i--) {
			cin >> a;
			if (i % 2) {
				osum += a;
			} else {
				esum += a;
			}
		}
		//cout << esum << " " << osum << "\n";
		if ((esum % ((n%2) ? n/2+1 : n/2) == 0) && (osum % (n/2) == 0) && (esum/((n%2) ? n/2+1 : n/2) == osum/(n/2))) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}

