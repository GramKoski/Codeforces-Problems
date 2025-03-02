#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if ((n+1)/2 % 2 == 1) {
			if ((n-k+1)/2 % 2 == 1) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			if ((n-k+1)/2 % 2 == 1) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		}
	}
}
