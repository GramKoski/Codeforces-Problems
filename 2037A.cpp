#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
	int t, n, u, res;
	cin >> t;
	unordered_set<int> nums;
	for (int i = 0; i < t; ++i) {
		nums.clear();
		res = 0;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >>  u;
		    if (nums.find(u) != nums.end()) {
				res += 1;
				nums.erase(u);
			} else {
				nums.insert(u);
			}
		} 
		cout << res << "\n";
	}
}
