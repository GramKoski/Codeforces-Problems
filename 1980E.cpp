#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define ll long long


using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int a;
		vector<pair<int, int>> old(m*n+1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a;
				old[a] = {i, j};
			}
		}
		vector<vector<int>> b(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> b[i][j];
			}
		}
		int r, c; bool valid = true;
		for (int i = 0; i < n; ++i) {
			r = old[b[i][0]].first;
			for (int j = 0; j < m; ++j) {
				if (old[b[i][j]].first	!= r) {
					valid = false;
					break;
				}
			}
		}
		for (int j = 0; j < m; ++j) {
			c = old[b[0][j]].second;
			for (int i = 0; i < n; ++i) {
				if (old[b[i][j]].second != c) {
					valid = false;
					break;
				}
			}
		}
		if (valid) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}



			 
