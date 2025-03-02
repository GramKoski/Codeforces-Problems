#include <iostream>
#define llu long long unsigned

using namespace std;

int main() {
	string ts;
	getline(cin, ts);
	int t = stoi(ts);

	while (t--) {
		string n;
		getline(cin, n);
		int numTwos = 0;
		int numThrees = 0;
		llu num = 0;
		for (char c : n) {
			//cout << c << "\n";
			if (c == '2') {
				numTwos += 1;
			} else if (c == '3') {
				numThrees += 1;
			}
			num += c - '0';
		}
		//cout << num << "\n";
		//cout << numTwos << " " << numThrees << "\n";
		bool valid = false;
		for (int i = 0; i < min(9, numTwos+1); ++i) {
			for (int j = 0; j < min(3, numThrees+1); ++j) {
				//cout << num + i*2 + j*6 << "\n";
				if ((num + i*2 + j*6) % 9 == 0) {
					valid = true;
					break;
				} 
			}
		}
		if (valid) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
