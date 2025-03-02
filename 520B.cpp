#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	unordered_set<int> visited;
	queue<int> q;
	q.push(n);
	int length = 0;

	int ai, s;
	while (!q.empty()) {
		s = q.size();
		for (int i = 0; i < s; i++) {
			ai = q.front();
			q.pop();
			visited.insert(ai);
			if (ai == m) {
				cout << length << "\n";
				return 1;
			}

			if (ai*2 <= m*2 && visited.find(ai*2) == visited.end()) {
				q.push(ai*2);
			}
			if (ai-1 > 0 && visited.find(ai-1) == visited.end()) {
				q.push(ai-1);
			}
		}
		length += 1;
	}
	cout << "No value\n";
}
