#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

#define llu long long unsigned

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k, w, a;
		vector<int> arr;
		cin >> n >> m >> k >> w;
		for (int i = 0; i < w; ++i) {
			cin >> a;
			arr.push_back(a);
		}
		sort(arr.begin(), arr.end(), greater<int>());
		//go through matrix and add overlaps to map
		map<int, int, greater<int>> laps;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int o = min(k, min(min(m-j, m-k+1), j+1)) * min(k, min(min(n-i, i+1), n-k+1));
				if (laps.find(o) == laps.end()) {
					laps[o] = 1;
				} else {
					laps[o] += 1;
				}
			}
		}
		map<int, int>::iterator i = laps.begin();
		int wi = 0;
		llu res = 0;
		while(i != laps.end() && wi < w) {
			//cout << i->first << " " << i->second << "\n";
			for (int ii = wi; ii < min(w, wi+(i->second)); ++ii) {
			//	cout << i << "\n";
				res += (llu)arr[ii] * i->first;
			}
			wi += i->second;
			++i;
		}
		cout << res << "\n";
	}
}

		
