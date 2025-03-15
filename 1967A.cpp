#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		vector<ll> freq(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> freq[i];
		}
		sort(freq.begin(), freq.end());
		ll res = 0;
		//Key observation: It only matters what the minimum possible value is because that determines the number of "pure" permutations there will be in the list.
		//The number of minimum frequency elements determines the number of extra permutations that can be appended to the end. If we increased a minumum frequence element by
		// 1 we only increase the number of total permutations by 1 because we append at the end and rearrange if necessary. It only increases by one assuming that the permutation
		// was in the correct arrangement before
		// Note that this is the part where we can append one permutation for each element that is in excess
		ll w = freq[0];
		ll i;
		for (i = 1; i < n; ++i) {
			if (k - ((freq[i] - freq[i-1]) * i) >= 0) {
				//cout << i << " " << freq[i] << " " << w << " " << k << "\n"; 
				k -= (freq[i]-freq[i-1]) * i;
				w = freq[i];
			} else {
				w = w + k/i;
				k = k % i;
				break;
			}
		}
		res -= i-1;
		res += n*w;
		cout << res + ((k > 0) ? k : 0) << "\n";
	}
}

