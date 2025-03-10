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
			 price += a[i]*m;
		}
		if (k/m < n) {
			price += a[k/m]*(k%m);
		}
		//Each additional unit of tax is in bijection with the number of pairs not in the same index
		//How do I actually get the tax calculation correct?!

		for (int i = 0; i < k/m; ++i) price += m*i*m;
		price += (k%m)*k/m*m;
		cout << price << "\n";
	}
}
