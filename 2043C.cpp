#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		ll minPre = 0; ll minPreS = 0; ll maxPre = 0; ll maxPreS = 0;
		ll S = 0;
		ll pre = 0; ll minRange = 0; ll maxRange = 0; ll minRangeS = 0; ll maxRangeS = 0;
		for (int i = 0; i < n; ++i) {
			if (abs(a[i]) > 1) {
				S = a[i];
				ll post = 0;
				for (int c = i-1; c >= 0; --c) {
					post += a[c];
					minPreS = min(minPreS, post);
					maxPreS = max(maxPreS, post);
				}
				post = 0; minRangeS = minPreS; maxRangeS = maxPreS;
				pre = 0; minPre = 0; maxPre = 0;
				continue;
			}
			pre += a[i];
			maxRange = max(maxRange, pre - minPre);
			minRange = min(minRange, pre - maxPre);
			minPre = min(minPre, pre); //cout << "minRange = " << minRange << "\n";
			maxPre = max(maxPre, pre);
			if (S != 0) {
				minRangeS = min(minRangeS, minPre + minPreS);
				maxRangeS = max(maxRangeS, maxPre + maxPreS);
			}
		}

		//cout << "min = " << minRange << " max = " << maxRange << " minS = " << minRangeS <<  " maxS = " << maxRangeS << "\n";

		if ((S > 0 && S + minRangeS  <= maxRange) || (S < 0 && S + maxRangeS >= minRange)) {
			cout << max(maxRange, maxRangeS) - min(minRange, minRangeS) + 1 << "\n";
			for (ll i = min(minRange, minRangeS); i <= max(maxRange, maxRangeS); ++ i) cout << i << " ";
		} else if (S != 0) {
			cout << maxRange - minRange + 1 + maxRangeS - minRangeS + 1 << "\n";
			if (minRange < S + minRangeS) {
				for (ll i = minRange; i <= maxRange; ++i) cout << i << " ";
				for (ll i = S + minRangeS; i <= S + maxRangeS; ++i) cout << i << " ";
			} else {
				for (ll i = S + minRangeS; i <= S + maxRangeS; ++i) cout << i << " ";
				for (ll i = minRange; i <= maxRange; ++i) cout << i << " ";
			}
		} else {
			cout << maxRange - minRange + 1 << "\n";
			for (ll i = minRange; i <= maxRange; ++i) cout << i << " ";
		}
		cout << "\n";
	}
}
