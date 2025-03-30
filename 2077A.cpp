#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t; 
	while (t--) {
		int n; cin >> n;
		vector<ll> a(2*n+1);
		for (int i = 0; i < 2*n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		vector<ll> res(2*n+1);
		ll sum = 0; int curr = 0;
		for (int i = 0; i <= n; ++i) {
			res[2*i] = a[curr];
			sum += a[curr];
			curr += 1;
		}
		for (int i = 1; i < 2*n-1; i += 2) {
			res[i] = a[curr];
			sum -= a[curr];
			curr += 1;
		}
		res[2*n-1] = sum;
		for (auto e : res) cout << e << " ";
		cout << "\n";
	}
}



