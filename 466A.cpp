#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int res = min((n / m) * b + (n%m) * a, a*n);
	res = min(res, (n / m + 1) * b);
	cout << res;
}

