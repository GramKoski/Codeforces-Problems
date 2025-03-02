#include <iostream>
#include <vector>

using namespace std;

int main() {
	string a; cin >> a;
	bool valid = false;
	int len = a.length(); int r, l;
	int sep;
	for (sep = 1; sep < (len+1)/2; ++sep) {
		r = len-sep; l = sep;
		//cout << "sep = " << sep << "\n";
		valid = true;
		for (int i = 0; i < len-sep; ++i) {
			//cout << i << " " << a[i] << " " << a[l+i] << "\n";
			if (a[i] != a[l+i]) {
				valid = false; break;
			}
			//cout << len-i-1 << " " << a[len-i-1] << " " << a[r-i-1] << "\n";
			if (a[len-i-1] != a[r-i-1]) {
				valid = false; break;
			}
		}
		if (valid == true) break;
	}
	if (valid) {
		cout << "YES\n";
		cout << a.substr(sep, len-sep) << "\n";
	} else {
		cout << "NO\n";
	}
}

