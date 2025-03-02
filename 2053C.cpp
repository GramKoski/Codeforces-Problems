#include <iostream>
#include <vector>

#define llu long long unsigned

using namespace std;

vector<llu> val(llu n, llu k) {
	if (n < k) {
		return {0, 0};
	}
	vector<llu> sub_res = val(n/2, k);
	sub_res[0] *= 2;
	sub_res[0] += sub_res[1]*((n+1)/2);
	sub_res[1] *= 2;
	if (n%2==1) {
		sub_res[0] += (n+1)/2;
		sub_res[1] += 1;
	}
	//cout << n << " tot = " << sub_res[0] << " hits = " << sub_res[1] << "\n";
	return sub_res;
}


int main() {
	int t; cin >> t;
	while (t--) {
		llu n, k; cin >> n >> k;
		llu total = val(n, k)[0];
		cout << total << "\n";
	}
}
