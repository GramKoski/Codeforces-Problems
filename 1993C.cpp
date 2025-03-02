#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<ll> a(n);
		vector<int> m(n);
		vector<int> ms(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			int mod = a[i] % (2*k);
			ms[i] = mod;
			if (mod > k) {
				m[i] = -1*(2*k-mod);
			} else {
				m[i] = mod;
			}
		}
		sort(ms.begin(), ms.end());
		sort(a.begin(), a.end());
		sort(m.begin(), m.end());
		if (ms.back() - ms[0] < k) {
			cout << ((a.back() / (2*k))*2*k + ms.back()) << "\n";
		} else if (m.back() - m[0] < k) {
			if (m[0] < 0 && m.back() < 0) {
				cout << 2*k*((a.back()+2*k-1) / (2*k)) + m.back() << "\n";
			} else if (m[0] < 0 && m.back() >= 0) {
				cout << ((a.back()+2*k-1) / (2*k)) * 2*k + (m.back()) << "\n";
			}
		} else {
			cout << -1 << "\n";
		}
	}
}
