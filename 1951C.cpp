#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long


int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n);
		for (int i =0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		ll price = 0;
		ll tax = 0;
		for (int i = 0; i < k/m; ++i) {
			price += a[i]*m+tax*m;
			tax += m;
		}
		price += a[k/m]*(k%m) + tax*(k%m);
		cout << price + tax << "\n";
	}
}
