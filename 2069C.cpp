#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t; 
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		int start = -1;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 1) {
				start = i;
				break;
			}
		}
		if (start == -1) {
			cout << 0 << "\n";
		} else {
			vector<pair<int, ll>> val;
			ll curr = 1;
			for (int i = start; i < n; ++i) {
				if (a[i] == 2) {
					curr *= 2;
				} else if (a[i] == 3) {
					val.push_back({i, curr-1});
				}
			}
			if (val.size() == 0) {
				cout << 0 << "\n";
			} else {
				ll res = 0;
				for (auto e : val) res += e.second;
				int curr_i = start;
				int curr_3 = 0;
				ll curr_sum = res + val.size();
				ll num_twos = 0;
				for (int i = curr_i+1; i < n; ++i) {
					if (i == val[curr_3].first) {
						curr_sum -= val[curr_3].second + 1;
						curr_3 += 1;
						if (curr_3 >= val.size()) break;
					}
					if (a[i] == 2) {
						num_twos += 1;
					}
					if (a[i] == 1) {
						curr_sum >>= num_twos*(val.size() - curr_3);
						res += curr_sum-1;
						cout << i << " " << curr_sum << " " << res << "\n";
						num_twos = 0;
					}
				}
				cout << res << "\n";
			}
		}
	}
}
						
