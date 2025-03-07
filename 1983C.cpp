#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> a(3, vector<int>(n));
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 1; j < n; ++j) {
				a[i][j] += a[i][j-1];
			}
		}
		int req = (a[0][n-1]+2)/3;
		//Run the greedy algo once normal and once in reverse to avoid the problem of equal size sections and know which list to get rid of. If this happens going one direction (ie the first section in the forward direction
		//it will be seen which section will minimize the other intervals if it is run in reverse
		//Alternatively, I could just run the algo for each interval that there is a tie. This might actually a clearer way to handle this edge case
		vector<vector<int>> secs(3, vector<int>(3, 0));
		int r1 = 0; int r2 = 0;
		int r1_div = -1;
		//Find r1
		bool r1_found = false; bool r2_found = false;
		int num_r1 = 0;
		while (num_r1 == 0 && r1 < n) {
			for (int i = 0; i < 3; ++i) {
				if (a[i][r1] >= req) {
					num_r1 += 1;
					r1_div = i;
					r1_found = true;
				}
				secs[i][0] = a[i][r1];
			}
			if (num_r1 > 0) break;
			r1++;
		}
		if (r1_found) {
			//Find r1
			r2 = r1;
			while (!r2_found && r2 < n) {
				for (int i = 0; i < 3; ++i) {
					if ((num_r1 > 1 || i != r1_div) && a[i][r2] - a[i][r1] >= req) {
						r2_found = true;
					}
					secs[i][1] = a[i][r2] - a[i][r1];
				}
				if (r2_found) break;
				r2++;
			}
		}
		if (r2_found) {
			for (int i = 0; i < 3; ++i) {
				secs[i][2] = a[i][n-1]-a[i][r2];
			}
		}
		/*for (auto r : secs) {
			for (auto c : r) {
				cout << c << " ";
			}
			cout << "\n";
		}
		*/
		if (!r1_found || !r2_found) {
			cout << -1 << "\n";
		} else {
			//must find intervals that work
			vector<int> res(3); bool valid = false;
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					for (int k = 0; k < 3; ++k) {
						if ( secs[0][i] >= req && secs[1][j] >= req && secs[2][k] >= req && i != j && j != k && k != i) {
							res[0] = i;
							res[1] = j;
							res[2] = k;
							valid = true;
							break;
						}
					}
					if (valid) break;
				}
				if (valid) break;
			}

			if (!valid) {
				cout << -1 << "\n";
			} else {
				if (res[0] == 0) cout << 1 << " " << r1+1 << " ";
				if (res[0] == 1) cout << r1+2 << " " << r2+1 << " ";
				if (res[0] == 2) cout << r2+2 << " " << n << " ";
				if (res[1] == 0) cout << 1 << " " << r1+1 << " ";
				if (res[1] == 1) cout << r1+2 << " " << r2+1 << " ";
				if (res[1] == 2) cout << r2+2 << " " << n << " ";
				if (res[2] == 0) cout << 1 << " " << r1+1;
				if (res[2] == 1) cout << r1+2 << " " << r2+1;
				if (res[2] == 2) cout << r2+2 << " " << n;
				cout << "\n";
			}
		}
	}
}

