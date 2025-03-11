#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int a; string str;
		vector<int> lead_zeros(n, 0);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> str;
			sum += str.length(); 
			a = stoi(str);
			while (a % 10 == 0) {
				lead_zeros[i] += 1;
				a /= 10;
			}
		}
		sort(lead_zeros.begin(), lead_zeros.end());
		for (int i = n-1; i >= 0; i -= 2) {
			sum -= lead_zeros[i];
		}
		if (sum >= m+1) {
			cout << "Sasha\n";
		} else {
			cout << "Anna\n";
		}
	}
}
			


