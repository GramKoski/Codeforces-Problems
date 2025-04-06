#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<bool> t(n);
		for (int i = 0; i < n; ++i) {
			cin >> t[i];
		}
		//BFS to find distance to n tables
		//n by n list to see if table is occupied
		//two queues, one for tables (bottom left corner of table) and another for table cell
		queue<pair<int, int>> q1;
		queue<pair<int, int>> q2;
		queue<pair<int, int>> q;
		q1.push({1, 1});
		q2.push({1, 1});
		set<int> s;
		pair<int, int> curr;
		while (!q.empty()) {
			int l = q.size();
			for (int i = 0; i < l; ++i) {
				curr = q.front();
				if (s.find(curr) != s.end()) {
					continue;
				}
				s.emplace(curr);
				if (curr.first % 3 == 1 && curr.second % 3 == 1) {
					q2.push_back(curr);
				}
				if (1 <= curr.first % 3 && 2 >= curr.first % 3 && 1 <= curr.second % 3 && 

