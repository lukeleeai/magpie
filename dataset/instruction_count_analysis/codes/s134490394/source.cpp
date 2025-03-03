#include "stdc++.h"

#define _C ios::sync_with_stdio(false);cin.tie(0);

#define xx first

#define yy second

#define ERR 0.00000001

#define INF (ll)1<<62

#define nSize 1000000

#define forn for(int i = 0 ; i < n ; i++)

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pll;

typedef vector<ll> vll;

typedef vector<pll> vpll;

typedef complex<double> cp;

typedef vector<cp> polinomio;

typedef long double ld;

const ld PI = acos(-1);





int main()

{_C

	ll n , k;

	ll mx = INF;

	cin >> n >> k;

	vll v(n);

	forn

		cin >> v[i];

	sort(v.begin(),v.end());

	for(int i = k-1 ; i < n ; i++)

	{

		mx = min(v[i]-v[i-k+1],mx);

	}

	cout << mx << '\n';

	

	return 0;

}