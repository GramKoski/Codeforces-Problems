#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_set<int> v;
		bool valid;
		vector<vector<int>> a(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
			}
		}
		//Postfix sum
		for (int i = 0; i < n; ++i) {
			for (int j = n-2; j >= 0; --j) {
				a[i][j] = a[i][j] + a[i][j+1];
			}
		}
		//Some complex pointers algorithm
		for (int j = 0; j < n-1; ++j) {
			for (int i = 0; i < n; ++i) {
				if (

