#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string a, b, c;
		cin >> a >> b >> c;
		vector<int> prev(size(b)+2, 0);
		vector<int> curr(size(b)+2);
		curr[size(b)+1] = 0;
		for (int i = size(a); i >= 0; --i) {
			for (int j = size(b); j >= 0; --j) {
				if (i + j >= size(c)) {
					curr[j] = 0;
					continue;
				}
				curr[j] = min((i < size(a)) ? (a[i] != c[i+j]) + prev[j] : (b[j] != c[i+j]) + curr[j+1], (j < size(b)) ? (b[j] != c[i+j]) + curr[j+1] : (a[i] != c[i+j]) + prev[j]);
			}
			prev = curr;
		}
		cout << curr[0] << "\n";
	}
}

