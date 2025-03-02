#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int r = 2;
		int res = n-2;
		for (int l = 0; l < n-2; ++l) {
			//cout << arr[l] + arr[l+1] << " " << arr[r] << " ";
			while (r < n && arr[l]+arr[l+1] > arr[r]) {
				r++;
				//cout << "here\n";
			}
			res = min(res, n-r+l);
			//cout << "r = " << r << "\n";
		}
		cout << res << "\n";
	}
}

