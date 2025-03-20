#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n-2; ++i) {
			cout << i+1 << " " << i+1 << "\n";
		}
		cout << n << " " << n << "\n";
		cout << n << " " << n-1 << "\n";
		cout << "\n";
	}
}
