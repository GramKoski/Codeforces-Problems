#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<string> nodes(n); vector<int> pre(n); vector<int> post(n);
		pre[0] = -1;
		string prev; cin >> prev;
		nodes[0] = prev;
		for (int i = 1; i < n; ++i) {
			cin >> nodes[i];
			if (nodes[i] == prev || (nodes[i][0] != prev[0] && nodes[i][1] != prev[1] && nodes[i][1] != prev[0] && nodes[i][0] != prev[1])) {
				pre[i] = pre[i-1];
			} else {
				pre[i] = i-1;
			}
			prev = nodes[i];
		}
		post[n-1] = n;
		for (int i = n-2; i >= 0; --i) {
			if (nodes[i] == nodes[i+1] || (nodes[i][0] != nodes[i+1][0] && nodes[i][1] != nodes[i+1][1] && nodes[i][0] != nodes[i+1][1] && nodes[i][1] != nodes[i+1][0])) {
				post[i] = post[i+1];
			} else {
				post[i] = i+1;
			}
		}
		//for (auto i : pre) cout << i << " "; cout << "\n";
		//for (auto i : post) cout << i << " "; cout << "\n";

		int x, y, z;
		while (q--) {
			cin >> x >> y;
			x-=1;y-=1;
			if (x > y) {
				int temp = x; x = y; y = temp;
			}
			//cout << x << " " << y << " " << nodes[x] << " " << nodes[y] << "\n";
			if (nodes[x] == nodes[y]) {
				cout << y-x << "\n";
				continue;
			}
			if (post[x] == n && pre[x] == -1) {
				cout << -1 << "\n";
			} else if (post[x] == n) { 
				z = pre[x];
				cout << x-z + y-z << "\n";
			} else if (pre[x] == -1) {
				z = post[x];
				if (z <= y) {
					cout << y-x << "\n";
				} else {
					cout << z-x + z-y << "\n";
				}
			} else {
				if (post[x] < y) {
					cout << y-x << "\n";
				} else {
					cout << min(x-pre[x] + y-pre[x], post[x]-x + post[x]-y) << "\n";
				}
			}
		}
	}
}
			
