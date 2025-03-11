#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s;
		unordered_map<char, vector<int>> v;
		int n; cin >> n;
		char t; cin >> t;
		v[t] = {};
		for (int i = 0; i < 2*n; ++i) {
			cin >> s;
			if (v.find(s[1]) == v.end()) {
				v[s[1]] = {s[0] - '0'};
			} else {
				v[s[1]].push_back(s[0] - '0');
			}
		}
		for (auto  &c : v) {
			sort(c.second.begin(), c.second.end());
			//for (auto i : c.second) cout << i << " ";
		}
		int rest = 0;
		for (auto k : v) {
			if (k.first != t) {
				rest += k.second.size()%2;
			}
		}
		//cout << (int)v[t].size() - rest << "\n";
		if ((int)v[t].size() - rest >= 0 && ((int)v[t].size()-rest)%2 == 0) {
			int odd = 0;
			for (auto c : v) {
				if (c.first == t) continue;
				/*
				cout << "c = " << c.first << "\n"; 
				for (auto k : c.second) {
					cout << k << " ";
				}
				cout << "\n";
				*/
				for (int i = 0; i < c.second.size()/2 * 2; i += 2) {
					cout << c.second[i] << c.first << " " << c.second[i+1] << c.first << "\n";
				}
				if (c.second.size()%2) {
					cout << c.second.back() << c.first << " " << v[t][odd] << t << "\n";
					odd += 1;
				}
			}
			for (int i = odd; i < v[t].size(); i += 2) {
				cout << v[t][i] <<  t << " " << v[t][i+1] << t << "\n";
			}
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
}
