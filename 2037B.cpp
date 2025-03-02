#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int t, k, u, m, n;
	cin >> t;
	unordered_map<int, int> nums;
	for (int _ = 0; _ < t; _++) {
		cin >> k;
		nums.clear();
		for (int i = 0; i < k; ++i) {
			cin >> u;
			if (nums.find(u) == nums.end()) {
				nums[u] = 1;
			} else {
				nums[u] += 1;
			}
		}
		k -= 2;
		//2 integers n and m
		for (m = 0; m <= k/2 +1; ++m) {
			if (nums.find(m) == nums.end()) {
				continue;
			}
			n = k/m;
			if ((k%m == 0 && n != m && nums.find(n) != nums.end()) || (k%m ==0 && n ==m && nums[m] > 1)) {
				cout << m << " " << n << "\n";
				break;
			}
		}
	}
}
