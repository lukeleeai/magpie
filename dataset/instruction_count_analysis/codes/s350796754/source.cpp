#include "stdc++.h"

using namespace std;



using ll = long long;



#define REP(i, n) for (int i = 0; i < (n); ++i)

#define SIZE(a) ((int)(a).size())



const int N = 100005;

const ll linf = 2e18;



int n, a[N];



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);



	cin >> n;

	REP(i, n) cin >> a[i];

	reverse(a, a + n);

	ll l, r;

	l = r = 2;

	REP(i, n) {

		ll nl = l % a[i] ? l + a[i] - l % a[i] : l;

		ll nr = r - r % a[i] + a[i] - 1;

		if (nl > nr) {

			cout << -1 << '\n';

			return 0;

		}

		l = nl;

		r = nr;

	}



	cout << l << ' ' << r << '\n';



	return 0;

}