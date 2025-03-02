#include <vector>
#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll h, n; cin >> h >> n;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
		vector<int> a(n);
		for (int i =0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> c(n);
		for (int i = 0; i < n; ++i) {
			cin >> c[i];
		}
		pair<ll, int> curr;
		for (int i = 0; i < n; ++i) {
			curr = {1, i};
			q.push(curr);
		}
		ll top_time = 0;
		while (!q.empty()) {
			top_time = q.top().first;
			//cout << top_time << "\n";
			while (q.top().first == top_time) {
				h -= a[q.top().second];
				q.push({top_time+c[q.top().second], q.top().second});
				q.pop();
			}
			if (h <= 0) break;
		}
		cout << top_time << "\n";
	}
}
