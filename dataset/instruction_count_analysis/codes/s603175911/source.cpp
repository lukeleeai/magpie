#include <vector>

#include <algorithm>

#include <set>

#include <map>

#include <queue>

#include <stack>

#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstring>

using namespace std;

typedef long long ll;

typedef pair<ll,ll> P;

typedef double db;



#define fr first

#define sc second

#define pb push_back

#define rep(i,x) for(ll i=0;i<x;i++)

#define rep1(i,x) for(ll i=1;i<=x;i++)

#define rrep(i,x) for(ll i=x-1;i>=0;i--)

#define rrep1(i,x) for(ll i=x;i>0;i--)



ll n,l;

ll a[100010];

ll dp[100010];

const ll INF = 0xfffffffff;



ll rec(ll x){

	if(dp[x]!=-1) return dp[x];

	ll res=l-a[x];

	ll lef=0,rig=0;

	

	auto ok=[](ll z){return 0<=z&&z<n;};

	

	if(ok(x-1)&&a[x-1]>a[x]) lef=rec(x-1);

	if(ok(x+1)&&a[x+1]>a[x]) rig=rec(x+1);

	

	return res+max(lef,rig);

}



int main()

{

	ll ans=0;

	cin>>n>>l;

	rep(i,n) cin>>a[i];

	memset(dp,-1,sizeof(dp));

	rep(i,n) ans=max(ans,rec(i));

	cout<<ans<<endl;

}