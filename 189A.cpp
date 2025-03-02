#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int cuts[4001] = {-1};

	cuts[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cuts[i] = max(max((i >= a) ? cuts[i-a] : -1, (i >= b) ? cuts[i-b] : -1), (i >= c) ? cuts[i-c] : -1) + 1;
		cuts[i] = (cuts[i] == 0) ? -1 : cuts[i];
		//printf("cuts[%d] = %d\n", i, cuts[i]);
	}
	cout << cuts[n] << "\n";
}
