#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, a;
		string s;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> a;
			arr[i] = a;
		}
		cin >> m;
		while (m--) {
			cin >> s;
			if (s.size() != n) {
				cout << "NO\n";
				continue;
			}
			unordered_map<int, char> template_map;
			unordered_map<char, int> char_map;
			bool valid = true;
			for (int i = 0; i < n; ++i) {
				if (char_map.find(s[i]) == char_map.end()) {
					char_map[s[i]] = arr[i];
					if (template_map.find(arr[i]) != template_map.end()) {
						valid = false;
						break;
					}
					template_map[arr[i]] = s[i];
				} else {
					if (char_map[s[i]] != arr[i] || template_map[arr[i]] != s[i]) {
						valid = false;
						break;
					}
				}
			}
			if (valid) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}

