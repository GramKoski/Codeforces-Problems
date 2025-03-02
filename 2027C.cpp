#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <set>

#define ll long long

using namespace std;

vector<ll> binary_search(vector<pair<ll, int>> a, ll val) {
	int l = -1; int r = a.size(); int m;
	vector<ll> res;
	if (a[r-1].first < val) {
		return res;
	}
	while (l < r-1) {
		m = (l+r)/2;
		if (a[m].first >= val) {
			r = m;
		} else {
			l = m;
		}
	}
	while (r < a.size() && a[r].first == val) {
		res.push_back(val+a[r].second);
		r += 1;
	}
	return res;
}


int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<ll, int>> a;
		ll b;
		for (int i = 0; i < n; ++i) {
			cin >> b;
			//if (b - (n-i) >= 0) {
			a.push_back({b-(n-i), i});
			//}
		}
		//Solution: breadth first search with binary search optimization
		queue<ll> q;
		sort(a.begin(), a.end());
		vector<ll> next = binary_search(a, 0);
		for (auto c : next) q.push(c);
		ll maxZeros = 0;
		vector<bool> v(n*n, false);
		v[0] = true;
		ll curr;
		while (!q.empty()) {
			int length = q.size();
			while (length--) {
				curr = q.front();
				if (v[curr]) {
					q.pop();
					continue;
				}
				//cout << q.front() << "\n";
				v[curr] = true;
				maxZeros = max(maxZeros, curr);
				next = binary_search(a, curr);
				for (auto c : next) q.push(c);
				q.pop();
			}
		}
		cout << a.size() + maxZeros << "\n";
	}
}

			
