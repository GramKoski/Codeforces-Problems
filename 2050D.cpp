#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string n;
		cin >> n;
		for (int i = 0; i < n.length(); ++i) {
			int s = n[i] - '0';
			//cout << s << " ";
			int m = s;
			int r = i;
			for (int j = i+1; j < min((int)(n.length()), i+10); ++j) {
				//cout << (int)n[j] - '0' << " ";
				if ((int)(n[j]-'0')-(j-i) > m) {
					r = j;
					m = n[j]-'0'-(j-i);
				}
			}
			for (int j = r-1; j >= i; --j) {
				n[j+1] = n[j];
			}
			n[i] = m + '0';
		}
		cout << n << "\n";
	}
}
