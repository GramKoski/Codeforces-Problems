#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, m; cin >> n >> m;
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		string s;
		cin >> s;
		int l, r; l = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'L') l += 1;
		}
		r = l;
		l -= 1;
		ll res = 1;
		vector<ll> o(n);
		for (int i = n-1; i >= 0; --i) {
			if (s[i] == 'R') {
				res *= (a[r]%m);
				res %= m;
				o[i] = res;
				r += 1;
			} else {
				res *= (a[l]%m);
				res %= m;
				o[i] = res;
				l -= 1;
			}
		}
		for (int i = 0; i < n; ++i) cout << o[i] << " ";
		cout << "\n";
	}
}

