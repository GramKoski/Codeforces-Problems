#include <iostream>

using namespace std;

int main () {
	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a %2 != 0) {
			cout << "NO\n";
		} else {
			if (b%2 != 0) {
				if (a >= 2) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
			} else {
				cout << "YES\n";
			}
		}
	}
}
