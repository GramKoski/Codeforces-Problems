#include <iostream>
#include <vector>
#include <algorithm>

#define llu long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		llu n, x, y; cin >> n >> x >> y;
		vector<int> arr(n);
		llu sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}
		//binary search for each a in arr
		sort(arr.begin(), arr.end());
		llu res = 0;
		//cout << "Sum = " << sum << "\n";
		for (int i = 0; i < n; ++i) {
			int l = i;
			int r = n;
			int m;

			while (l != r-1) {
				m = (r+l)/2;
				if (arr[m] <= sum -x -arr[i]) {
					l = m;
				} else {
					r = m;
				}
			}
			int R = l; l = i; r = n;
			while (l != r-1) {
				m = (r+l)/2;
				//cout << "m = " << m << " arr[m] = " << arr[m] << " val = " << sum -y -arr[i] << "\n";
				if (arr[m] >= sum -y - arr[i]) {
					r = m;
				} else {
					l = m;
				}
			}
			int L = r;
			res += (R-L >= 0) ? (R-L+1) : 0;
			//cout << "i = " << i << " " << "L = " << L << " " << "R = " << R << "\n";

		}
		cout << res << "\n";
	}
}

