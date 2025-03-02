#include <iostream>
#include <vector>

#define llu long long unsigned

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a;
		vector<int> arr;
		string s;
		cin >> n;
		vector<llu> pre(n, 0);
		llu sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			arr.push_back(a);
			sum += a;
			pre[i] = sum;
		}
		cin >> s;
		llu res;
		int l, r;
		res = l = 0;
		r = arr.size() -1;
		while(l < r) {
			for (; r >= 0; --r) {
				if (s[r] == 'R') {
					break;
				}
			}
			for (; l < arr.size(); ++l) {
				if (s[l] == 'L') {
					break;
				}
			}
			if (l >= r) {
				break;
			}
			res += (pre[r] - ((l > 0) ? pre[l-1] : 0));
			l += 1;
			r -= 1;
		}
		cout << res << "\n";
		
	}
}
