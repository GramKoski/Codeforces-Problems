#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int _ = 0; _ < t; ++_) {
		string s;
		int q;
		cin >> s;
		cin >> q;
		unordered_set<int> valid;
		string substring = "xxxx";
		//cout << s.size() << "\n";
		int length = s.size();
		for (int k = 0; k <= length-4; ++k) {
			//Take substring
			substring = s.substr(k, 4);
			//cout << substring << " " << k << " " << s.size()-4 << "\n";

			if (substring.compare("1100") == 0) {
				valid.insert(k+1);
			}

		}
		for (int j = 0; j < q; ++j) {
			int i, v;
			cin >> i >> v;
			if (v == 0) {
				s[i-1] = '0';
			} else {
				s[i-1] = '1';
			}

			for (int u = -3; u < 1; ++u) {
				if (i+u < 1 || i+u+3 > length) {
					continue;
				}
				if (s.substr(i-1+u, 4).compare("1100") == 0) {
					valid.insert(i+u);
				} else {
					if (valid.find(i+u) != valid.end()) {
						valid.erase(i+u);
					}
				}
			}
			if (valid.size() == 0) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		}
	}
}

				


