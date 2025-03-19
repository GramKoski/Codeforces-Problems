#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		//Nothing will happen at odd numbered steps because odd * odd = odd
		//Note that 2 brings even numbers that are divisible by 2 but there is no way for these numbers to be divisible by 4
		//Note that 4 brings even nubmers that are divisible by 4, 2 has already been covereed and there is no way for these numbers to be divisible by 6 or more
		//Note 6 doesn't bring anything new because a number because x*6 = y --> x*3*2 = y so it was covered in round 2
		//In general if the round is not a power of 2 it can be broken down into an odd number and a lower power of 2
		//What can be done checking if the number is odd than checking its lowest power of 2 (lowest set bit
		//Or we can do it recursively is better
		int r = 1;
		int place = 0;
		while (place + (n+1)/2 < k) {
			place += (n+1)/2;
			n = n/2;
			r = 2*r;
			//cout << place << " " << r << "\n";
		}
		
		int res = (2*(k-place)-1)*r;
		cout << res << "\n";
	}
}
