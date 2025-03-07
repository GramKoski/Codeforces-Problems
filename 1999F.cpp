#include <iostream>
#include <vector>

#define ll long long

ll p = 1e9 + 7;

using namespace std;

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		ll a, b, c; b = 0;
		for (int i = 0; i < n; ++i) {
			cin >> c;
			b += c;
		}
		a = n - b;
		//Formula sum from k+1/2 to b of b!/(b-i)!i!*a!/(a-(k-i))!(k-i)!
		//b seems to be the largest thing I must calculate factorial of
		vector<ll> fac(n+1);
		fac[0] = 1;
		for (int i = 1; i <= n; i++) { fac[i] = fac[i - 1] * i % p; }
		vector<ll> inv(n+1);
		inv[n] = exp(fac[n], p-2, p);
		for (ll i = n; i >= 1; i--) { inv[i-1] = inv[i] * i % p;}
		ll res = 0;
		for (ll i = max((k+1)/2, k-a); i <= min(b, k); ++i) {
			res += ((fac[b] * inv[i] % p * inv[b-i] % p) * (fac[a] * inv[k-i] % p * inv[a-(k-i)] % p))%p ;
		}
		cout << res%p << "\n";
	}
}


