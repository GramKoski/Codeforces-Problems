#include <iostream>
#include <vector>

using namespace std;

int main() {
	int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
	if (l1 < l2) {
		if (r1 > l2) {
			cout << min(r2-l2, r1-l2) << "\n";
		} else {
			cout << 0 << "\n";
		}
	} else {
		if (l1 < r2) {
			cout << min(r2-l2, min(r1-l1, r2 - l1)) << "\n";
		} else {
			cout << 0 << "\n";
		}
	}
}
