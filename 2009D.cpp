#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int x, y;
		vector<int> count_x(n+1, 0);
		vector<int> count_y(2, 0);
		vector<vector<bool>> points(n+1, vector<bool>(2, false));
		vector<pair<int, int>> coords(n);
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			points[x][y] = true;
			coords[i] = {x, y};
			count_x[x] += 1;
			count_y[y] += 1;
		}
		ll res = 0;
		for (auto p : coords) {
			res += (count_x[p.first]-1)*(count_y[p.second]-1);
			if (p.first > 0 && p.first < n && points[p.first-1][(p.second == 0) ? 1 : 0] && points[p.first+1][(p.second==0)?1:0]) {
				res += 1;
			}
		}
		cout << res << "\n";
	}
}
	
