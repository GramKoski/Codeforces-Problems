#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n+1);
		ll res = 0; 
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			res += a[i];
		}
		//Calculate first MAD
		unordered_map<int, int> freq;
		int curr = 0;
		vector<int> mad1(n);
		mad1[0] = curr;
		freq[a[0]] = 1;
		for (int i = 1; i < n; ++i) {
			if (freq.find(a[i]) != freq.end()) {
				freq[a[i]] += 1;
			} else {
				freq[a[i]] = 1;
			}
			if (freq[a[i]] >= 2 && a[i] > curr) {
				curr = a[i];
			}
			mad1[i] = curr;
		}
		for (auto i : mad1) res += i;
		//Calculate 2nd MAD
		unordered_map<int, int> freq2;
		curr = 0;
		vector<int> mad(n);
		mad[0] = curr;
		freq[mad1[0]] = 1;
		for (int i = 1; i < n; ++i) {
			if (freq2.find(mad1[i]) != freq2.end()) {
				freq2[mad1[i]] += 1;
			} else {
				freq2[mad1[i]] = 1;
			}
			if (freq2[mad1[i]] >= 2 && mad1[i] > curr) {
				curr = mad1[i];
			}
			mad[i] = curr;
		}

		vector<ll> pre(n);
		pre[0] = mad[0];
		for (int i = 1; i < n; ++i) {
			pre[i] = pre[i-1] + mad[i];	
		}
		//Main logic
		for (int i = 1; i < n; ++i) {
			res += pre[i];
		}
		//for (auto i : mad) cout << i << " ";
		cout << res << "\n";
	}
}



