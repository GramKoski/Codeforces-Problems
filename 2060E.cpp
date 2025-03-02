#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


int main() {
	int t; cin >> t;
	while (t--) {
		int n, m1, m2; cin >> n >> m1 >> m2;
		unordered_map<int, unordered_set<int>> f_adj;
		unordered_map<int, unordered_set<int>> g_adj;
		vector<int> g(n+1, 0);
		
		//This problem is all about connected components
		int u, v;
		for (int i = 0; i < m1; ++i) {
			cin >> u >> v;
			f_adj[u].insert(v);
			f_adj[v].insert(u);
		}
		for (int i = 0; i < m2; ++i) {
			cin >> u >> v;
			g_adj[u].insert(v);
			g_adj[v].insert(u);
		}
		unordered_set<int> visited_g;
		int index_g = 0; int curr;
		queue<int> q;
		for (int i = 1; i <= n; ++i) {
			if (visited_g.find(i) != visited_g.end()) {
				continue;
			}
			index_g += 1;
			q.push(i);
			while (!q.empty()) {
				int size = q.size();
				for (int j = 0; j < size; ++j) {
					curr = q.front(); g[curr] = index_g;
					visited_g.insert(curr);
					q.pop();
					if (g_adj.find(curr) == g_adj.end()) continue;
					for (auto neighbor : g_adj[curr]) {
						if (visited_g.find(neighbor) == visited_g.end()) q.push(neighbor);
					}
				}
			}
		}
		//cout << "here\n";
		int res = 0;
		unordered_map<int, unordered_set<int>> f_adj_edit;
		for (int i = 1; i <= n; ++i) {
			if (f_adj.find(i) == f_adj.end()) continue;
			for (auto neighbor : f_adj[i]) {
				if (g[i] == g[neighbor]) {
					//cout << "i = " << i << " neighbor = " << neighbor << " g[i] = " << g[i] << " g[n] = " << g[neighbor] << "\n";
					f_adj_edit[i].insert(neighbor);
				} else {
					res += 1;
				}
			}
		}
		res /= 2;
		int index_f = 0;
		unordered_set<int> visited_f;
		for (int i = 1; i <= n; ++i) {
			if (visited_f.find(i) != visited_f.end()) continue;
			index_f += 1;
			q.push(i);
			while (!q.empty()) {
				curr = q.front();
				visited_f.insert(curr);
				q.pop();
				if (f_adj_edit.find(curr) == f_adj_edit.end()) continue;
				for (auto neighbor : f_adj_edit[curr]) {
					if (visited_f.find(neighbor) == visited_f.end()) q.push(neighbor);
				}
			}
		}
		/*
		cout << "comps = " << index_f-index_g << "\n";
		cout << "g\n";
		for (auto i : g) {
			cout << i << " ";
		}
		cout << "\nf\n";
		for (auto edge : f_adj_edit) {
			cout << edge.first << " ";
			for (auto u : edge.second) {
				cout << u << " ";
			}
			cout << "\n";
		}
		*/
		res += index_f-index_g;
		cout << res << "\n";
	}
}



