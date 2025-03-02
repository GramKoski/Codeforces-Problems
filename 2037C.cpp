#include <iostream>
#include <string>

using namespace std;

int main() {

	int t, n;
	cin >> t;

	for (int _ = 0; _ < t; ++_) {
		cin >> n;
		if (n <= 4) {
			cout << -1 << "\n";
		} else {
			for (int i = 6; i <= n; i += 2) {
				cout << i << " ";
			}
			cout << 2 << " " << 4 << " " << 5 << " ";
			for (int i = 7; i <= n; i += 2) {
				cout << i << " ";
			}
			cout << 1 << " " << 3 << "\n";
		}
	}
}



