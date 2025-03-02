#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, v; cin >> n >> m >> v;
		vector<int> a(n);
		vector<ll> presum(n);
		for (int i =0; i < n; ++i) {
			cin >> a[i];
			presum[i] = a[i] + ((i > 0) ? presum[i-1] : 0);
		}
		//two pointer method for finding the max interval prefix array
		vector<int> pre(n, 0);
		int r = 0;
		for (int l = -1; l < n-1; ++l) {
			if (l > 0) {
				pre[l] = max(pre[l], pre[l-1]);
			}
			while (r < n && presum[r]-((l==-1) ? 0 : presum[l]) < v) {
				++r;
			}
			if (r < n) {
				pre[r] = max(pre[r], 1 + ((l >= 0) ? pre[l] : 0));
			}
		}
		/*
		for (auto i : pre) cout << i << " ";
		cout << "\n";
		*/
		vector<int> post(n, 0);
		vector<ll> postsum(n, 0);
		postsum[n-1] = a[n-1];
		for (int i = n-2; i >= 0; --i) {
			postsum[i] = postsum[i+1] + a[i];
		}
		/*
		for (auto i : postsum) cout << i << " ";
		cout << "\n";
		*/
		int le = n-1;
		for (r = n; r >= 0; --r) {
			if (r < n-1) {
				post[r] = max(post[r], post[r+1]);
			}
			while (le >= 0 && postsum[le]-((r==n) ? 0 : postsum[r]) < v) {
				--le;
			}
			//cout << "le = " << le << " r = " << r << " sum = " << postsum[le]-((r==n) ? 0 : postsum[r]) << "\n";
			if (le >= 0) {
				post[le] = max(post[le], 1 + ((r==n) ? 0 : post[r]));
			}
		}
		/*	
		for (auto i : post) cout << i << " ";
		cout << "\n";
		*/
		//Two pointer strategy for finding max interval for alice
		ll alice = ((pre[n-1] >= m) ? 0 : -1);
		r = 0;
		for (int l = 0; l < n; ++l) {
			while (r < n && ((l>0) ? pre[l-1] : 0) + ((r < n-1) ? post[r+1] : 0) >= m) {

				//cout << "l = " << l << " r = " << r << " interval = " << ((l>0) ? pre[l-1] : 0) + ((r < n-1) ? post[r+1] : 0) << " sum = " << presum[r]-((l>0) ? presum[l-1] : 0)<< "\n"; 
				alice = max(alice, presum[r]-((l>0) ? presum[l-1] : 0));
				r++;
			}
		}
		cout << alice << "\n";
	}
}


		
