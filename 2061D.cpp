#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		priority_queue<int> a;
		priority_queue<int> b;
		int num;
		for (int i = 0; i < n; ++i) {
			cin >> num;
			a.push(num);
		}
		for (int i = 0; i < m; ++i) {
			cin >> num;
			b.push(num);
		}
		bool valid = true;
		int cur_a, cur_b;
		while (!a.empty() && !b.empty() && a.size() >= b.size()) {
			cur_a = a.top();
			cur_b = b.top();
			//cout << a.size() << " " << b.size() << "\n";
			if (cur_a > cur_b) {
				valid = false;
				break;
			} else if (cur_a < cur_b) {
				b.pop();
				b.push(cur_b/2); b.push((cur_b+1)/2);
			} else {
				a.pop();
				b.pop();
			}
		}
		if (valid == false || !a.empty() || !b.empty() || a.size() != b.size()) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}
}
