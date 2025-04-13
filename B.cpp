#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int h, m; cin >> h >> m;
	int a, b, c, d;
	a = h/10; b = h%10; c = m/10; d = m%10;
	if ((a >= 2 && c >= 4)) {
		h = (h + 1) % 24;
		m = 0;
	}
	a = h/10; b = h%10; c = m/10; d = m%10;
	if (b >= 6) {
		h = (h + 10-b) % 24;
		m = 0;
	}
	cout << h << " " << m << "\n";

}
