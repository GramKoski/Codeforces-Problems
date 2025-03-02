#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int prev = 0; 
		bool broken = false;
		bool valid = true;
		int i = 0;
		while (i < n-1) {
			int g = gcd(a[i], a[i+1]);
			if (g < prev) {
				if (broken) {
					valid = false;
					break;
				}
				if (i < n-2) {
					if (gcd(a[i], a[i+2]) < prev) {
						valid = false;
						break;
					} else {
						prev = gcd(a[i], a[i+2]);
					}
				}
				broken = true;
				i += 2;
			} else {
				i += 1;
				prev = g;
			}
		} 
		bool valid2 = true;
		reverse(a.begin(), a.end());
		i = 0;
		broken = false;
		prev = 1e9;
		while (i < n-1) {
			int g = gcd(a[i], a[i+1]);
			if (g > prev) {
				if (broken) {
					valid2 = false;
					break;
				}
				if (i < n-2) {
					if (gcd(a[i], a[i+2]) > prev) {
						valid2 = false;
						break;
					} else {
						prev = gcd(a[i], a[i+2]);
					}
				}
				broken = true;
				i += 2;
			} else {
				i += 1;
				prev = g;
			}
		} 

		if (valid || valid2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
			
