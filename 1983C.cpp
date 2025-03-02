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
		set<int> second_row;
		int p1, p2, p3;
		int l1, l2;
		l1 = 0;
		l2 = 0;
		bool valid_first = false;
		while (l1 < n) {
			for (int i = 0; i < 3; ++i) {
				if (a[i][l1] >= req) {
					second_row.insert(i);
					valid_first = true;
				}
			}
			if (valid_first) break;
			l1+= 1;
		}
		bool valid_second=false;
		if (valid_first) {
			while (l2 < n) {
				for (int i = 0; i < 3; ++i) {
					if (a[i][l2] - a[i][l1-1] >= req && (second_row.size() > 1 || second_row.find(i) == second_row.end())) {
						valid_second = true;
						p2 = i;
						break;
					}
				}
				if (valid_second) break;
				l2 += 1;
			}
		}
		if (!valid_first || !valid_second || l2 >= n-1) {
			cout << -1 << "\n";
		} else {
			if (second_row.find(p2) != second_row.end()) {
				second_row.erase(p2);
			}
			if (second_row.size() == 2) {
				p1 = -1;
				for (auto i : second_row) {
					if (p1 == -1) {
						p1 = i;
					} else {
						p3 = i;
					}
				}
			} else {
				p1 = -1;
				for (auto i : {0, 1, 2}) {
					if (i != p2) {
						if (p1 == -1) {
							p1 = i;
						} else {
							p3 = i;
						}
					}
				}
			}
			if (a[p3][n-1] - a[p3][l2] < req) {
				cout << -1 << "\n";	
			} else {
				vector<pair<int, int>> res(3);
				res[p1] = {0, p1};
				res[p2] = {p1+1, p2};
				res[p3] = {p2+1, n-1};
				for (auto r : res) {
					cout << r.first << " " << r.second << " ";
				}
				cout << "\n";
			}
		}
	}
}

