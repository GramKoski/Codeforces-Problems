#include <iostream>
#include <queue>
#include <algorithm>

#define llu long long unsigned

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k, a;
		cin >> n >> k;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> events;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			events.push({a, 0});
		}
		for (int i = 0; i < n; ++i) {
			cin >> a;
			events.push({a, 1});
		}
		int br = 0; llu buying = n; llu maxProf = 0; int currb = 0; int curra = 0; int last = 0; llu p = 0;
		while (!events.empty()) {
			p = events.top().first;
			a = events.top().second;
			events.pop();
			if (p > last) {
				br += curra;
				buying -= currb;
				br -= currb;
				curra = currb = 0;
			}
			if (br <= k) {
				maxProf = max(maxProf, buying*p);
			}
			//cout << "p = " << p << " e = " << a << " buying = " << buying << " badr = " << br << "\n";
			if (a == 0) {
				curra += 1;
			} else {
				currb += 1;
			}
			p = last;
		}
		cout << maxProf << "\n";
	}
}
