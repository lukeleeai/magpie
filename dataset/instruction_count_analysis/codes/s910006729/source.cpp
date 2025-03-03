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

	int n, m;

	cin >> n >> m;

	vector <pair <ll, ll> > arr(n);

	for ( int i = 0; i < n; ++i ) {

		cin >> arr[i].first >> arr[i].second;

	}

	sort(arr.begin(), arr.end());

	int total = 0;

	ll taka = 0;

	for ( int i = 0; i < n; ++i ) {

		int temp = m - total;

		if ( arr[i].second <= temp ) {

			total += arr[i].second;

			taka += (arr[i].second * arr[i].first);

		} else if ( arr[i].second > temp ) {

			taka += ((m - total) * arr[i].first);

			total = m;

		}

		if ( total >= m ) break;

	}

	cout << taka << endl;

    return 0;

}
