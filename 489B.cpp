#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	int b[m];
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	//Sort static arrays
	sort(a, a + n);
	sort(b, b + m);

	int ai, bi, res;
	ai = bi = res = 0;
	while (ai < n && bi < m) {
		if (abs(a[ai] - b[bi]) <= 1) {
			res += 1;
			ai += 1;
			bi += 1;
		} else if (a[ai] > b[bi]) {
			bi += 1;
		} else {
			ai += 1;
		}
	}
	cout << res;
}
