#include <iostream>
#include <vector>

using namespace std; 

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int i = 1; int j = 2; int k = 3;
		//Probabilistic algo with 1/3 chance of guessing the right triangle
		while (i != 0) {
			if (i == -1) break;
			cout <<"? " << i << " " << j << " " << k << "\n";
			fflush(stdout);
			cin >> i;
		}
		cout << "! " << i << " " << j << " " << k << "\n";
		fflush(stdout);
	}
}

