#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		string x;
		vector<int> pre(s.length(), 0);
		vector<int> pre_one(s.length(), 0);
		for (int i = 0; i < s.length(); ++i) {
			x += (char)((int)s[i]-'0' ^ (int)s[i]-'0');
			if (i > 0) {
				pre[i] = pre[i-1];
				pre_one[i] = pre_one[i-1];
			}
			if (x[i] == '1') pre[i] += 1;
			if (s[i] == '1') pre_one[i] += 1;
		}
		int one_count = (x[0] == 1) ? 1 : 0;
		int m = 0; int l, r;
		for (int j = s.size(); i < s.size(); ++i) {		
			for (int i = j; j >= 0; --j) {
				one_count = pre_one[s.size()-(j-i)-1]
				one_count += 

				


			

