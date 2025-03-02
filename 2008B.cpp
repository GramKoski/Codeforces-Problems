#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		int size;
		cin >> size;
		cin >> s;
		int i = 0;
		while (i < size && s[i] == '1') {
			i += 1;
		}
		i -= 1;
		if (size == 4 && i == 3) {
			cout << "YES\n";
			continue;
		}
		//cout << size << " " << i << "\n";
		bool valid = true;
		if (size / i != i || size %i != 0) {
			cout << "NO\n";
			valid = false;
		}
		for (int j = i; j < size-i; ++j) {
			if ((j%i == 0 || j%i == (i-1)) && s[j] != '1') {
				cout << "NO\n";
				valid = false;
				break;
			} else if (!(j%i == 0 || j%i == (i-1)) && s[j] != '0') {
				valid = false;
				cout << "NO\n";
				break;
			}
		}

		for (int j = size-i; j < size; ++j) {
			if (s[j] != '1') {
				valid = false;
				cout << "NO\n";
				break;
			}
		}
		if (valid) {
			cout << "YES\n";
		}
	}
}

			
