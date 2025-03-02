#include <iostream>
#include <cmath>

#define llu long long unsigned

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		llu l, r;
		cin >> l >> r;
		int  n = (sqrt(8*(r-l+1))-1)/2 + 1;
		cout << n << "\n";
	}
}
		
