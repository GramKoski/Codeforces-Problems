#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int _ = 0; _ < t; ++_) {
		int n;
		cin >> n;
		int x = 0;
		int i = 1;
		while (abs(x) <= n) {
			//cout << abs(x) << " " << i << "\n";
			if (i % 2 == 1) {
				x = x - (2*i-1);
			} else {
				x += (2*i-1);
			}
			i += 1;
		}
		if (i%2 ==0) {
			cout << "Sakurako\n";
		} else {
			cout << "Kosuke\n";
		}
	}
}
