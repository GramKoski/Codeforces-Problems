#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<bool> t(n);
		for (int i = 0; i < n; ++i) {
			cin >> t[i];
		}
		queue<pair<int, int>> q1;
		queue<pair<int, int>> q2;
		q1.insert({1, 1});
		q2.insert({1, 1});
		set<pair<int, int>> v;
		vector<pair<int, int>> m(n);
		for (int i = 0; i < n; ++i) {
			if (t[i] == false) {
				pair<int, int> curr = q.front();
				q1.pop();
				while (v.find(curr) != v.end()) {
					curr = q.front();
					q1.pop();
				}
				v.insert(curr);
				if (curr.first % 3 == 1 && curr.second % 3 == 1) {
					q1.insert({curr.first, curr.second + 1});
				} else if (curr.first % 3 == 2 && curr.second % 3 == 1) {
					q1.insert({curr.first-1, curr.second + 1});
				} else if (curr.first % 2 == 1 && curr.second % 3 == 2) {
					curr
