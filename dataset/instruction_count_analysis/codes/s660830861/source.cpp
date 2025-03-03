#include "stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define ll              long long

#define pb              push_back

#define ppb             pop_back

#define endl            '\n'

#define mii             map<ll,ll>

#define pii             pair<ll,ll>

#define vi              vector<ll>

#define vs              vector<string>

#define all(a)          (a).begin(),(a).end()

#define F               first

#define S               second

#define sz(x)           (ll)x.size()

#define hell            1000000007

#define inf             (ll)1e18 + 5

#define PI              (double)3.14159265358979323844

#define DECIMAL(n)      cout << fixed << setprecision(n);

#define rep(i,a,b)      for (ll i=a;i<b;i++)

#define repr(i,a,b)     for (ll i=a-1;i>=b;i--)

#define bitcount(a)     (ll)__builtin_popcount(a)

#define lbnd            lower_bound

#define ubnd            upper_bound

#define mp              make_pair

#define ios             ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ordered_set     tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

#define trace(...)      __f(#__VA_ARGS__, __VA_ARGS__)



template <typename Arg1>

void __f(const char* name, Arg1&& arg1){

    std::cerr << name << " : " << arg1 << endl;

}

template <typename Arg1, typename... Args>

void __f(const char* names, Arg1&& arg1, Args&&... args){

    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);

}



using namespace std;

using namespace __gnu_pbds;



/*----------------------Graph Moves----------------*/

//const int fx[]={+1,-1,+0,+0};

//const int fy[]={+0,+0,+1,-1};

//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move

//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move

//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move

//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

/*------------------------------------------------*/



//primes for hashing 937,991,1013,1409,1741



ll n;

const ll N=200005;

ll seg[4*N];

ll heights[N];

ll bs[N];

ll dp[N];

ll a[N];



ll query(ll cur,ll st,ll end,ll l,ll r) {

	if(l<=st&&r>=end)

	return seg[cur];

	if(r<st||l>end)

	return -inf;                           /*  2-change here  */

	ll mid=(st+end)>>1;

	ll ans1=query(2*cur,st,mid,l,r);

	ll ans2=query(2*cur+1,mid+1,end,l,r);

	return max(ans1,ans2);	                /*  3-change here  */

}



void update(ll cur,ll st,ll end,ll pos,ll upd) {

	if(st==end) {

		// dp[pos]=max(dp[pos],upd);					  4-change here  

		// seg[cur]=max(dp[pos],upd);					/*  5-change here  */

		a[pos]=upd;					/*  4-change here  */

		seg[cur]=upd;

		return;

	}

	ll mid=(st+end)>>1;

	if(st<=pos&&pos<=mid)

		update(2*cur,st,mid,pos,upd);

	else

		update(2*cur+1,mid+1,end,pos,upd);

	seg[cur]=max(seg[2*cur],seg[2*cur+1]);	/*  6-change here  */

}



void solve() {

    cin>>n;

    rep(i,0,n){

    	cin>>heights[i];

    }

  rep(i,0,n){

    	cin>>bs[i];

    }

    rep(i,0,n){

    	//trace(query(1,0,N,0,heights[i]-1));

    	//trace(heights[i]);

    	dp[i]=max(query(1,0,N,0,heights[i]-1),(ll)0)+bs[i];

    	//trace(dp[i]);

    	update(1,0,N,heights[i],dp[i]);

    }

    // rep(i,0,10){

    // 	cout<<dp[i]<<" "<<heights[i]<<"    ";

    // }

    // cout<<endl;

    cout<<*max_element(dp,dp+n)<<endl;

    memset(dp,0,sizeof dp);

    memset(seg,0,sizeof seg);

}



signed main() {

    ios

    ll test=1;

    //cin>>test;

    while (test--) solve();

    return 0;

}