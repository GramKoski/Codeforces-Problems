#include <iostream>
#include <vector>
#include <set>

#define ll long long

using namespace std;

int main() {
	int t, n, res;
	ll curr, a;
	cin >> t;

	while (t--) {
		curr = 0;
		set<ll> sums;
		cin >> n;
		res = 0;
		sums.emplace(0);
		while (n--) {
			cin >> a;
			curr += a;
			if (sums.count(curr)) {
				//take this interval
				res += 1;
				sums.clear();
				curr = 0;
			}
			sums.emplace(curr);
		}
		cout << res << "\n";
	}
}
