#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		vector<priority_queue<int>> index(3);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			index[a[i]].push(i);
		}
		int end_one = n-1-index[2].size();
		//Replace 0s with 1s on two area
		//Remove twos that are already in the correct area
		while (!index[2].empty() && index[2].top() > end_one) {
			index[2].pop();
		}

		vector<pair<int, int>> res;
		int i_one; 
		int i;
		//Replace 1s in two section with 2s
		while (!index[1].empty() && index[1].top() > end_one) {
			//There should be enough twos left
			i_one = index[1].top();
			res.push_back({index[2].top()+1, i_one+1});
			a[i_one] = 2;
			a[index[2].top()] = 1;
			index[1].pop();
			index[1].push(index[2].top());
			index[2].pop();
		}
		while (!index[0].empty() && index[0].top() > end_one) {
			i_one = index[1].top();
			index[1].pop();
			i = index[0].top();
			index[0].pop();
			res.push_back({i+1, i_one+1});

			a[i] = a[i_one];
			a[i_one] = 0;

			index[0].push(i_one);
			i_one = i;
			res.push_back({i_one+1, index[2].top()+1});

			a[index[2].top()] = 1;
			a[i_one] = 2;

			i_one = index[2].top();
			index[2].pop();
			index[1].push(i_one);
		}

		//Replace 0s in the ones section with ones
		int one_start = end_one - index[1].size() + 1;
		while (!index[1].empty() && index[1].top() >= one_start && index[1].top() <= end_one) {
			index[1].pop();
		}
		while (!index[0].empty() && !index[1].empty() && index[0].top() >= one_start) {
			res.push_back({index[1].top()+1, index[0].top()+1});
			a[index[0].top()] = 1;
			a[index[1].top()] = 0;
			index[1].pop();
			index[0].pop();
		}
		cout << res.size() << "\n";
		for (auto m : res)  {
			cout << m.first << " " << m.second << "\n";
		}
	}
	return 0;
}
			

			
