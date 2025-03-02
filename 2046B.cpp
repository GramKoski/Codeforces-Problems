#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		vector<int> post(n);
		post[n-1] = n-1;
		for (int i = n-2; i >= 0; --i) {
			if (arr[i] <= arr[post[i+1]]) {
				post[i] = i;
			} else {
				post[i] = post[i+1];
			}
		}
		vector<int> res;
		priority_queue<int, vector<int>, greater<int>> m;
		int j = 0; int minimum;
		bool end = false;
		while (res.size() < n) {
			minimum = arr[post[j]];
			if (!m.empty() && m.top() < minimum) {
				minimum = m.top();
				end = true;
			}
			for (int i = j; i < ((end) ? n : post[j]); ++i) {
				m.push(arr[i]+1);
			}
			if (!end) {
				res.push_back(minimum);
			}
			j = (end) ? n : post[j]+1;
			if (j >= n) {
				break;
			}
		}
		while (!m.empty()) {
			res.push_back(m.top());
			m.pop();
		}
		for (auto n : res) {
			cout << n << " ";
		}
		cout << "\n";
	}
}
