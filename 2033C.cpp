#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;

	cin >> t;

	for (int _ = 0; _ < t; ++_) {
		int n;
		cin >> n;
		vector<int> arr;

		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			arr.push_back(a);
		}
		
		int l = 1;
		int r = n-2;

		while (l < r) {
			if ((arr[l-1] == arr[l] && arr[r+1] != arr[l]) || (arr[r+1] == arr[r] && arr[l-1] != arr[r])) {
				int temp = arr[l];
				arr[l] = arr[r];
				arr[r] = temp; 
			}
			l += 1;
			r -= 1;
		}
		int res = 0;
		for (int i = 1; i < n; ++i) {
			if (arr[i-1] == arr[i]) {
				res += 1;
			}
		}
		cout << res << "\n";
	}
}
