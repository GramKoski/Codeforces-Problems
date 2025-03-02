#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <limits>

using namespace std;

#define llu long long unsigned
const llu inf = numeric_limits<llu>::max();

struct CompareVectors {
    bool operator()(const vector<llu>& a, const vector<llu>& b) const {
        return a[0] > b[0]; // Prioritize smaller first elements
    }
};

void djikstras(vector<vector<pair<int, llu>>> graph, int start_node, vector<bool> horses, vector<llu> &distance) {
	priority_queue<vector<llu>, vector<vector<llu>>, CompareVectors> curr;
	curr.push({0, (llu)start_node, 0});

	vector<vector<llu>> dhorse(2);
	vector<llu> dh(graph.size()+1, inf);
	dhorse[0] = distance;
	dhorse[1] = dh;
	dhorse[0][start_node] = 0;
	
	vector<vector<int>> v(graph.size()+1);
	for (auto &i : v) {
		i.push_back(0);
		i.push_back(0);
	}

	while(!curr.empty()) {
		int cn = curr.top()[1];
		llu d = curr.top()[0];
		horses[cn] = horses[cn] | curr.top()[2];
		curr.pop();

		if (v[cn][horses[cn]] == true) continue;

		v[cn][horses[cn]] = true;

		for (auto &elem: graph[cn]) {
			llu ndist = d + ((horses[cn])?elem.second/2:elem.second);
			if (ndist < dhorse[horses[cn]][elem.first]) {
				dhorse[horses[cn]][elem.first] = ndist;
				curr.push({ndist, (llu)elem.first, horses[cn]});
			}
		}
	}

	for (int i = 0; i < distance.size(); ++i) {
		distance[i] = min(dhorse[0][i], dhorse[1][i]);
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, h;
		cin >> n >> m >> h;
		vector<bool> horses(n+1, false);
		for (int i = 0; i < h; ++i) {
			int a;
			cin >> a;
			horses[a] = true;
		}
		int u, v;
		llu w;
		vector< vector < pair<int, llu>>> graph(n+1);
		while (m--) {
			cin >> u >> v >> w;	
			//cout << u << " " << v << " " << w << "\n";
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});

		}
		vector<llu> Marian(n+1, inf);
		djikstras(graph, n, horses, Marian);
		vector<llu> Robin(n+1, inf);
		djikstras(graph, 1, horses, Robin);
		llu res = inf;
		for (int i = 1; i < n+1; ++i) {
			if (Marian[i] == inf || Robin[i] == inf) continue;
			res = min(res, max(Marian[i],Robin[i]));
		}
		if (res != inf) {
			cout << res << "\n";
		} else {
			cout << -1 << "\n";
		}
	}
}


