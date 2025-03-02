#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;
		int b, c;
		vector<int> bottles(k, 0);
		for (int j = 0; j < k; ++j) {
			cin >> b >> c;
			bottles[b-1] += c;
		}

		sort(bottles.rbegin(), bottles.rend());

		int sum = 0;
		for (int j = 0; j < min(n, k); ++j) {
			sum += bottles[j];
		}
		cout << sum << "\n";
	}
}


