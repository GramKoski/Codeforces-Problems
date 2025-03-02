#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a;
		cin >> n;
		vector<int> arr(n);
		vector<int> res(n, 0);
		string color;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			arr[i] = a;
		}
		cin >> color;
		vector<bool> visited(n, false);
		for (int i = 0; i < n; ++i) {
			int j = arr[i]-1;
			int curr = 0;
			unordered_set<int> cycle;
			while (!visited[j]) {
				cycle.insert(j);
				visited[j] = true;
				if (color[j] == '0') {
					curr += 1;
				}
				j = arr[j] -1;
			}
			for (auto h : cycle) {
				res[h] = curr;
			}
		}
		for (auto r : res) {
			cout << r << " ";
		}
		cout << "\n";
	}
}

