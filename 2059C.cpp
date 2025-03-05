#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> a(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}
		//Postfix sum
		vector<int> count(n, 0);
		vector<vector<bool>> valid(n, vector<bool>(n));
		for (int i = 0; i < n; ++i) {
			 if (a[i][n-1] == 1) {
				 valid[i][0] = true;
				 count[0] += 1;
			 }
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < n; ++j) {
				if (a[i][n-1-j] == 1 && valid[i][j-1]) {
					count[j] += 1;
					valid[i][j] = true;
				}
			}
		}
		int res = 0;
		for (int j = n-2; j >= 0; --j) {
			if (count[j] > res) {
				//cout << j << "\n";
				res += 1;
			} else {
				res = count[j];
			}
		}
		res += 1;
		cout << res << "\n";
	}
}
