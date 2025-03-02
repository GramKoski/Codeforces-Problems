#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define llu long long unsigned

int main() {
	int n, k, q;
	cin >> n >> k >> q;

	vector< vector<llu> > regions(n);
	vector<llu> prev(k);

	for (int i = 0; i < k; ++i) {
		llu a;
		cin >> a;
		prev[i] = a;
	}
	regions[0] = prev;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			llu a; 
			cin >> a;
			regions[i].push_back(regions[i-1][j] | a);
		}
	}

	for (int t = 0; t < q; ++t) {
		int m;
		cin >> m;
		llu c;
		char o;
		int r;
		int L = 0;
		int R = n-1;
		for (int query = 0; query < m; ++query) {
			int le = -1;
			int ri = n;
			cin >> r >> o >> c;
			int mid;
			while (le+1 != ri) {
			//Idea: for <, maintain left as one under the threshhold and move right to the threshold until they are one apart and do the same 
			//with the right as one over the threshild when >
				mid = le + (ri-le)/2;
				if (o == '<') {
					if (regions[mid][r-1]<c) {
						le = mid;
					} else {
						ri = mid;
					}
				} else {
					if (regions[mid][r-1] <= c) {
						le = mid;
					} else {
						ri = mid;
					}
				}
			}
			if (o == '<' and le < R) {
				R = le;
			}
			if (o == '>' and ri > L) {
				L = ri;
			}
			//cout << "L = " << L << ", R = " << R << "\n";
		}
		if (R >= L) {
			cout << L+1 << "\n";
		} else {
			cout << -1 << "\n";
		}
	}
}

