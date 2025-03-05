#include <vector>
#include <iostream>

#define ll long long

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<ll> a(n+m+1);
		vector<ll> b(n+m+1);
		for (int i = 0; i < n+m+1; ++i) {
			cin >> a[i];
		}
		for (int i =0; i < n+m+1; ++i) {
			cin >> b[i];
		}
		bool p_over = true;
		int num_p = 0; int num_t = 0;
		int last = n+m; 
		for (int i = 0; i < n+m+1; ++i) {
			if (a[i] > b[i]) {
				num_p += 1;
			} else {
				num_t += 1;
			}
			if (num_p == n+1) {
				last = i; p_over = true;
				break;
			} else if (num_t == m+1) {
				last = i; p_over = false;
				break;
			}
		}
		//cout << p_over << " " << last << "\n";
		//Take pre and post_fix sums
		vector<ll> pre(n+m+2, 0);
		for (int i = 1; i <= n+m+1; ++i) {
			pre[i] = pre[i-1] + ((a[i-1] > b[i-1]) ? a[i-1] : b[i-1]);
		}
		vector<ll> post(n+m+2, 0);
		for (int i = n+m; i >= 0; --i) {
			post[i] = post[i+1] + ((p_over) ? b[i] : a[i]);
		}
		
		//Main algorithm
		//if i is before the oversupply point than include oversuply in presum else take normal presum good and postfix oversupply
		vector<ll> res(n+m+1, 0);

		for (int i = 0; i < n+m+1; ++i) {
			if (i <= last && ((p_over && a[i] > b[i]) || (!p_over && b[i] >= a[i]))) {
				res[i] += pre[i] + pre[last+1] - pre[i+1];
				res[i] += post[last+1];
			} else {
				res[i] += pre[last];
				res[i] += post[last] - post[i] + post[i+1];
			}
		}
		for (auto r : res) cout << r << " ";
		cout << "\n";
	}
}
