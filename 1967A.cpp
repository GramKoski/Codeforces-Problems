#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> freq(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> freq[i];
		}
		sort(freq.begin(), freq.end());
		int res = 0;
		//Key observation: It only matters what the minimum possible value is because that determines the number of "pure" permutations there will be in the list.
		//The number of minimum frequency elements determines the number of extra permutations that can be appended to the end. If we increased a minumum frequence element by
		// 1 we only increase the number of total permutations by 1 because we append at the end and rearrange if necessary. It only increases by one assuming that the permutation
		// was in the correct arrangement before
		// Note that this is the part where we can append one permutation for each element that is in excess
		int w = freq[0];
		for (int i = 1; i < n; ++i) {
			if (k - ((freq[i] - freq[i-1]) * i) >= 0) {
				k -= (freq[i]-freq[i-1]) * i;
				w = freq[i];
			} else {
				w = w + k/i;
				res -= i;
				break;
			}
		}
		res += n*w;
		cout << res + max(0, k) << "\n";
	}
}

