#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int _ = 0; _ < t; ++_) {
		int n;
		cin >> n;
		unordered_map<int, int> lakes;
		int a;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a;
				if (a < 0) {
					if (lakes.find(i-j) == lakes.end()) {
						lakes[i-j] = a;
					} else {
						lakes[i-j] = min(lakes[i-j], a);
					}
				}
			}
		}
		int sum = 0;
		for (auto const& d: lakes) {
			sum -= d.second;
		}
		cout << sum << "\n";
	}
}


