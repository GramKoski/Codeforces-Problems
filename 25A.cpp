#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, odd, even, odd_num, even_num;
	cin >> n;
	odd = 0;
	even = 0;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		if (m%2 == 1 && odd == 0) {
			odd_num = i;
		} else if (m%2 == 0 && even == 0) {
			even_num = i;
		}
		if (m%2) {
			odd += 1;
		} else {
			even += 1;
		}
		if (odd==1 && even > 1) {
			cout << odd_num+1 << "\n";
			break;
		} 
		if (even == 1 && odd > 1) {
			cout << even_num+1 << "\n";
			break;
		}
	}
}

