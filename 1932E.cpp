#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		string s; cin >> s;
		ll val = 0; ll res = 0;
		for (ll i = 0; i < n; ++i) {
			val *= 10;
			val += (s[i]-'0');
			res += (val-val/10)*(n-i);
			cout << val << " " << res << "\n";
		}
		cout << res << "\n";
	}
}


