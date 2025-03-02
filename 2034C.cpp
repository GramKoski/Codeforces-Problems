#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>


using namespace std;

int main() {
	int t; cin >>t;
	while (t--) {
		int n, m;
		cin >> n >> m; string s;
		vector<string> grid;
		queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			grid.push_back(s);
		}
		
		vector<vector<vector<pair<int, int>>>> adj(n, vector<vector<pair<int, int>>>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <m; ++j) {
				if (i > 0 && grid[i-1][j] == 'D') {
					adj[i][j].push_back(make_pair(i-1, j));
				}
				if (i < n-1 && grid[i+1][j] == 'U') {
					adj[i][j].push_back(make_pair(i+1, j));
				}
				if (j > 0 && grid[i][j-1] == 'R') {
					adj[i][j].push_back(make_pair(i, j-1));
				}
				if (j < m-1 && grid[i][j+1] == 'L') {
					adj[i][j].push_back(make_pair(i, j+1));
				}
			}
		}
		int res = 0;

		//Main dfs for finding the paths which lead out
		set<pair<int, int>> v;
		for (int i = 0; i < n; ++i) {
			if (grid[i][0] == 'L') {
				q.push(make_pair(i, 0));
			}
			if (grid[i][m-1] == 'R') {
				q.push(make_pair(i, m-1));
			}
		}
		for (int j = 0; j < m; ++j) {
			if (grid[0][j] == 'U') {
				q.push(make_pair(0, j));
			}
			if (grid[n-1][j] == 'D') {
				q.push(make_pair(n-1, j));
			}
		}
		int curr_i, curr_j;
		while (!q.empty()) {
			curr_i = q.front().first;
			curr_j = q.front().second;
			if (v.find({curr_i, curr_j}) != v.end()) continue;
			res += 1; v.emplace(curr_i, curr_j);
			q.pop();
			for (auto [ni, nj] : adj[curr_i][curr_j]) {
				if (v.find({ni, nj}) != v.end()) continue;
				q.push({ni, nj});
			}
		}

		//Add ? which have neighbors all facing away
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if ((grid[i][j] == '?') 
				&& (i == 0 || v.find({i-1, j}) != v.end())
				&& (i == n-1 || v.find({i+1, j}) != v.end())
				&& (j == 0 || v.find({i, j-1}) != v.end())
				&& (j == m-1 || v.find({i, j+1}) != v.end())) {
					res += 1;
				}
			}
		}
		cout << m*n - res << "\n";
	}
}
