#include <iostream>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t; 
	while (t--) {
		ll n, m; cin >> n >> m;
		ll max_mex = 0; int li;
		for (int i = 0; i < n; ++i) {
			int l; cin >> l;
			priority_queue<int, vector<int>, greater<int>> q;
			for (int j = 0; j < l; ++j) {
				cin >> li;
				q.push(li);
			}
			ll curr = 0; int holes = 0;
			int prev = -1;
			while (!q.empty()) {
				if (q.top() != curr) {
					if (holes == 1) {
						break;
					} else {
						holes++;
					}
				} else {
					prev = q.top();
					while (!q.empty() && q.top() == prev) q.pop();
				}
				curr++;
			}
			if (holes == 0) curr += 1;
			max_mex = max(curr, max_mex);
		}
		//Calculating the values which start greater than mex
		ll g = m*(m+1)/2-(max_mex)*(max_mex+1)/2;
		cout << max_mex*min(max_mex+1, m+1)+((g > 0) ? g : 0) << "\n";
	}
}
