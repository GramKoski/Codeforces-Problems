#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long

int main() {
	int t, a, n;
	cin >> t;

	while (t--) {
		unordered_map<int, int> cycles;
		vector<int> arr;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			arr.push_back(a);
		}
		//detect cycles
		unordered_set<int> V;
		int c = 0;
		int i = 0;
		while (V.size() <= n) {
			//cout << i;
			if (V.find(i) == V.end()) {
				V.insert(i);
				c += 1;
				i = arr[i]-1;
			} else {
				if (c > 2) {
					if (cycles.find(c) != cycles.end()) {
						cycles[c] += 1;
					} else {
						cycles[c] = 1;
					}
				}
				c = 0;
				i += 1;
			}
		} 
		int res = 0;
		for (const auto& elem: cycles) {
			res += ((elem.first %2) ? elem.first/2 : elem.first/2 - 1) * cycles[elem.first]; 
		}
		cout << res << "\n";
	}
}
