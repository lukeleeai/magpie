#include "stdc++.h"

using namespace std;



int solve() {

	int n;

	cin >> n;

	cout << (n + 999) / 1000 * 1000 - n << '\n';

	return 0;

}



int main() {

	cin.tie(0)->sync_with_stdio(0);

	

	int t = 1;

	// cin >> t;

	while (t--) solve();

	return 0;

}