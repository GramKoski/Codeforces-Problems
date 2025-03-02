#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		int n; string s; cin >> n >> s;
		vector<int> post(n);
		post[n-1] = 2;
		for (int i = n-2; i >= 0; --i) {
			if (s[i] == '0') {
				post[i] = post[i+1]-1;
			} else {
				post[i] = post[i+1] + 1;
				if (s[i+1] == '0') {
					post[i] = max(2, post[i]);
				}
			}
		}
		//for (auto i : post) cout << i << " ";
		//cout << "\n";
		ll res = 0;
		priority_queue<int> bag;
		for (int i = 0; i < n; ++i) {
			bag.push(i+1);
			//cout << "i = " << i << " size = " << bag.size() << " ";
			if (s[i] == '0') {
				continue;
			}
			if (bag.size() >= post[i]) {
				if (bag.size() > 1) {
					bag.pop();
					//cout << "top = " << bag.top() << " ";
					res += bag.top();
					bag.pop();
				} else {
					res += bag.top();
					bag.pop();
				}
			}
		}
		//cout << "\n";
		while (!(bag.size() == 0)) {
			res += bag.top();
			bag.pop();
		}
		cout << res << "\n";
	}
}
