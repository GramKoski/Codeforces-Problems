#include <iostream>
#include <unordered_set>

using namespace std;
unordered_set<long long unsigned> twins;
//Calculate all primes under a number n = 10^6
void sieve(int n) {
	bool is_not_prime[n+1];
	for (int i = 0; i <= n; ++i) {
		is_not_prime[i] = 0;
	}
	is_not_prime[0] = is_not_prime[1] = 1;
	for (int i = 2; i <= n;++i) {
		if (is_not_prime[i] == 0) {
			twins.insert((long long unsigned)i*(long long unsigned)i);
			for (int k = i*2;k <= n; k += i){
				is_not_prime[k] = 1;
			}
		}
	}
}

int main() {
	int n;
	long long unsigned m;
	cin >> n;	
	sieve(1e6);
	for (int i = 0; i < n; ++i) {
		cin >> m;
		if (twins.find(m) != twins.end()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}

