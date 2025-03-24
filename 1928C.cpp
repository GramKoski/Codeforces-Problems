#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		int res = 0;
		unordered_set<int> s;
		int o = 0;
		//Must find the number of devisors of a number (n-x)/2
		if ((n-x)%2 == 0) {
			for (int d = 1; d*d <= n-x; ++d) {
				o = (n-x)/d;
				if (o%2 == 0 && (n-x)%o == 0) {
					s.insert((n-x)/o+1);
				}
				if (d%2 == 0 && (n-x)%d == 0) {
					s.insert((n-x)/d + 1);
				}
			}

			for (int d = 1; (d*d) <= n+x-2; ++d) {
					o = (n+x-2)/d;
					if (o % 2 ==  0 && (n+x-2)%o == 0) {
						s.insert((n+x-2)/o + 1);
					}
					if (d % 2 == 0 && (n+x-2) % d == 0) {
						s.insert((n+x-2)/d + 1);
				}
			}
			for (auto e : s) {
				if (e >= x) res += 1;
			}
		}
		cout << res << "\n";
	}
}

