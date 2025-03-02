#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, a, b; cin >> n >> a >> b;
		int g = gcd(a, b);
		vector<int> nums(n); vector<int> congruence(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
			congruence[i] = nums[i] % g;
		}
		sort(congruence.begin(), congruence.end());
		int minDif = congruence[n-1] - congruence[0];
		for (int i = 1; i < n; ++i) {
			minDif = min(minDif, congruence[i-1]+g - congruence[i]);
		}
		cout << minDif << "\n";
	}
}
