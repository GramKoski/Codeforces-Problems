#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int i = n-1;
	while (i >= 1 && a[i-1] != i+1) {
		i -= 1;
	}
	cout << i << "\n";
}

