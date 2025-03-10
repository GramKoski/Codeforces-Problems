#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		set<int> s;
		int a;
		for (int i =0; i < n; ++i) {
			cin >> a;
			s.emplace(a);
		}
		int i = 0;
		for (i = 1; i <= n+1; ++i) {
			if (s.find(i) == s.end()) {
				break;
			}
		}
		//cout << i << " " << s.size() << "\n";
		if (i <= s.size()) {
			if (i%2) {
				cout << "Alice\n";
			} else {
				cout << "Bob\n";
			}
		} else {
			if (i%2) {
				cout << "Bob\n";
			} else {
				cout << "Alice\n";
			}
		}
	}
}

