#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define llu long long unsigned


int main() {
	int t; cin >> t;
	while (t--) {
		llu n, m, k;
		cin >> n >> m >> k;
		vector<llu> a(n);
		for (int i =0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		llu price = 0;
		for (int i = 0; i < k/m; ++i) {
			 price += a[i]*m + m*i*m;
			 //cout << "p = " << a[i]*m + i*m*m << "\n";
		}
		//cout << a[k/m] << " " << k%m << " " << price << "\n";
		price += a[k/m]*(k%m) + ((k > m) ? (k/m)*m*(k%m) : 0);
		cout << price << "\n";
	}
}
