#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; string s;
		cin >> n >> s;
		int res = 1e9;	
		for (int i = 0; i < n-1; ++i) {
			//Find min with constant i
			int sum = 0;
			bool has_zero = false;
			for (int j = 0; j <= i-1; ++j) {
				if (s[j]-'0' == 0) {
					sum = 0; has_zero = true;
					break;
				} else if (s[j]-'0' > 1) {
					sum += (s[j]-'0');
				}
			}
			if (i > 0 && sum == 0 && has_zero) {
				res = 0;
				break;
			}
			int curr = stoi(s.substr(i, 2));
			if (curr == 0) {
				sum = 0; has_zero = true;
			} else if (curr > 1) {
				sum += curr;
			}
			if (sum == 0 && has_zero) {
				res = 0;
				break;
			}
			for (int j = i+2; j < n; ++j) {
				if (s[j]-'0' == 0) {
					sum = 0; has_zero = true;
					break;
				} else if (s[j]-'0' > 1) {
					sum += s[j]-'0';
				}
			}
			if (!has_zero && sum == 0) {
				sum = 1;
			}
			//cout << "i = " << i << " " << sum << "\n";
			res = min(res, sum);
		}
		cout << res << "\n";
	}
}

