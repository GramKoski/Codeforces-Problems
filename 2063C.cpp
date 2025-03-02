#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> adj(n+1, vector<int>);
		int u, v;
		for (int i = 0; i < n; ++i) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<pair<int, int>> edges;
		for (int i = 1; i <= n; ++i) {
			if (adj[i].size() > 0) {
				edges.push_back(adj[i].size(), i);
			}
		}
		sort(edges.begin(), edges.end());
		int res = 0;
		//Take top element of map with most edges
		v = edges.back().second;
		res += edges.back().first;
		edges.pop_back();
		//Decrease adjacent vertices by 1
		v = edges.back



