#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		int curr = 1;
		for (int i = 0; i < k; i+=2) {
			for (int j = 0; j < n/k + ((n%k > i) ? 1 : 0); ++j) {
				a[k*j+i] = curr;
				curr += 1;
			}
			for (int j = n/k + ((n%k > i+1) ? 1 : 0)-1; j >= 0; --j) {
				a[k*j+i+1] = curr;
				curr += 1;
			}
		}
		for (auto e : a) cout << e << " ";
		cout << "\n";
	}
}
