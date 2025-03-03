#include "stdc++.h"

 

#define ll long long int

#define pb push_back

#define mp make_pair

#define ff first

#define ss second

#define lim 200005

#define mod 1000000007

#define nfs_mw ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;



bool Q;

struct Line {

	mutable ll k, m, p;

	bool operator<(const Line& o) const {

		return Q ? p < o.p : k < o.k;

	}

};



//Line equation is k*x + m

//works for maximum, negate values for minimum

struct LineContainer : multiset<Line> {

	// (for doubles, use inf = 1/.0, div(a,b) = a/b)

	const ll inf = LLONG_MAX;

	ll div(ll a, ll b) { // floored division

		return a / b - ((a ^ b) < 0 && a % b); }

	bool isect(iterator x, iterator y) {

		if (y == end()) { x->p = inf; return false; }

		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;

		else x->p = div(y->m - x->m, x->k - y->k);

		return x->p >= y->p;

	}

	void add(ll k, ll m) {

		auto z = insert({k, m, 0}), y = z++, x = y;

		while (isect(y, z)) z = erase(z);

		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));

		while ((y = x) != begin() && (--x)->p >= y->p)

			isect(x, erase(y));

	}

	ll query(ll x) {

		assert(!empty());

		Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;

		return l.k * x + l.m;

	}

	void min_add(ll k, ll m) {

		add(-k, -m);

	}

	ll min_query(ll x) {

		return -query(x);

	}

};







int main()

{

    nfs_mw;

    int i,j,n; ll c, h, dp[lim] = {};

    cin>>n>>c;

    LineContainer idk;

    dp[0] = 0; cin>>h;

    idk.min_add(-2*h, dp[0] + h*h + c);

    for(i=1; i<n; i++){

    	cin>>h;

    	dp[i] = idk.min_query(h) + h*h;

    	idk.min_add(-2*h, dp[i] + h*h + c);

    }

    cout<<dp[n-1];

}