#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(vector<int> arr1, vector<int> arr2) {
	int m = 0;
	for (int i = 0; i < 26; ++i) {
		m = max(m, arr1[i] + arr2[i]);
	}
	return m;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		//count each character by it's frequency
		if (n % 2 == 0) {
			int maxCE = 0;
			int maxCO = 0;
			vector<int> freqO(26, 0);
			vector<int> freqE(26, 0);
			for (int i = 0; i < n; ++i) {
				if (i%2 == 0) {
					freqE[s[i] - 'a'] += 1;
					maxCE = max(freqE[s[i]-'a'], maxCE);
				} else {
					freqO[s[i] - 'a'] += 1;
					maxCO = max(freqO[s[i]-'a'], maxCO);
				}
			}
			cout << n-maxCE-maxCO << "\n";

		} else {
			vector<int> empty(26, 0);
			vector<vector<vector<int>>> freq(2, vector<vector<int>>(n, vector<int>(26, 0)));
			//cout << "here\n";
			freq[0][0][s[0]-'a'] = 1;
			if (n > 1) {
				freq[0][1][s[1]-'a'] = 1;
			}
			//cout << "here\n";
			for (int i = 2; i < n; ++i) {
				freq[0][i] = (freq[0][i-2]);
				freq[0][i][s[i] - 'a'] += 1;
			}
			//cout << "here\n";
			if (n > 1) {
				freq[1][n-2][s[n-2]-'a'] = 1;
			}
			//cout << "here\n";
			freq[1][n-1][s[n-1]-'a'] = 1;
			for (int i = n-3; i >= 0; --i) {
				freq[1][i] = freq[1][i+2];
				freq[1][i][s[i] - 'a'] += 1;
			}
			int m = 1e9;
			//cout << "here\n";
			for (int i = 0; i < n; ++i) {
				vector<int> pre2 = (i > 1) ? freq[0][i-2] : empty;
				vector<int> post1 = (i < n-1) ? freq[1][i+1] : empty;
				vector<int> pre1 = (i > 0) ? freq[0][i-1] : empty;
				vector<int> post2 = (i < n-2) ? freq[1][i+2] : empty;

				m = min(m, n-1-find_max(pre2, post1)-find_max(pre1, post2));

			}
			cout << 1+m << "\n";
		}
	}
}
