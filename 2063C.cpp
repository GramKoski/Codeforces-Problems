#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<set<int>> adj(n+1); 
		int u, v;
		for (int i = 0; i < n-1; ++i) {
			cin >> u >> v;
			adj[u].insert(v);
			adj[v].insert(u);
		}
		vector<pair<int, int>> edges;
		for (int i = 1; i <= n; ++i) {
			if (adj[i].size() > 0) {
				edges.push_back({adj[i].size(), i});
			}
		}
		sort(edges.begin(), edges.end());
		int res = 0;
		//Take top element of map with most edges
		int g = edges.back().first;
		vector<int> great;
		while (!edges.empty() && edges.back().first == g)  {
			great.push_back(edges.back().second);
			edges.pop_back();
		}
		res += g;
		if (great.size() == 1) {
			int s = edges.back().first;
			res += s-2;
			while (!edges.empty() && edges.back().first == s) {
				if (adj[great[0]].find(edges.back().second) == adj[great[0]].end()) { 
					res += 2-1;
					break;
				}
				edges.pop_back();
			}
		} else if (great.size() == 2) {
			if (adj[great[0]].find(great[1]) == adj[great[0]].end()) {
				res += g-1;
			} else if (!edges.empty() && edges.back().first > g-2) {
				res += edges.back().first-1;
			} else {
				res += g-2;
			}
		} else {
			res += g-1;
		}
		cout << res << "\n";
	}
}	
