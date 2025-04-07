#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> t(n);
		for (int i = 0; i < n; ++i) {
			cin >> t[i];
		}
		//BFS to find distance to n tables
		//n by n list to see if table is occupied
		//two queues, one for tables (bottom left corner of table) and another for table cell
		queue<pair<int, int>> q1;
		queue<pair<int, int>> q2;
		queue<pair<int, int>> q;
		q.push({0, 0});
		set<pair<int, int>> s;
		pair<int, int> curr;
		while (!q.empty() && q2.size() < n) {
			int l = q.size();
			for (int i = 0; i < l; ++i) {
				curr = q.front(); q.pop();
				//cout << curr.first << " " << curr.second << "\n";
				if (s.find(curr) != s.end()) continue; 
				s.emplace(curr);
				if (curr.first % 3 == 1 && curr.second % 3 == 1) {
					q2.push(curr);
				}
				if (1 <= curr.first % 3 && 1 <= curr.second % 3) {
					q1.push(curr);
				} else {
					for (int x = -1; x < 2; ++x) {
						if (x == 0 && curr.second > 0) {
							pair<int, int> below = {curr.first, curr.second -1};
							if (s.find(below) == s.end()) q.push(below);
						}
						pair<int, int> n = {curr.first + x, curr.second + ((x == 0) ? 1 : 0)};
						if (s.find(n) == s.end() && curr.first +x >= 0) {
							q.push(n);
						} 

					}
				}
			}
		}
		set<pair<int, int>> v;
		for (int i = 0; i < n; ++i) {
			if (t[i] == 1) {
				while (v.find(q1.front()) != v.end()) {
					q1.pop();
				}
				cout << q1.front().first << " " << q1.front().second << "\n";
				if (q1.front() == q2.front()) {
					q2.pop();
				}
				v.emplace(q1.front());
				q1.pop();
			} else {
				cout << q2.front().first << " " << q2.front().second << "\n";
				v.emplace(q2.front());
				q2.pop();
			}
		}
		//cout << "\n";
	}
}

			
