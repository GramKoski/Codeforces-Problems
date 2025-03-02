#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_set<int> known;
		known.insert(1);
		int curr, next, base;
		vector<vector<int>> connections;
		for (int i = 2; i <= n; ++i) {
			//query for branch and add to branch stack if necessary
			//At most nlogn queries which is less than 15n
			curr = i;
			base = 1;
			while (known.find(i) == known.end()) {
				cout << "? " << base << " " << curr << "\n"; cout.flush();
				cin >> next;
				if (next == -1) return 0;
				if (next == base) {
					connections.push_back({next, curr});
					known.insert(curr);
					base = curr;
					curr = i;
				} else if (known.find(next) != known.end()) {
					base = next;
				} else {
					curr = next;
				}
			}
		}
		cout << "! ";
		for (auto edge : connections) cout << edge[0] << " " << edge[1] << " ";
		cout << "\n";
	}
}
