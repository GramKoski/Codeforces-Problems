#include <iostream>
#include <vector>

#define ll long long

using namespace std;


int main() {
	ll n; cin >> n;
	ll p; p = 1e9 + 7;
	vector<ll> res(n+1);
	res[0] = 1;
	res[1] = 1;

	for (int i = 2; i <= n; ++i) {
		res[i] = res[i-1]*2;
		if (i > 6) {
			res[i] -= res[i-7];
		}
		res[i] %= p;
		if (res[i] < 0) res[i] += 1e9+7;
	}
	cout << res[n] << "\n";
}
