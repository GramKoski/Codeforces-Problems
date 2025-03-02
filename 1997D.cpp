#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

#define ll long long

bool valid(unordered_map<int, vector<int>> adj, vector<int> a, int k) {
	bool is_valid = true;
	queue<pair<int, ll>> q;
	q.push({1, k});
	while (!q.empty()) {
		ll curr_v = q.front().first;
		ll curr_k = q.front().second;
		//cout << curr_v << " " << curr_k << "\n";
		q.pop();
		if ((adj.find(curr_v) == adj.end() && a[curr_v] < curr_k) || curr_k > 2e9 || (curr_v != 1 && curr_k - a[curr_v] > 1e9)) {
			is_valid = false;
			break;
		}
		ll g = ((curr_v == 1) ? 0 : curr_k);
		for (auto u : adj[curr_v]) {
			q.push({u, g+((curr_k-a[curr_v] > 0) ? curr_k-a[curr_v] : 0)});
		}
	}
	return is_valid;
}
		

int main() {
	int t; cin >> t;
	//Build adjacency matrix
	//function for checking if valid
	//call from main for each min child of root
	//use binary search with this with values 0, 10^9
	while (t--) {
		int n; cin >> n;
		unordered_map<int, vector<int>> adj;
		vector<int> a(n+1);
		for (int i =1; i <= n; ++i) {
			cin >> a[i];
		}
		int p;
		for (int i = 2; i <= n; ++i) {
			cin >> p;
			if (adj.find(p) == adj.end()) {
				adj[p] = {i};
			} else {
				adj[p].push_back(i);
			}
		}

		//main binary search to check for greatest valid value
		int l = 0; 
		int r = 2e9+1;
		while (l < r-1) {
			int m = (l+r)/2;
			bool v = valid(adj, a, m);
			//cout << l << "\n";
			if (v) {
				l = m;
			} else {
				r = m;
			}
		}
		cout << l << "\n";
	}
}


