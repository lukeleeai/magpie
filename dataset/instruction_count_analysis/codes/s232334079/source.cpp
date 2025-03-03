#include "stdc++.h"

using namespace std;

typedef long long ll;



const int N = (int)1e5 + 10;

const double eps = 1e-8;



template <typename T> inline T gcd(T a, T b) { a = abs(a), b = abs(b); while ( b ) { a %= b; swap(a, b); } return a; }

vector <pair <int, int> > adj[N + 7];





int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	ll n, arr[10];

	ll mn = (ll)1e18;

	cin >> n;

	for ( int i = 0; i < 5; ++i ) {

		cin >> arr[i];

		mn = min(arr[i], mn);

	}

	ll ans = 4 + ceil(n*1.0 / mn*1.0);

	cout << ans << endl;

    return 0;

}
