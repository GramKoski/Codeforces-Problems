#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int res = n;
		//Note that the length of the substring must devide n
		//But the number of devisors will be low enough to go through each one
		for (int i = 1; i <= n/2; ++i) {
			if (n%i == 0) {
				int pre_num = 0;
				int post_num = 0;
				string pre = s.substr(0, i);
				string post = s.substr(n-i, i);
				for (int j = 0; j < n; ++j) {
					if (s[j] != pre[j%i]) {
						pre_num += 1;
					}
					if (s[j] != post[j%i]) {
						post_num += 1;
					}
				}
				if (n%i == 0 && (post_num <= 1 || pre_num <= 1)) {
					res = i;
					break;
				}
			}
		}
		cout << res << "\n";
	}
}

