#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int k;
		ll res = 0;
		for (int g = 1; g <= min(m, n); ++g) {
			k = ((n/g)+1)/g;
			res += k;
		}
		cout << res-1 << "\n";
	}
}
