#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<string> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<vector<bool>> row_valid(n, vector<bool>(m, true));
		vector<vector<bool>> col_valid(n, vector<bool>(m, true));
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				if (!row_valid[i][j-1] || a[i][j-1] == '0') {
					row_valid[i][j] = false;
				}
			}
		}
		for (int j = 0; j < m; ++j) {
			for (int i = 1; i < n; ++i) {
				if (!col_valid[i-1][j] || a[i-1][j] == '0') {
					col_valid[i][j] = false;
				}
			}
		}

		bool valid = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == '1') {
					if (!row_valid[i][j] && !col_valid[i][j]) {
						valid = false;
					}
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


