#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ll n; cin >> n;
	cout << (n+1)/2 * ((n % 2 == 1) ? -1 : 1) << "\n";
}
