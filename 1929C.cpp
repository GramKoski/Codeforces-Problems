#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		ll k, x, a; cin >> k >> x >> a;
		ll b = 1;
		ll sum = 1;
		for (int i = 2; i <= x+1; ++i) {
			b = (sum+k-1)/(k-1);
			sum += b;
			if (a-sum < 0) break;
		}
		//cout << a-sum << "\n";
		if (a-sum >= 0) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}
