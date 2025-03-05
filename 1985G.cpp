#include <iostream>

#define ll long long

using namespace std;

ll mod = 1e9+7;

//First time using modular expo algorithm
ll exp(ll x, ll n, ll m) {
	ll res = 1;
	x %= m;
	while (n > 0) {
		if (n % 2 == 1) {res = res*x%m;}
		x = x*x%m;
		n /= 2;
	}
	return res%m;
}


int main() {
	int t; cin >> t;
	while (t--) {
		int l, r, k; cin >> l >> r >> k;
		ll res = exp((9/k) + 1, r, mod) - exp((9/k) + 1, l, mod);
		res %= mod;
		cout << ((res >= 0) ? res : 1000000007+res) << "\n";
	}
}
