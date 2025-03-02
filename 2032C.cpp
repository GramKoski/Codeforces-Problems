#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int> arr, int target, int right) {
	int l = -1; int r = right+1; int mid;

	while (l != r-1) {
		mid = (l+r)/2;
		if (arr[mid] > target) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return l;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int mid = binary_search(arr, arr[n-1]/2, n-1);
		int right = (mid == -1) ? 0 : (mid+1 - ((arr[mid] + arr[mid+1] > arr[n-1]) ? 1 : 0));
		int mid1 = binary_search(arr, arr[mid]/2, mid);
		int left = n-mid-1 + ((mid1 == -1) ? 0 : (mid1+1 - ((arr[mid1] + arr[mid1+1] > arr[mid]) ? 1 : 0)));
		cout << min(left, right) << "\n";

	}
}
