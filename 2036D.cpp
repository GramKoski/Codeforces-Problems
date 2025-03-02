#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int shift(vector<int>& prev, int curr) {
	prev[3] = prev[2];
	prev[2] = prev[1];
	prev[1] = prev[0];
	prev[0] = curr;
	//cout << prev[0] << prev[1] << prev[2] << prev[3] << "\n";
	return prev[3] == 1 && prev[2] == 5 && prev[1] == 4 && prev[0] == 3;
}
int main() {
	int t;
	cin >> t;

	for (int _ = 0; _ < t; ++_) {
		int n, m;
		cin >> n >> m;
		int res = 0;
		vector<vector<int> >layers(n);
		for (int i = 0; i < n; ++i) {
			string num;
			int j = 0;
			int digits;
			cin >> num;
			for (; j < m; ++j) {
				digits = (int)(num[j]-'0');
				layers[i].push_back(digits);
			}
			//reverse(layers[i].begin(), layers[i].end());
		}
		int i, j;
		//traverse matrix in a spiral
		int spirals = min(n/2, m/2);
		//cout << spirals << "\n";
		for (int s = 0; s < spirals; ++s) {
			vector<int> prev(4, 0);
			int iters = 0;
			while (1) {
				j = s;
				i = s;
				for (j = s; j < m-s; ++j) {
					if (iters > 3) {
						break;
					}
					//cout << i << " " << j << " " << layers[i][j] << "\n";
					if (shift(prev, layers[i][j])) {
						res += 1;
					}
					iters = (iters > 0) ? iters + 1 : 0;
				}
				j -= 1;
				if (iters > 3) {
					break;
				}
				for (i = s+1;i<n-s;++i) {
					if (iters > 3) {break;}
					//cout << i << " " << j << " " << layers[i][j] << "\n";
					if (shift(prev, layers[i][j])) {
						res += 1;
					}
					iters = (iters > 0) ? iters + 1 : 0;
				}
				i -= 1;
				j -= 1;
				if (iters > 3) {break;}
				for (;j >= s; j -= 1) {
					if (iters > 3) {break;}
					//cout << i << " " << j << " " << layers[i][j] << "\n";
					if (shift(prev, layers[i][j])) {
						res += 1;
					}

				}
				j += 1;
				i -= 1; 

				if (iters > 3) {break;}
				for (;i >= s+1; i -= 1) {
					if (iters > 3) {break;}
					//cout << i << " " << j << " " << layers[i][j] << "\n";
					if (shift(prev, layers[i][j])) {
						res += 1;
					}
				}
				j += 1;
				if (iters > 3) {break;}
				iters++;
			}

		}
		cout << res << "\n";
	}
}



