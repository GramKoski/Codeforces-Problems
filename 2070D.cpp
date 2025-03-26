#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll mod = 1e9 + 7;
		map<ll, vector<ll>> m; ll p;
		for (ll i = 1; i < n; ++i) {
			cin >> p;
			if (m.find(p-1) == m.end()) {
				m[p-1] = {i};
			} else {
				m[p-1].push_back(i);
			}
		}
		queue<ll> q;
		q.push(0);
		vector<ll> prev;
		prev.push_back(0);
		vector<ll> paths(n);
		paths[0] = 0;
		ll curr = 0;
		ll curr_sum = 0;
		ll size;
		while (!q.empty()) {
			size = q.size();
			ll curr_sum = 0;
			for (int i = 0; i < size; ++i) {
				ll curr = q.front();
				q.pop();
				for (auto c : m[curr]) {
					paths[c] = ((curr == 0) ? 1 : (prev[curr]*(size-1)%mod));
					curr_sum += paths[c];
					curr_sum %= mod;
					//cout << curr << " " << c << " " << paths[c] << "\n"; 
					q.push(c);
				}
			}
			prev.push_back(curr_sum%mod);
		}
		ll res = 0;
		for (auto sum : prev) {
			res += sum % mod;
			res %= mod;
		}
		cout << (res+1) % mod << "\n";
	}
}


