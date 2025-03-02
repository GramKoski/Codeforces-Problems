#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int t, n, d, k;
	cin >> t;
	while (t--) {
		cin >> n >> d >> k;
		int l, r;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		while (k--) {
			cin >> l >> r;
			q.push({l, r});
		}
		priority_queue<int, vector<int>, greater<int>> curr;
		vector<int> finished(n+1, 0);
		int m,  min, max;
		m = 0;
		min = 1e9;
		max = 0;
		int mstart = -1;
		int bstart = -1;
		for (int i = 0; i < n+1; ++i) {
			while (!q.empty() && q.top().first == i) {
				curr.push(q.top().second);
				q.pop();
				m += 1;
			}
			if (i >= d) {
				m -= finished[i-d];
				//cout << i << " " << m << "\n";
				if (m > max) {
					max = m;
					bstart = i - d + 1;
				} 
				if (m < min) {
					min = m;
					mstart = i - d + 1;
				}
			}
			while (!curr.empty() && curr.top() == i) {

				curr.pop();
				finished[i] += 1;
			}
		}

		cout << bstart << " " <<  mstart << "\n";
	}
}
