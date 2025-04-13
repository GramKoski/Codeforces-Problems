#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
	int n; string s; int q;
	cin >> n >> s >> q;
	map<int, set<int>> m;
	for (int i = 0; i < 26; ++i) {
		m[i] = {i};
	}
	vector<vector<int>> freq(26);
	for (int i = 0; i < n; ++i) {
		freq[s[i]-97].push_back(i);
	}
	char c, d;
	for (int i = 0; i < q; ++i) {
		cin >> c >> d;

		for (auto car : m[c-97]) {
			m[d-97].emplace(car);
		}
		m[c-97].clear();
	}
/*
	cout << "\n";
	for (int i = 0; i < 26; ++i) {
		cout << char(i + 97) << " ";
		for (auto car : m[i]) {
			cout << char(car+97);
		}
		cout << "\n";
	}
*/

	for (int i = 0; i < 26; ++i) {
		for (auto car : m[i]) {
			for (auto e : freq[car]) {
				s[e] = (char)(i+97);
			}
		}
	}
	cout << s << "\n";
}
