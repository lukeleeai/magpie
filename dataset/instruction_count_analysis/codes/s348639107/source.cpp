#include "stdc++.h"

using namespace std;



#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define mt make_tuple

#define eb emplace_back

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)



#define LB(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())

#define UB(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

typedef long long ll;

typedef pair<ll,ll> ii;

typedef vector<int> vi;

typedef vector<ll> vl;

typedef unsigned long long ull;

typedef long double ld; 

typedef tuple<int,int,int> State;



ll mod = 1e9 + 7;



#define citc(tc) int tc; cin>>tc; while(tc--){solve();}

#define each(a,x) for( auto &a:(x))

#define rep(i, n) for (ll i = 0; i < (n); i++)

#define repr(i, n) for (ll i = (n) - 1; i >= 0; i--)

#define rep2(i, l, r) for (ll i = (l); i < (r); i++)

#define rep2r(i, l, r) for (ll i = (r) - 1; i >= (l); i--)

#define range(a) a.begin(), a.end()

#define deb(x) cout<<#x<<" "<<x<<endl;

#define cini(i) int i; cin>>i;

#define cinll(l) ll l; cin>>l;

#define cinai(a, n) vi a(n); rep(i, n) { cin>>a[i]; }

#define cinal(a, n) vl a(n); rep(i, n) { cin>>a[i]; }

#define coutai(a, n) rep(i, n) { cout<<a[i]<<" "; } ent;

#define coutal(a, n) rep(i, n) { cout<<a[i]<<" "; } ent;

#define ent cout<<endl;



void solve()

{

	ll a, b;

	cin>>a>>b;

	if(a == b)

		cout<<"Yes\n";

	else

		cout<<"No\n";

}

int main()

{

	fastio();

	// citc(tc);

	solve();

}