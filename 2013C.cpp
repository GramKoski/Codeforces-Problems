#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		bool suf = false;
		string res = "";
		int response;
		while (res.length() < n) {
			if (!suf) {
				res += "0";
			} else {
				res = "0" + res;
			}
			cout << "? " << res << "\n"; cout.flush();
			cin >> response;
			if (response == 0) {
				if (suf) {
					res[0] = '1';
				} else {
					res[res.length()-1] = '1';
				}
				if (!suf) {
					cout << "? " << res << "\n"; cout.flush();
					cin >> response;
					if (response == 0) {
						if (!suf) {
							res = res.substr(0, res.length()-1);
							suf = true;
						}
					}
				}
			}
		}
		cout << "! " << res << "\n"; cout.flush();
	}
}
