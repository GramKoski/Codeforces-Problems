#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t, n, m, L;
	int x, l, r, i, j, res, k;
	cin >> t;
	for (int _ = 0; _ < t; ++_) {
		cin >> n >> m >> L;
		vector<vector<int> > hurdle(n, vector<int>(2));
		vector<vector<int> > power(m, vector<int>(2));
		int v = 1;

		for (int i1 = 0; i1 < n; ++i1) {
			cin >> hurdle[i1][0] >> hurdle[i1][1];
		}
		for (int i1 = 0; i1 < m; ++i1) {
			cin >> power[i1][0] >> power[i1][1];
		}
		priority_queue<int> power_q;
		x = 0;
		j = 0;
		k = 1;
		i = 0;
		res = 0;
		while (i < n) {
			l = hurdle[i][0];
			r = hurdle[i][1];
			if (x > r) {
				i++;
				continue;
			}
			x = l-1;
			while(j < m && x >= power[j][0]) {
				power_q.push(power[j][1]);
				//cout << k << " " << l << " " << r << " " << power[j][1] << "\n";
				++j;
			}

			while(k < r-l+2) {
				if (power_q.size() == 0) {
					v = 0;
					break;
				}
				k += power_q.top();
				power_q.pop();
				res += 1; 
			}
			x += k;
			if (!v) {
				cout << -1 << "\n";
				break;
			}
			++i;
		}
		if (v) {
			cout << res << "\n";
		}
	}
}

		
