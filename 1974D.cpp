#include <vector>
#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> path(n);
		vector<int> count(4, 0);
		string a; cin >> a;
		int curr; string res = "";
		for (int i = 0; i < n; ++i) {
			if (a[i] == 'N') {
				curr = 0;
			} else if (a[i] == 'S') {
				curr = 1;
			} else if (a[i] == 'E') {
				curr = 2;
			} else {
				curr = 3;
			}
			count[curr] += 1;
			path[i] = curr;
			if (count[curr] %2) {
				res += (curr == 0 || curr == 1) ? 'H' : 'R';
			} else {
				res += (curr == 0 || curr == 1) ? 'R' : 'H';
			}
		}
		//cout << count[0] << " " << count[1] << " " << count[2] << " " << count[3] << "\n";
		bool valid = true;
		if (count[0]%2 != count[1]%2 || count[2]%2 != count[3]%2 
			|| (count[0] == 1 && count[1] == 1 && count[2] == 0 && count[3] == 0)
			|| (count[0] == 0 && count[1] == 0 && count[2] == 1 && count[3] == 1 )) {
			valid = false;
			cout << "NO\n";
		}
		if (valid) {
			cout << res << "\n";
		}
	}
}
		
