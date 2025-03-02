#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll l, r; cin >> l >> r;
		ll n1 = 1; 
		ll n2 = 1; 
		ll n3 = l;
		int k = 64- __builtin_clzll(l ^ r);
		n1 = (r >> (k-1))<<(k-1);
		n2 = n1 - 1;
		n3 = (n2 == l) ? r : l;
		cout << n1 << " " << n2 << " " << n3 << "\n";
	}
}

