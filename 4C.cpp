#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;

int main() {
	int n;
	string str;
	cin >> n;
	map <string, int> m;

	for (int i = 0; i < n; ++i) {
		cin >> str;
		if (m.find(str) != m.end()) {
			m[str] += 1;
			str += to_string(m[str]);
			cout << str << "\n";
		} else {
			m[str] = 0;
			cout << "OK\n";
		}
	}
}
