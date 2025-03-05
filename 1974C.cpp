#include <vector>
#include <unordered_set>
#include <iostream>
#include <unordered_map>
#include <set>
#include <map>

#define ll long long

using namespace std;

struct PairHash {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const {
        // Combine hash values of the pair elements
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		//The challenge with this problem is actually finding a way to stay within the memory limit
		//The O(n) algorithm is simple but it is tricky to store all the triples in a compact way
		//Should I be wary of unordered_map blowing up?
		
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		map<pair<int, int>, map<int, int>> b;
		map<pair<int, int>, map<int, int>> m;
		map<pair<int, int>, map<int, int>> e;
		vector<map<pair<int, int>, int>> count(3);
		ll res = 0;
		pair<int, int> z, o, t;
		for (int i = 0; i < n-2; ++i) {
			//Check if in 
			z = {a[i+1], a[i+2]};
			t = {a[i], a[i+1]};
			o = {a[i], a[i+2]};
			//cout << z.first << " " << z.second << " " << o.first << " " << o.second << " " << t.first << " " << t.second << "\n";
			if (b.find(z) == b.end()) {
				b[z][a[i]] = 1;
				count[0][z] = 1;
			} else if (b[z].find(a[i]) == b[z].end()) {
				count[0][z] += 1;
				res += count[0][z]-1;
				b[z][a[i]] = 1;
			} else {
				count[0][z] += 1;
				b[z][a[i]] += 1;
				res += count[0][z] - b[z][a[i]];
				//cout << a[i] << " " << z.first << " " << z.second << " " << count[0][z] << " " << b[z][a[i]] << "\n";
			}
			if (m.find(o) == m.end()) {
				count[1][o] = 1;
				m[o][a[i+1]] = 1;
			} else if (m[o].find(a[i+1]) == m[o].end()) {
				count[1][o] += 1;
				m[o][a[i+1]] = 1;
				res += count[1][o] - 1;   
			} else {
				count[1][o] += 1;
				m[o][a[i+1]] += 1;
				res += count[1][o] - m[o][a[i+1]];
			}
				
			if (e.find(t) == e.end()) {
				e[t][a[i+2]] = 1;
				count[2][t] = 1;
			} else if (e[t].find(a[i+2]) == e[t].end()) {
				count[2][t] += 1;
				e[t][a[i+2]] = 1;
				res += count[2][t] - e[t][a[i+2]];
			} else {
				count[2][t] += 1;
				e[t][a[i+2]] += 1;
				res += count[2][t] - e[t][a[i+2]];
				//cout << t.first << " " << t.second << "\n";
			}

				
		}

		cout << res << "\n";
	
	}
}
				
