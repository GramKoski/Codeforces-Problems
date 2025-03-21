#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		//There is a clever greedy approach to this problem. We know that if a minimum of x achievable with k removals it is also
		// achievable with k-1 removals. We will look for the max x that is possible with k removals. To do this we will suppose a
		// sum of x is possible. Perform the greedy algo which assumes this. If not possible in k removals we lower x if possible
		// we raise x. Proceed this way with binary search on x.
