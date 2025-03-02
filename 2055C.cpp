#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<ll> sums(n+m, 0);
		vector<vector<ll>> grid(n, vector<ll>(m));
		string path; cin >> path;
		ll a;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a;
				grid[i][j] = a;
				sums[i] += a;
				sums[n+j] +=a;
			}
		}
		//first insight: row and column-wise sum must be zero
		//Second insight: the row or column is filled besides current one depending of the next move is down or right
		int cur_x = 0;
		int cur_y = 0;
		for (int i = 0; i < m+n-2; ++i) {
			if (path[i] == 'D') {
				grid[cur_y][cur_x] = 0-sums[cur_y];
				sums[n+cur_x] += 0-sums[cur_y];
				cur_y += 1;
			} else {
				grid[cur_y][cur_x] = 0-sums[n+cur_x];
				sums[cur_y] += 0-sums[n+cur_x];
				cur_x += 1;
			}
		}
		grid[n-1][m-1] = 0-sums[cur_y];
		for (auto row : grid) {
			for (auto col : row) {
				cout << col << " ";
			}
			cout << "\n";
		}
	}
}
