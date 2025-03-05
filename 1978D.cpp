#include <vector>
#include <iostream>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, c; cin >> n >> c;
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<ll> pre(n, 0);
		pre[0] = a[0];
		for (int i = 1; i < n; ++i) {
			pre[i] = a[i] + pre[i-1];
		}
		vector<ll> post(n, 0);
		int maxi = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > a[maxi]) maxi = i;
		}
		post[n-1] = a[n-1];
		for (int i = n-2; i >= 0; --i) {
			post[i] = max(post[i+1], a[i]);
		}
		vector<ll> res(n, 0);
		for (int i = 0; i < n; ++i) {
			if (i == maxi && a[i] > a[0]+c) continue;
			if (pre[i]+c < post[i] ) {
				res[i] += 1;
			}
			res[i] += i;
		}
		for (auto r : res) cout << r << " ";
		cout << "\n";
	}
}
