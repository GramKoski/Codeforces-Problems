#include <iostream>

using namespace std;

int  main() {
	int t;
	cin >> t;
	int n, m;
	while (t--) {
		int curr = 0;
		cin >> n >> m;
		string s;
		int res = 0;
		while (n--) {
			cin >> s;
			curr += s.length();
			res += 1;
			if (curr > m) {
				res -= 1;
			}
		}
		cout << res << "\n";
	}
}
