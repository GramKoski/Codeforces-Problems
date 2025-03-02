#include <iostream>
#include <vector>

#define llu long long unsigned

using namespace std;
llu m = 1e9+7;

llu pw(llu a, llu b) {
	llu  r = 1;
	while(b > 0) {
		if(b & 1) r = (r * a) % m;
		b /= 2;
		a = (a * a) % m; 
	}
	return r;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int a, b, c; b = 0;
		for (int i = 0; i < n; ++i) {
			cin >> c;
			b += c;
		}
		a = n - b;
		//Formula sum from k+1/2 to b of b!/(b-i)!i!*a!/(a-(k-i))!(k-i)!
		//b seems to be the largest thing I must calculate factorial of
		if (b < (k+1)/2) {
			cout << 0 << "\n";
			continue;
		}
		vector<llu> fact(max(b+1, a+1));
		fact[0] = 1;
		for (int i = 1; i < max(a+1, b+1); ++i) {
			fact[i] = (i*fact[i-1])%m;
		}
		llu res = 0;
		cout << b << " " << a << " " << fact[b]*fact[a]%m << " " << (fact[b-(k-a)]*fact[(k-a)]*fact[a-(k-(k-a))]*fact[k-(k-a)])%m << "\n";
		for (int i = max((k+1)/2, k-a); i <= b; ++i) {
			res += fact[b]*fact[a] * pw((fact[b-i]*fact[i]*fact[a-(k-i)]*fact[k-i])%m, m-2);
			res %= m;
		}
		cout << res << "\n";
	}
}


