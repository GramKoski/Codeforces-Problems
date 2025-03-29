#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std; 

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> ind = {1, 2, 3};
		random_device rd;
    	mt19937 gen(rd());
    	uniform_int_distribution<> distrib(0, 2);
		//Probabilistic algo with 1/3 chance of guessing the right triangle. We must guess the correct triangle 7 times and we have 75 guesses. Very high probability.
		int p = 1; int i = 0;
		while (p != 0) {
			cout <<"? " << ind[0] << " " << ind[1] << " " << ind[2] << "\n";
			cout.flush();
			cin >> p;
			if (p == 0) {
				break;
			} else {
				i = distrib(gen); 
				ind[i] = p;
			}
		}
		cout << "! " << ind[0] << " " << ind[1] << " " << ind[2] << "\n";
		cout.flush();
	}
}

